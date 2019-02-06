#include <stdint.h>
#include "../abstracts/SocketHandler.h"
#include "WinSocketHandler.h"

WinSocketHandler::WinSocketHandler(uint16_t port): SocketHandler(port) { }