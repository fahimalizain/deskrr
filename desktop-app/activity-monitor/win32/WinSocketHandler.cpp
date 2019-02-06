#include <stdint.h>
#include "../abstracts/SocketHandler.h"

class WinSocketHandler: public SocketHandler {
    public:
        WinSocketHandler(uint16_t port): SocketHandler(port) {

        }
        
        int startListening();
};

int WinSocketHandler::startListening() {
    return 0;
}