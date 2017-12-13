#include "InputErrorException.h"

InputErrorException::InputErrorException()
{
    now = time(0);
}

InputErrorException::~InputErrorException()
{

}

time_t InputErrorException::getTime()
{
    return now;
}

InputErrorException::InputErrorException(string message)
{
    now = time(0);

    strcpy(this->message, message.c_str());
    this->message[message.length()];

    InputErrorException er;
    readWriteClass rw;
    rw.writeClassToFile(er,"Exceptions/InputErrorException.dat");
}

string InputErrorException::getMessage()
{
    return message;
}

ostream& operator <<(ostream& outs, InputErrorException& i)
{
    time_t temp = i.getTime();
    char* dt = ctime(&temp);
    outs << i.getMessage() << " : " << dt << endl;

    return outs;
}
