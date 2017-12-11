#include "Error.h"

Error::Error()
{
    InputErrorException newInputErrorException;
    readWriteClass rw;
    rw.loadSpecificVector(inputErrorExceptionVec, "Exceptions/InputErrorException.dat", newInputErrorException);
}

Error::~Error()
{
    //dtor
}

vector <InputErrorException> Error::getInputErrorExceptionVec(){

    return inputErrorExceptionVec;

}

ostream& operator << (ostream& outs, Error& er){

    outs << "Invalid error exception is " <<  er.getInputErrorExceptionVec().size() << endl;

    return outs;

}


