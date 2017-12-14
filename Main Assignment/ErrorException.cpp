#include "ErrorException.h"

ErrorException::ErrorException()
{
    InputErrorException newInputErrorException;
    ReadWriteClass rw;
    rw.loadSpecificVector(inputErrorExceptionVec, "Exceptions/InputErrorException.dat", newInputErrorException);
}

vector <InputErrorException> ErrorException::getInputErrorExceptionVec()
{
    return inputErrorExceptionVec;
}


void ErrorException::logInputErrorException(InputErrorException newException)
{
    const char* fname = "Exceptions/InputErrorException.dat";
    ReadWriteClass rw;
    rw.writeClassToFile(newException, fname);
}

ostream& operator << (ostream& outs, ErrorException& er)
{
    outs << "1. Innslattarvilla, error exception er: " <<  er.getInputErrorExceptionVec().size() << endl;

    return outs;
}
