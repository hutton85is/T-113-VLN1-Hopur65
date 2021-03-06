#include "addRecords.h"

addRecords::addRecords()
{
    loadDataBase();
}

addRecords::~addRecords()
{
    //dtor
}

<<<<<<< HEAD
void addRecords::addEmployee(const char* name, char ssn[10], int year, int month, int salary){

    employee newEmployee;
    strcpy(newEmployee.name, name);
    strcpy(newEmployee.ssn, ssn);
    readWrite rw;
    rw.writeEmployee(newEmployee);

    salaryRecord newSalary;
    newSalary.year = year;
    newSalary.month = month;
    newSalary.salary = salary;
    rw.writeSsnRecord(newSalary, newEmployee.name);
}

void addRecords::addSsnRecords(char ssn[10], int year, int month, int salary){
    unsigned int i = 0;
    bool found = false;

    searchSsn(i, found, ssn);

    if(found){
        salaryRecord newSalary;
        newSalary.year = year;
        newSalary.month = month;
        newSalary.salary = salary;

        readWrite rw;
        rw.writeSsnRecord(newSalary,collection[i].first.name);
    }
}

void addRecords::getSsnRecords(char ssn[10]){

    loadDataBase();
    unsigned int i = 0;
    bool found = false;

    searchSsn(i, found, ssn);

    if(found){
        cout << collection[i].first << endl;

        for(unsigned int k = 0; k < collection[i].second.size(); k++){
            cout << collection[i].second[k] << endl;
        }
    }
}

void addRecords::searchSsn(unsigned int &i, bool &found, char ssn[10]){

        for (; i < collection.size(); i++){

            int counter = 0;

            for (int k = 0; k < 10; k++){

                if(collection[i].first.ssn[k] == ssn[k]){
                    counter ++;
                }
            }

            if(counter == 10){
                found = true;
                break;
            }
        }
}

void addRecords::loadDataBase(){

    vector <employee> listOfNames;
    readWrite rw;
    rw.readList(listOfNames);
    for (unsigned int i = 0; i < listOfNames.size(); i++){
        employee newEmployee;
        vector<salaryRecord> srvec;
        rw.readEmployee(listOfNames[i].name, newEmployee, srvec);

        pair <employee, vector <salaryRecord> > newPair;
        newPair.first = newEmployee;
        newPair.second = srvec;
        collection.push_back(newPair);
    }
}

pair <employee, vector<salaryRecord> > addRecords::findRecordsBySsn(char ssn[10]){

    unsigned int i = 0;
    bool found = false;
    readWrite rw;

    searchSsn(i, found, ssn);

    pair <employee, vector<salaryRecord> > newEmployeePair;

    if(found){
        employee newEmployee;
        vector <salaryRecord> vec;
        rw.readEmployee(collection[i].first.name, newEmployee, vec);
       newEmployeePair.first = newEmployee;
       newEmployeePair.second = vec;
       //newEmployeePair.first = collection[i].first;
       //newEmployeePair.second = collection[i].second;
    }

    return newEmployeePair;
}


=======
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
>>>>>>> 5d1a0e5657ae6b82c2003fb3df292bc43d751c3d
