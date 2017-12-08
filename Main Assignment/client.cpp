#include "client.h"

client::client()
{
    name[0] = '\0';
    address[0] = '\0';
    addressNumber =  0;

    orderCounter = 0;
    currentPizza = 0;

    inProgress = false;
    finished = false;
    orderDelivered = false;
    orderPaid = false;
}

client::~client()
{
    //dtor
}

ostream& operator <<(ostream& outs, client& customer)
{
    outs << customer.name << endl;
    outs << customer.address << " " << customer.addressNumber;
    return outs;
}
