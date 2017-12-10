#include "employee.h"

employee::employee()
{
    recordCounter = 0;
}

employee::~employee()
{
    //dtor
}

ostream& operator << (ostream& out, employee& emp){

    out << emp.name << " : " << emp.ssn;

    return out;
}
