#ifndef SOCKETBASE_H
#define SOCKETBASE_H

#include <stdint.h>

class SocketHandler {
    private:
        uint16_t port;
    public:
        SocketHandler(int);
        int startListening();
};

#endif
