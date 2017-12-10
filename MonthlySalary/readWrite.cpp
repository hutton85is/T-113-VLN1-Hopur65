#include "readWrite.h"

readWrite::readWrite()
{
    //ctor
}

readWrite::~readWrite()
{
    //dtor
}

void readWrite::writeEmployeeRecord(char ssn[10], salaryRecord newSalary)
{
    ofstream file;
    string name = "data/";
    for (int i = 0; i < 10; i++)
    {
        name = name + ssn[i];
    }
    name += ".dat";
    const char* fname = name.c_str();

    file.open(fname, ios_base::binary|ios_base::app);
    file.write((char*)(&newSalary), sizeof(salaryRecord));
    file.close();
}

void readWrite::writeEmployeeRecord(employee newEmployee, salaryRecord newSalary)
{
    ofstream file;
    string name = "data/";
    for (int i = 0; i < 10; i++)
    {
        name = name + newEmployee.ssn[i];
    }
    name += ".dat";
    const char* fname = name.c_str();

    file.open(fname, ios_base::binary|ios_base::app);
    addToList(newEmployee);
    file.write((char*)(&newSalary), sizeof(salaryRecord));
    file.close();
}

void readWrite::addToList(employee newEmployee)
{
    ofstream file;
    const char* fname = "data/list.dat";

    file.open(fname, ios_base::binary|ios_base::app);
    file.write((char*)(&newEmployee), sizeof(employee));
    file.close();
}

void readWrite::readList(vector <employee> &listOfNames){
    ifstream file;
    file.open("data/list.dat", ios_base::binary);

    if(file.is_open())
    {
        file.seekg(0, file.end);
        int records = file.tellg() / sizeof(employee);
        file.seekg(0, file.beg);

        for(int i = 0; i < records; i++)
        {
            employee newEmployee;
            file.read((char*)(&newEmployee), sizeof(employee));
            listOfNames.push_back(newEmployee);
        }
        file.close();
    }
}

void readWrite::readSalaryRecords(char ssn[10], vector<salaryRecord> &salaryRecordsVec)
{
    ifstream file;
    string name = "data/";
    for (int i = 0; i < 10; i++)
    {
        name = name + ssn[i];
    }
    name += ".dat";
    const char* fname = name.c_str();
    file.open(fname, ios_base::binary);

    if(file.is_open())
    {
        file.seekg(0, file.end);
        int records = file.tellg() / sizeof(salaryRecord);
        file.seekg(0, file.beg);

        for(int i = 0; i < records; i++)
        {
            salaryRecord newSalaryRecord;
            file.read((char*)(&newSalaryRecord), sizeof(salaryRecord));
            salaryRecordsVec.push_back(newSalaryRecord);
        }
        file.close();
    }
}

void readWrite::highestSalary(int year){
    ifstream fin;
    int temp1 = 0;
    string temp;
    fin.open("", ios::binary);
    if(fin.is_open()){
        fin.seekg(0, fin.end);
        int Counter = fin.tellg() / sizeof(salaryRecord);
        fin.seekg(0, fin.beg);
        for(int i = 0; i < Counter; i++){
            salaryRecord s;
            fin.read((char*)(&s), sizeof(salaryRecord));
            if(s.year == year) {
                if(s.salary >= temp1){
                    temp1 = s.salary;
                }

            }
        }

        fin.close();
    }
    else{
            cout << "No information" << endl;
    }
}
