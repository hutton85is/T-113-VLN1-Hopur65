#include "addRecords.h"

addRecords::addRecords()
{
    loadDataBase();
}

addRecords::~addRecords()
{
    //dtor
}

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


