#ifndef MISSINGLOCATIONEXCEPTION_H
#define MISSINGLOCATIONEXCEPTION_H

#include <iostream>

using namespace std;

class MissingLocationException
{
    public:
        MissingLocationException(string message);
        virtual ~MissingLocationException();
        string getMessage();

    private:
        string message;
};

#endif // MISSINGLOCATIONEXCEPTION_H
