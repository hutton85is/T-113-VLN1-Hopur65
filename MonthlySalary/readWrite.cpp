#include "readWrite.h"

readWrite::readWrite()
{
    //ctor
}

readWrite::~readWrite()
{
    //dtor
}

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
}

void readWrite::readList(vector <employee> &listOfNames){
    ifstream file;
    file.open("listOfNames.dat", ios_base::binary);

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
