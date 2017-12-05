#include "client.h"

client::client()
{
    name[0] = '\0';
    address[0] = '\0';
    addressNumber =  0;
}

client::client(const char name[64], const char address[32], int number)
{
    //this->name = name;
//    this->address = address;
    addressNumber = number;
}

client::~client()
{
    //dtor
}
