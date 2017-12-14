/**
* @brief Functional class for ErrorUI and logging exceptions
*
*/


#ifndef ERROREXCEPTION_H
#define ERROREXCEPTION_H

#include <vector>
#include "InputErrorException.h"
#include "ErrorExceptionUI.h"


class ErrorException
{
    public:

        /**
        * @brief Load exception into vector from file
        *
        */
        ErrorException();

        vector <InputErrorException> getInputErrorExceptionVec();

        void logInputErrorException(InputErrorException newException);

        friend ostream& operator << (ostream& outs, ErrorException& er);

    private:

        vector <InputErrorException> inputErrorExceptionVec;
};

#endif // ERROREXCEPTION_H
