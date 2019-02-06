#ifndef DESKR_WINSOCKHANDLER
#define DESKR_WINSOCKHANDLER

#include <stdint.h>
#include "../abstracts/SocketHandler.h"

class WinSocketHandler: public SocketHandler {
    public:
        WinSocketHandler(uint16_t port);
        int startListening();
};

#endif