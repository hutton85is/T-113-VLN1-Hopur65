#ifndef CLIENT_H
#define CLIENT_H

#include "Pizza.h"
#include "PizzaHelper.h"

class client
{
    public:
        client();
        virtual ~client();

        char name[64];
        char address[32];
        int addressNumber;

        // A counter to know which pizza is currently being edited
        unsigned int currentPizza;

        // store how many pizzas there are on an order
        unsigned int orderCounter;

        friend ostream& operator <<(ostream& outs, client& customer);
};

#endif // CLIENT_H
