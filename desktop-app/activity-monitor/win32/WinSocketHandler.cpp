#include <iostream>
#include <stdint.h>
#include "../abstracts/SocketHandler.h"
#include "WinSocketHandler.h"

WinSocketHandler::WinSocketHandler(uint16_t port): SocketHandler(port) {
  std::cout << "Constructed WinSocket Handler" << std::endl;
}
int WinSocketHandler::startListening() {
  std::cout << "started listening" << std::endl;
}