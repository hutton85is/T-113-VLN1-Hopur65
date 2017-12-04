#ifndef CLIENT_H
#define CLIENT_H

#include "Pizza.h"

class client
{
    public:
        client();
        virtual ~client();

        char name[64];
        char address[32];
        int addressNumber;

    private:
        Pizza lager;
        Pizza order;
};

#endif // CLIENT_H
