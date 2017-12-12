#include "client.h"

client::client()
{
    name[0] = '\0';
    address[0] = '\0';
    addressNumber =  0;

    orderCounter = 0;
    currentPizza = 0;

    sumOfOrder = 0;

    orderPaid = false;
    inProgress = false;
    finished = false;
    orderDelivered = false;
    deliverOrder = false;
}

client::~client()
{
    //dtor
}

ostream& operator <<(ostream& outs, client& customer)
{
    outs << customer.name << ", " << customer.address << " " << customer.addressNumber << endl;
    outs << "Buid ad borga: ";
    if (customer.orderPaid)
    {
        outs << "ja";
    }
    else
    {
        outs << "nei";
    }
    outs << endl;
    outs << "verid ad baka pizzu: ";
    if (customer.inProgress)
    {
        outs << "ja";
    }
    else
    {
        outs << "nei";
    }
    outs << endl;
    outs << "buid ad baka pizzu: ";
    if (customer.finished)
    {
        outs << "ja";
    }
    else
    {
        outs << "nei";
    }
    outs << endl;
    outs << "heimsending: ";
    if(customer.deliverOrder)
    {
        outs << "ja";
    }
    else
    {
        outs << "nei";
    }
    outs << endl;
    outs << "buid ad afhenda pizzu: ";
    if (customer.orderDelivered)
    {
        outs << "ja";
    }
    else
    {
        outs << "nei";
    }
    cout << endl;
    outs << "Heildarverd: " << customer.sumOfOrder << " kr.";
    return outs;
}
