#ifndef CLIENT_H
#define CLIENT_H

#include "Pizza.h"

class client
{
    public:
        client();
        client(char name[], char address[], int number);
        virtual ~client();

        Pizza order;
        char name[64];
        char address[32];
        int addressNumber;

    private:
};

#endif // CLIENT_H
