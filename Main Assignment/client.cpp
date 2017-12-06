#include "client.h"

client::client()
{
    name[0] = '\0';
    address[0] = '\0';
    addressNumber =  0;
}

client::client(char nam[64], char addres[32], int number)
{
    name = nam;
    address = addres;
    addressNumber = number;
}

client::~client()
{
    //dtor
}

ostream& operator <<(ostream& outs, client& addressInfo)
{
    outs << addressInfo.name << " : ";
    outs << addressInfo.address << " : ";
    outs << addressInfo.addressNumber << " : ";
    return outs;
}
