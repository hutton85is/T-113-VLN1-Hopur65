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
        void addSsn();
        void addRecord();
        void addEmployee();
        bool validateYear(int year);
        bool validateMonth(int month);
        bool validateSalary(int salary);
        void displayRecordsBySsn();



    private:
};

#endif // ADDRECORDSUI_H
