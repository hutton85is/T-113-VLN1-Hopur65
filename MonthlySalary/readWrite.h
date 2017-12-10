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
        // create new employee with salary record
        void writeEmployeeRecord(employee newEmployee, salaryRecord newSalary);
        // add salary record to existing employee
        void writeEmployeeRecord(char ssn[10], salaryRecord newSalary);
        // Read list of employees registered into a vector
        void readList(vector <employee> &listOfNames);
        // Read salary records for a given SSN
        void readSalaryRecords(char ssn[10], vector<salaryRecord> &salaryRecordsVec);

    private:
        void addToList(employee newEmployee);
};

#endif // READWRITE_H
