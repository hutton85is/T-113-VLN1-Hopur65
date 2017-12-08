#include "addRecordsUI.h"




addRecordsUI::addRecordsUI()
{
    //ctor
}

addRecordsUI::~addRecordsUI()
{
    //dtor
}


void addRecordsUI::addSsn(){

    string name;
    char ssn[10];
    int year;
    int month;
    int salary;
    cout << "Enter ssn " << endl;
    cin >> ssn;
    cout << "Enter name " << endl;
    cin >> ws;
    getline(cin, name);
    cout << "Enter year " << endl;
    cin >> year;
    cout << "Enter month " << endl;
    cin >> month;
    cout << "Enter salary " << endl;
    cin >> salary;
    addRecords add;
    const char* fname = name.c_str();
    add.addEmployee(fname, ssn, year, month, salary);
}


void addRecordsUI::addRecord(){

    char ssn[10];
    int year;
    int month;
    int salary;
    cout << "Enter ssn " << endl;
    cin >> ssn;
    cout << "Enter year " << endl;
    cin >> year;
    cout << "Enter month " << endl;
    cin >> month;
    cout << "Enter salary " << endl;
    cin >> salary;
    addRecords add;
    add.addSsnRecords(ssn, year, month, salary);
}

void addRecordsUI::displayRecordsBySsn(){

    char ssn[10];
    cout << "Enter SSN: " << endl;
    cin >> ssn;
    addRecords add;
    pair <employee, vector<salaryRecord> > newEmployeePair = add.findRecordsBySsn(ssn);

    cout << newEmployeePair.first << endl;

    cout << newEmployeePair.second.size() << endl;

    for (unsigned int i = 0; i < newEmployeePair.second.size(); i++){
        cout << newEmployeePair.second[i] << endl;
    }
}

void addRecordsUI::addEmployee(){

    char input;

    while(true){

        cout << "Press 1 to add an employee" << endl;
        cout << "Press 2 to add a salary record for a given employee" << endl;
        cout << "Press 3 to get all salary records for a given SSN" << endl;
        cout << "Press 4 to get total salary for a given year and a given SSN" << endl;
        cout << "Press 5 to get the name of the employee with the highest total salary for a given year" << endl;

        cin >> input;

        if(input == '1'){

            addSsn();
        }

        else if(input == '2'){

            addRecord();
        }

        else if(input == '3'){

            displayRecordsBySsn();
        }
    }

}



bool addRecordsUI::validateYear(int year){
    if(year <= 2017 && year >=0){
    return true;
    }
    else return false;
}
bool addRecordsUI::validateMonth(int month){
    if(month <=12 && month >=1){
    return true;
    }
    else return false;
}
bool addRecordsUI::validateSalary(int salary){
    if(salary <= 2000000 && salary >= 300000){
        return true;
    }
    else {return false;}
}
/*bool mainUI::validateSsn(string ssn){
    if(ssn.size() == 10){
        for(int i = 0; i < 10; i++){
            if(isdigit(ssn[i])!=true){
                break;
        }
    }
        return true;
}
    return false;
}
*/
