/**
* @brief An exception class for wrong input insert
*
*/

#ifndef INPUTERROREXCEPTION_H
#define INPUTERROREXCEPTION_H

#include <string.h>
#include <iostream>
#include <ctime>
#include <ostream>
#include <fstream>

#include "ReadWriteClass.h"

using namespace std;

class InputErrorException
{
    public:

        InputErrorException();

        InputErrorException(string message);

        string getMessage();

        friend ostream& operator << (ostream& outs, InputErrorException& i);

        time_t getTime();

    private:

        char message[64];

        time_t now;
};

#endif // INPUTERROREXCEPTION_H
