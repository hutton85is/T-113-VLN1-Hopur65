#ifndef ERROR_H
#define ERROR_H

#include <vector>
#include "InputErrorException.h"
#include "ErrorUI.h"

using namespace std;


class Error
{
    public:
        Error();
        virtual ~Error();
        void displayError();
        vector <InputErrorException> getInputErrorExceptionVec();

        friend ostream& operator << (ostream& outs, Error& er);

    private:
        vector <InputErrorException> inputErrorExceptionVec;
};

#endif // ERROR_H
