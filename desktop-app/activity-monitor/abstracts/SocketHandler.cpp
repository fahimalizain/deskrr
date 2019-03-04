#include <stdint.h>
#include "SocketHandler.h"

SocketHandler::SocketHandler(uint16_t _port) {
    port = _port;
}

int SocketHandler::startListening() {
    return 0;
}