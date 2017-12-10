#include "addRecords.h"

addRecords::addRecords()
{
    loadDataBase();
}

addRecords::~addRecords()
{
    //dtor
}

void addRecords::addRecordBySSN(char ssn[10], int year, int month, int salary)
{
    salaryRecord newSalaryRecord;
    newSalaryRecord.year = year;
    newSalaryRecord.month = month;
    newSalaryRecord.salary = salary;

    readWrite rw;
    rw.writeEmployeeRecord(ssn, newSalaryRecord);
}

void addRecords::addRecordBySSN(const char* name, char ssn[10], int year, int month, int salary){

    employee newEmployee;
    strcpy(newEmployee.name, name);
    strcpy(newEmployee.ssn, ssn);

    salaryRecord newSalaryRecord;
    newSalaryRecord.year = year;
    newSalaryRecord.month = month;
    newSalaryRecord.salary = salary;

    readWrite rw;
    rw.writeEmployeeRecord(newEmployee, newSalaryRecord);
}

void addRecords::loadDataBase()
{
    readWrite rw;
    vector <employee> listOfNames;
    rw.readList(listOfNames);

    // read all salary records from files to template variable pair <employee, vector <salaryRecord> > newPair and add to collection of employees
    for (unsigned int i = 0; i < listOfNames.size(); i++)
    {
        employee newEmployee = listOfNames[i];
        vector<salaryRecord> salaryRecordsVec;
        rw.readSalaryRecords(newEmployee.ssn, salaryRecordsVec);

        pair <employee, vector <salaryRecord> > newPair;
        newPair.first = newEmployee;
        newPair.second = salaryRecordsVec;
        collection.push_back(newPair);
    }
}

pair < employee, vector < salaryRecord > > addRecords::getPairBySSN(char SSN[10])
{
    pair < employee, vector < salaryRecord > > SSNPair;
    bool found = true;
    unsigned int i = 0;
    for(; i < collection.size(); i++)
    {
        found = true;
        for(unsigned int k = 0; k < 10; k++)
        {
            if(collection[i].first.ssn[k] != SSN[k])
            {
                found = false;
                break;
            }
        }
        if(found)
        {
            SSNPair = collection[i];
            break;
        }
    }
    return SSNPair;
}

pair < employee, vector < salaryRecord > > addRecords::getPairBySSNAndYear(char SSN[10], int year)
{
    pair < employee, vector < salaryRecord > > SSNPair = getPairBySSN(SSN);
    vector<salaryRecord> newSalaryRecord;
    for(unsigned int i = 0; i < SSNPair.second.size(); i++)
    {
        if(SSNPair.second[i].year == year)
        {
            newSalaryRecord.push_back(SSNPair.second[i]);
        }
    }
    SSNPair.second = newSalaryRecord;
    return SSNPair;
}

employee addRecords::highestTotalSalaryOfYear(int year)
{
    employee highestPaidEmployee;
    int highestSalary = 0;
    // run through all employees and find their total salary for a year. Update highestSalary and highestPaidEmployee when highest paid employee is found
    for(unsigned int i = 0; i < collection.size(); i++)
    {
        int totalSalary = 0;
        // a template pair containing an employee and his salary record for a given year
        pair < employee, vector < salaryRecord > > salaryYear = getPairBySSNAndYear(collection[i].first.ssn, year);
        // Sum all payments that year
        for(unsigned int k = 0; k < salaryYear.second.size(); k++)
        {
            totalSalary = totalSalary + salaryYear.second[k].salary;
        }
        if(highestSalary < totalSalary)
        {
            highestPaidEmployee = salaryYear.first;
        }
    }
    return highestPaidEmployee;
}
