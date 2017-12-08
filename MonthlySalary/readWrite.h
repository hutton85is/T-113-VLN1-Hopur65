#ifndef READWRITE_H
#define READWRITE_H

#include "employee.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include "salaryRecord.h"

using namespace std;


class readWrite
{
    public:
        readWrite();
        virtual ~readWrite();
        void writeEmployee(employee newEmployee);
        void readEmployee(const char* name, employee &newEmployee, vector <salaryRecord> srvec);
        void readList(vector <employee> &listOfNames);
        void highestSalary(int year);
        void writeSsnRecord(salaryRecord newSalary, char name[40]);

    private:
};

#endif // READWRITE_H
