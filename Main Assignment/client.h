/**
* @brief All information about customer
*
* A class to store customer information, and how many orders there are for a particular customer
*/

#ifndef CLIENT_H
#define CLIENT_H

#include "Pizza.h"
#include "PizzaHelper.h"

class Client
{
    public:

        Client();

        char name[64];

        char address[32];

        int addressNumber;

        char comment[128];

        bool inProgress;

        bool finished;

        bool orderPaid;

        bool orderDelivered;

        bool deliverOrder;

        int sumOfOrder;

        unsigned int orderCounter;

        friend ostream& operator <<(ostream& outs, Client& customer);
};

#endif // CLIENT_H
