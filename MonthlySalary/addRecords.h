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

<<<<<<< HEAD
       vector < pair < employee, vector < salaryRecord > > > collection;

        void addEmployee(const char* name, char ssn[10], int year, int month, int salary);
        void getSsnRecords(char ssn[10]);
        void addSsnRecords(char ssn[10], int year, int month, int salary);
        pair <employee, vector<salaryRecord> > findRecordsBySsn(char ssn[10]);

       private:
         void loadDataBase();
         void searchSsn(unsigned int &i, bool &found, char ssn[10]);
=======
        void addRecordBySSN(const char* name, char ssn[10], int year, int month, int salary);
        void addRecordBySSN(char ssn[10], int year, int month, int salary);
        pair < employee, vector < salaryRecord > > getPairBySSN(char SSN[10]);
        pair < employee, vector < salaryRecord > > getPairBySSNAndYear(char SSN[10], int year);
        employee highestTotalSalaryOfYear(int year);

    private:
        vector < pair < employee, vector < salaryRecord > > > collection;
        void loadDataBase();
>>>>>>> 5d1a0e5657ae6b82c2003fb3df292bc43d751c3d
};

#endif // ADDRECORDS_H
