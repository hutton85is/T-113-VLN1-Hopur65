#include "MissingLocationException.h"

MissingLocationException::MissingLocationException(string message)
{
    this->message = message;
}

MissingLocationException::~MissingLocationException()
{

}

string MissingLocationException::getMessage()
{
    return message;
}
