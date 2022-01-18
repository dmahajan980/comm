#include "TunnelbrokerServiceImpl.h"

#include "AmqpManager.h"
#include "AwsTools.h"
#include "Constants.h"
#include "CryptoTools.h"
#include "DatabaseManager.h"
#include "DeliveryBroker.h"
#include "Tools.h"

#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace comm {
namespace network {

using namespace std::chrono_literals;

TunnelBrokerServiceImpl::TunnelBrokerServiceImpl() {
  Aws::InitAPI({});
  // List of AWS DynamoDB tables to check if they are created and can be
  // accessed before the AWS API methods run
  const std::list<std::string> tablesList = {
      DEVICE_SESSIONS_TABLE_NAME, DEVICE_SESSIONS_SIGN_TABLE_NAME};
  for (const std::string &table : tablesList) {
    if (!database::DatabaseManager::getInstance().isTableAvailable(table)) {
      throw std::runtime_error(
          "Error: AWS DynamoDB table '" + table + "' is not available.");
    }
  };
}

TunnelBrokerServiceImpl::~TunnelBrokerServiceImpl() {
  Aws::ShutdownAPI({});
}

grpc::Status TunnelBrokerServiceImpl::SessionSignature(
    grpc::ServerContext *context,
    const tunnelbroker::SessionSignatureRequest *request,
    tunnelbroker::SessionSignatureResponse *reply) {
  const std::string toSign = generateRandomString(SIGNATURE_REQUEST_LENGTH);
  std::shared_ptr<database::SessionSignItem> SessionSignItem =
      std::make_shared<database::SessionSignItem>(toSign, request->deviceid());
  database::DatabaseManager::getInstance().putSessionSignItem(*SessionSignItem);
  reply->set_tosign(toSign);
  return grpc::Status::OK;
}

grpc::Status TunnelBrokerServiceImpl::NewSession(
    grpc::ServerContext *context,
    const tunnelbroker::NewSessionRequest *request,
    tunnelbroker::NewSessionResponse *reply) {

  std::shared_ptr<database::DeviceSessionItem> deviceSessionItem;
  std::shared_ptr<database::SessionSignItem> sessionSignItem;
  const std::string deviceId = request->deviceid();
  const std::string signature = request->signature();
  const std::string publicKey = request->publickey();
  const boost::uuids::uuid uuid = boost::uuids::random_generator()();
  const std::string newSessionId = boost::lexical_cast<std::string>(uuid);
  try {

    // Check for possible random generated sessionId collision
    // with already used sessions ids
    deviceSessionItem =
        database::DatabaseManager::getInstance().findSessionItem(newSessionId);
    if (deviceSessionItem != nullptr) {
      std::cout << "gRPC: "
                << "Session unique id " << newSessionId << " already used."
                << std::endl;
      return grpc::Status(
          grpc::StatusCode::INTERNAL, "Session unique id already used.");
    }

    // Check if signature doesn't match the deviceId from the
    // previous `SessionSignature` request.
    sessionSignItem =
        database::DatabaseManager::getInstance().findSessionSignItem(deviceId);
    if (sessionSignItem == nullptr) {
      std::cout << "gRPC: "
                << "Session sign request not found for deviceId: " << deviceId
                << std::endl;
      return grpc::Status(
          grpc::StatusCode::NOT_FOUND, "Session sign request not found. ");
    }
    const std::string toSign = sessionSignItem->getSign();
    database::DatabaseManager::getInstance().removeSessionSignItem(deviceId);

    deviceSessionItem = std::make_shared<database::DeviceSessionItem>(
        newSessionId,
        deviceId,
        request->publickey(),
        request->notifytoken(),
        tunnelbroker::NewSessionRequest_DeviceTypes_Name(request->devicetype()),
        request->deviceappversion(),
        request->deviceos());
    database::DatabaseManager::getInstance().putSessionItem(*deviceSessionItem);
  } catch (std::runtime_error &e) {
    std::cout << "gRPC: "
              << "Error while processing NewSession request: " << e.what()
              << std::endl;
    return grpc::Status(grpc::StatusCode::INTERNAL, e.what());
  }
  reply->set_sessionid(newSessionId);
  return grpc::Status::OK;
}

grpc::Status TunnelBrokerServiceImpl::Send(
    grpc::ServerContext *context,
    const tunnelbroker::SendRequest *request,
    google::protobuf::Empty *reply) {

  try {
    const std::string sessionId = request->sessionid();
    // Check if the sessionId from request exists in DB
    // or return PERMISSION_DENIED.
    std::shared_ptr<database::DeviceSessionItem> sessionItem =
        database::DatabaseManager::getInstance().findSessionItem(sessionId);
    if (sessionItem == nullptr) {
      std::cout << "gRPC: "
                << "Session " << sessionId << " not found." << std::endl;
      return grpc::Status(
          grpc::StatusCode::PERMISSION_DENIED,
          "No such session found. SessionId: " + sessionId);
    }
    const std::string clientDeviceId = sessionItem->getDeviceId();
    if (!AMQPSend(
            request->todeviceid(),
            clientDeviceId,
            std::string(request->payload()))) {
      std::cout << "gRPC: "
                << "Error while publish the message to AMQP" << std::endl;
      return grpc::Status(
          grpc::StatusCode::INTERNAL,
          "Error while publish the message to AMQP");
    }
  } catch (std::runtime_error &e) {
    std::cout << "gRPC: "
              << "Error while processing Send request: " << e.what()
              << std::endl;
    return grpc::Status(grpc::StatusCode::INTERNAL, e.what());
  }
  return grpc::Status::OK;
}

grpc::Status TunnelBrokerServiceImpl::Get(
    grpc::ServerContext *context,
    const tunnelbroker::GetRequest *request,
    grpc::ServerWriter<tunnelbroker::GetResponse> *writer) {

  try {
    const std::string sessionId = request->sessionid();
    // Check if the sessionId from request exists in DB
    // or return PERMISSION_DENIED.
    std::shared_ptr<database::DeviceSessionItem> sessionItem =
        database::DatabaseManager::getInstance().findSessionItem(sessionId);
    if (sessionItem == nullptr) {
      std::cout << "gRPC: "
                << "Session " << sessionId << " not found." << std::endl;
      return grpc::Status(
          grpc::StatusCode::PERMISSION_DENIED,
          "No such session found. SessionId: " + sessionId);
    }
    const std::string clientDeviceId = sessionItem->getDeviceId();
    // Check if the DeliveryBroker queue is not empty for the deviceID and
    // deliver the messages by the gRPC stream message responses if not
    std::vector<DeliveryBrokerMessageStruct> messagesToDeliver;
    while (1) {
      if (DeliveryBrokerIsEmpty(clientDeviceId)) {
        continue;
      }
      messagesToDeliver = DeliveryBrokerGet(clientDeviceId);
      for (auto const &message : messagesToDeliver) {
        tunnelbroker::GetResponse response;
        response.set_fromdeviceid(message.fromDeviceID);
        response.set_payload(message.payload);
        if (!writer->Write(response)) {
          throw std::runtime_error(
              "gRPC: Get handler writer error on sending data.");
        }
      }
      // Remove messages from the queue only after gRPC writer
      DeliveryBrokerRemove(clientDeviceId);
    }
    return grpc::Status::OK;
  } catch (std::runtime_error &e) {
    std::cout << "gRPC: "
              << "Error while processing Get request: " << e.what()
              << std::endl;
    return grpc::Status(grpc::StatusCode::INTERNAL, e.what());
  }
  return grpc::Status::OK;
}

} // namespace network
} // namespace comm