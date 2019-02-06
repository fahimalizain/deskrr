#include <stdint.h>

class SocketHandler {
    private:
        uint16_t currentPort;
    public:
        SocketHandler(uint16_t);

        /**
         * Starts listening on the port provided
        */
        int startListening();
};

SocketHandler::SocketHandler(uint16_t port) {
    currentPort = port;
}

int SocketHandler::startListening() {
    
}