#ifndef CLIENT_H
#define CLIENT_H

#include "Pizza.h"

class client
{
    public:
        client();
        virtual ~client();

        Pizza order;
        char name[64];
        char address[32];
        int addressNumber;

        unsigned int orderCounter;
        unsigned int crustCounter;
        unsigned int toppingsCounter;
        unsigned int extrasCounter;
        unsigned int menuCounter;
        unsigned int locationCounter;
        unsigned int sizeCounter;
};

#endif // CLIENT_H
