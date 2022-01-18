#include "SessionSignItem.h"
#include "Constants.h"

namespace comm {
namespace network {
namespace database {

std::string SessionSignItem::tableName = DEVICE_SESSIONS_SIGN_TABLE_NAME;
const std::string SessionSignItem::FIELD_SESSION_SIGN = "Sign";
const std::string SessionSignItem::FIELD_DEVICE_ID = "DeviceId";
const std::string SessionSignItem::FIELD_TTL = "TTL";

SessionSignItem::SessionSignItem(
    const std::string sign,
    const std::string deviceId)
    : sign(sign), deviceId(deviceId) {
  this->validate();
}

SessionSignItem::SessionSignItem(const AttributeValues &itemFromDB) {
  this->assignItemFromDatabase(itemFromDB);
}

void SessionSignItem::validate() const {
  if (!this->sign.size()) {
    throw std::runtime_error("Error: Sign is empty.");
  }
}

void SessionSignItem::assignItemFromDatabase(
    const AttributeValues &itemFromDB) {
  try {
    this->sign = itemFromDB.at(SessionSignItem::FIELD_SESSION_SIGN).GetS();
    this->deviceId = itemFromDB.at(SessionSignItem::FIELD_DEVICE_ID).GetS();
  } catch (const std::exception &e) {
    throw std::runtime_error(
        "Got an exception at SessionSignItem: " + std::string(e.what()));
  }
  this->validate();
}

std::string SessionSignItem::getTableName() const {
  return SessionSignItem::tableName;
}

std::string SessionSignItem::getPrimaryKey() const {
  return SessionSignItem::FIELD_DEVICE_ID;
}

std::string SessionSignItem::getSign() const {
  return this->sign;
}

std::string SessionSignItem::getDeviceId() const {
  return this->deviceId;
}

} // namespace database
} // namespace network
} // namespace comm