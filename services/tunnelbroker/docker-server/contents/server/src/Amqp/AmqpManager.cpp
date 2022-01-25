#include "AmqpManager.h"
#include "Constants.h"
#include "DeliveryBroker.h"
#include "Tools.h"

#include <boost/asio/io_service.hpp>

namespace comm {
namespace network {

void AMQPConnectInternal() {
  config.loadConfig();
  std::cout << "AMQP: Connecting to " << config.amqpURI << std::endl;

  // Make a connection and channel
  boost::asio::io_service BoostIOservice(AMQP_CLIENT_THREADS);
  AMQP::LibBoostAsioHandler AMQPhandler(BoostIOservice);
  AMQP::TcpConnection connection(&AMQPhandler, AMQP::Address(config.amqpURI));
  AmqpChannel = std::make_unique<AMQP::TcpChannel>(&connection);

  AmqpChannel->onError([&connection](const char *message) {
    std::cout << "channel error: " << message << ", will try to reconnect"
              << std::endl;
    AmqpReady = false;
  });

  // Create a queue for the current tunnelbroker instance by it's ID
  AMQP::Table arguments;
  arguments["x-message-ttl"] = AMQP_MESSAGE_TTL;
  arguments["x-expires"] = AMQP_QUEUE_TTL;
  AmqpChannel->declareQueue(config.tunnelbrokerID, AMQP::durable, arguments)
      .onSuccess([&connection](
                     const std::string &name,
                     uint32_t messagecount,
                     uint32_t consumercount) {
        std::cout << "AMQP: Queue " << name << " created" << std::endl;
        AmqpReady = true;
        AmqpChannel->consume(config.tunnelbrokerID)
            .onReceived([&](const AMQP::Message &message,
                            uint64_t deliveryTag,
                            bool redelivered) {
              try {
                AMQP::Table headers = message.headers();
                const std::string payload(message.body());
                const std::string toDeviceID(headers[AMQP_HEADER_TO_DEVICEID]);
                const std::string fromDeviceID(
                    headers[AMQP_HEADER_FROM_DEVICEID]);
                std::cout << "AMQP: Message consumed for deviceId: "
                          << toDeviceID << std::endl;
                DeliveryBrokerPush(toDeviceID, fromDeviceID, payload);
              } catch (const std::exception &e) {
                std::cout << "AMQP: Message parsing exception: " << e.what()
                          << std::endl;
              }
              AmqpChannel->ack(deliveryTag);
            })
            .onError([](const char *message) {
              std::cout << "AMQP: Error on message consume:  " << message
                        << std::endl;
            });
      })
      .onError([&](const char *message) {
        throw std::runtime_error(
            "AMQP: Queue creation error: " + std::string(message));
      });
  BoostIOservice.run();
}

void AMQPConnect() {
  while (true) {
    long long currentTimestamp = getCurrentTimestamp();
    if (lastConnectionTimestamp &&
        currentTimestamp - lastConnectionTimestamp <
            AMQP_SHORTEST_RECONNECTION_ATTEMPT_INTERVAL) {
      throw std::runtime_error(
          "AMQP reconnection attempt interval too short, tried to reconnect "
          "after " +
          std::to_string(currentTimestamp - lastConnectionTimestamp) +
          "ms, the shortest allowed interval is " +
          std::to_string(AMQP_SHORTEST_RECONNECTION_ATTEMPT_INTERVAL) + "ms");
    }
    lastConnectionTimestamp = currentTimestamp;
    AMQPConnect();
  }
}

bool AMQPSend(
    std::string toDeviceID,
    std::string fromDeviceID,
    std::string payload) {
  if (!AmqpReady) {
    std::cout << "AMQP: Message send error: channel not ready." << std::endl;
    return false;
  }
  try {
    AMQP::Envelope env(payload.c_str(), payload.size());
    AMQP::Table headers;
    headers[AMQP_HEADER_FROM_DEVICEID] = fromDeviceID;
    headers[AMQP_HEADER_TO_DEVICEID] = toDeviceID;
    // Set delivery mode to durable
    env.setDeliveryMode(2);
    env.setHeaders(std::move(headers));
    AmqpChannel->publish("", config.tunnelbrokerID, env);
  } catch (std::runtime_error &e) {
    std::cout << "AMQP: Error while publishing message:  " << e.what()
              << std::endl;
    return false;
  }
  return true;
}

} // namespace network
} // namespace comm
