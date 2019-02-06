#ifndef DESKR_SOCKETBASE_H
#define DESKR_SOCKETBASE_H

#include <stdint.h>

class SocketHandler {
    private:
        uint16_t port;
    public:
        SocketHandler(uint16_t);
        int startListening();
};

#endif
