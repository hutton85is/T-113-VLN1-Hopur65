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

        // status for Baker class, tells if pizza is being baked
        bool inProgress;
        // status for Afhending and Baker class, tells if pizza is ready to be delivered
        bool finished;
        // status for Afhending class, tells if order has been paid
        bool orderPaid;
        // status for Afhending class, tells if order has been delivered
        bool orderDelivered;

        // A counter to know which pizza is currently being edited
        unsigned int currentPizza;

        // store how many pizzas there are on an order
        unsigned int orderCounter;

        friend ostream& operator <<(ostream& outs, client& customer);
};

#endif // CLIENT_H
