#include "salaryRecord.h"

salaryRecord::salaryRecord()
{
    salary = 0;
    month = 1;
    year = 1990;
}

salaryRecord::~salaryRecord()
{
    //dtor
}


int salaryRecord::get_salary(){

    return this->salary;
}

int salaryRecord::get_month(){

    return this->month;
}

int salaryRecord::get_year(){

    return this->year;
}

ostream& operator << (ostream& out, salaryRecord& record){

    out  << record.salary << ", " << record.month << ", " << record.year << endl;

    return out;
}



