#include "Error.h"

Error::Error()
{
    InputErrorException newInputErrorException;
    ReadWriteClass rw;
    rw.loadSpecificVector(inputErrorExceptionVec, "Exceptions/InputErrorException.dat", newInputErrorException);
}

vector <InputErrorException> Error::getInputErrorExceptionVec()
{
    return inputErrorExceptionVec;
}


void Error::logInputErrorException(InputErrorException newException)
{
    const char* fname = "Exceptions/InputErrorException.dat";
    ReadWriteClass rw;
    rw.writeClassToFile(newException, fname);
}

ostream& operator << (ostream& outs, Error& er)
{
    outs << "1. Innslattarvilla, error exception er: " <<  er.getInputErrorExceptionVec().size() << endl;

    return outs;
}


