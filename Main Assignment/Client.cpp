#include "Client.h"

Client::Client()
{
    name[0] = '\0';
    address[0] = '\0';
    addressNumber =  0;
    comment[0] = '\0';

    orderCounter = 0;

    sumOfOrder = 0;

    orderPaid = false;
    inProgress = false;
    finished = false;
    orderDelivered = false;
    deliverOrder = false;
}

ostream& operator <<(ostream& outs, Client& customer)
{
    if(customer.name[0] != '\0')
    {
        outs << "    " << customer.name << ", " << customer.address << " " << customer.addressNumber << endl;
    }

    outs << "    " << "heimsending: ";

    if(customer.deliverOrder)
    {
        outs << "ja";
    }
    else
    {
        outs << "nei";
    }
    outs << endl;

    outs << "    " << "Athugasemd: " << customer.comment << endl;

    outs << "    " << "Heildarverd: " << customer.sumOfOrder << " kr.";

    return outs;
}
