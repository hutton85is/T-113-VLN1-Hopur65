#ifndef ADDRECORDS_H
#define ADDRECORDS_H

#include "readWrite.h"
#include <utility>
#include <vector>
#include <string.h>
#include <stdio.h>
#include "employee.h"
#include "salaryRecord.h"

class addRecords
{
    public:
        addRecords();
        virtual ~addRecords();

       vector < pair < employee, vector < salaryRecord > > > collection;

        void addEmployee(const char* name, char ssn[10], int year, int month, int salary);
        void getSsnRecords(char ssn[10]);
        void addSsnRecords(char ssn[10], int year, int month, int salary);
        pair <employee, vector<salaryRecord> > findRecordsBySsn(char ssn[10]);

       private:
         void loadDataBase();
         void searchSsn(unsigned int &i, bool &found, char ssn[10]);
};

#endif // ADDRECORDS_H
