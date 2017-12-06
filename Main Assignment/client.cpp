#include "client.h"

client::client()
{
    name[0] = '\0';
    address[0] = '\0';
    addressNumber =  0;

    orderCounter = 0;
    toppingsCounter = 0;
    extrasCounter = 0;
    menuCounter = 0;
    locationCounter = 0;
    sizeCounter = 0;
    crustCounter = 0;
}

client::~client()
{
    //dtor
}

ostream& operator <<(ostream& outs, client& addressInfo)
{
    outs << addressInfo.name << endl;
    outs << addressInfo.address << " " << addressInfo.addressNumber;
    return outs;
}
