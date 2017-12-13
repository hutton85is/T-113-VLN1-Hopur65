#include "readWrite.h"

readWrite::readWrite()
{
    //ctor
}

readWrite::~readWrite()
{
    //dtor
}

<<<<<<< HEAD
void readWrite::writeEmployee(employee newEmployee){
    ofstream fout;
    char* fname = newEmployee.name;
    strcat(fname, ".dat");
    fout.open(fname, ios_base::binary);
    fout.write((char*)(&newEmployee), sizeof(employee));
    fout.close();
    ofstream out;
    out.open("listOfNames.dat", ios_base::binary | ios_base::app);
    out.write((char*)(&newEmployee), sizeof(employee));
    out.close();
}

void readWrite::writeSsnRecord(salaryRecord newSalary, char name[40]){
    ofstream fout;
    strcat(name, ".dat");
    fout.open(name, ios_base::binary | ios_base::app);
    fout.write((char*)(&newSalary), sizeof(salaryRecord));
    fout.close();
}

void readWrite::readEmployee(const char* name, employee &newEmployee, vector <salaryRecord> srvec){
    ifstream fin;
    fin.open(name, ios::binary);
    if(fin.is_open()){
        fin.seekg(0, fin.end);
        int fileSize = fin.tellg();
        fin.seekg(0, fin.beg);
        fin.read((char*)(&newEmployee), sizeof(employee));
        fileSize = fileSize - sizeof(employee);

        while(fileSize >0){

            salaryRecord newRecord;
            fin.read((char*)(&newRecord), sizeof(salaryRecord));

            srvec.push_back(newRecord);
            fileSize = fileSize - sizeof(salaryRecord);
        }

            fin.close();
    }
    else{cout << "No information" << endl;}
=======
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
>>>>>>> 5d1a0e5657ae6b82c2003fb3df292bc43d751c3d
}

void readWrite::readList(vector <employee> &listOfNames){
    ifstream file;
<<<<<<< HEAD
    file.open("listOfNames.dat", ios_base::binary);
=======
    file.open("data/list.dat", ios_base::binary);
>>>>>>> 5d1a0e5657ae6b82c2003fb3df292bc43d751c3d

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

<<<<<<< HEAD
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
=======
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
>>>>>>> 5d1a0e5657ae6b82c2003fb3df292bc43d751c3d
    }
}
