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
<<<<<<< HEAD
        void writeEmployee(employee newEmployee);
        void readEmployee(const char* name, employee &newEmployee, vector <salaryRecord> srvec);
        void readList(vector <employee> &listOfNames);
        void highestSalary(int year);
        void writeSsnRecord(salaryRecord newSalary, char name[40]);

    private:
=======
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
>>>>>>> 5d1a0e5657ae6b82c2003fb3df292bc43d751c3d
};

#endif // READWRITE_H
