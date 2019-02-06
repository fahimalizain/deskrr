#ifndef _WINSOCKHANDLER
#define _WINSOCKHANDLER

#include <stdint.h>
#include "../abstracts/SocketHandler.h"

class WinSockHandler: public SocketHandler {
    public:
        WinSockHandler(uint16_t port);
        int startListening();
};

#endif