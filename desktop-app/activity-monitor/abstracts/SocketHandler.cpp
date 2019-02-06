#include <stdint.h>
#include "SocketHandler.h"

SocketHandler::SocketHandler(uint16_t port) {
    this->port = port;
}

int SocketHandler::startListening() {
    return 0;
}