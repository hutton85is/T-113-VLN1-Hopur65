#include "Error.h"

Error::Error()
{
    InputErrorException newInputErrorException;
    readWriteClass rw;
    rw.loadSpecificVector(inputErrorExceptionVec, "Exceptions/InputErrorException.dat", newInputErrorException);
}

vector <InputErrorException> Error::getInputErrorExceptionVec()
{
    return inputErrorExceptionVec;
}


void Error::logInputErrorException(InputErrorException newException, const char* fname)
{
    readWriteClass rw;
    rw.writeClassToFile(newException, fname);
}

ostream& operator << (ostream& outs, Error& er)
{
    outs << "Invalid input error exception count is: " <<  er.getInputErrorExceptionVec().size() << endl;

    return outs;
}


