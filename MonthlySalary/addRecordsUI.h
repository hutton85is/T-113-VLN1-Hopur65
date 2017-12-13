#ifndef ADDRECORDSUI_H
#define ADDRECORDSUI_H

#include <iostream>
#include <istream>
#include <string>

#include "salaryRecord.h"
#include "addRecords.h"

using namespace std;


class addRecordsUI
{
    public:
        addRecordsUI();
        virtual ~addRecordsUI();
<<<<<<< HEAD
        void addSsn();
=======
        void addNewRecordBySSN();
>>>>>>> 5d1a0e5657ae6b82c2003fb3df292bc43d751c3d
        void addRecord();
        void addEmployee();
        bool validateYear(int year);
        bool validateMonth(int month);
        bool validateSalary(int salary);
        void displayRecordsBySsn();
<<<<<<< HEAD



    private:
=======
        void displayRecordsBySSNAndYear();
        void displayHighestSalaryForYear();
>>>>>>> 5d1a0e5657ae6b82c2003fb3df292bc43d751c3d
};

#endif // ADDRECORDSUI_H
