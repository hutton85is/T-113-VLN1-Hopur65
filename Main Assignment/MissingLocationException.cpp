#include "MissingLocationException.h"

MissingLocationException::MissingLocationException(string message)
{
    this->message = message;
}

MissingLocationException::~MissingLocationException()
{
    //dtor
}

string MissingLocationException::getMessage()
{
    return message;
}
