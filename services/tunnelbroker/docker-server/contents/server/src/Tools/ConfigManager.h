#pragma once

#include <string>

struct TunnelbrokerConfig {
  // Tunnelbroker server identification
  const char *tunnelbrokerID;

  // AWS
  const char *deviceSessionsTableName;

  // gRPC Server
  const char *serverListenAddress;

  // AMQP (RabbitMQ)
  const char *amqpURI;
  size_t amqpMessageTTL;

  void loadConfig();
};
