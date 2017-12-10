#include "addRecordsUI.h"




addRecordsUI::addRecordsUI()
{
    //ctor
}

addRecordsUI::~addRecordsUI()
{
    //dtor
}


void addRecordsUI::addNewRecordBySSN(){

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
    add.addRecordBySSN(fname, ssn, year, month, salary);
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
    add.addRecordBySSN(ssn, year, month, salary);
}

void addRecordsUI::displayRecordsBySsn(){

    char ssn[10];
    cout << "Enter SSN: " << endl;
    cin >> ssn;
    addRecords add;

    pair <employee, vector<salaryRecord> > newEmployeePair = add.getPairBySSN(ssn);

    cout << newEmployeePair.first << endl;

    for (unsigned int i = 0; i < newEmployeePair.second.size(); i++){
        cout << newEmployeePair.second[i] << endl;
    }
}

void addRecordsUI::displayRecordsBySSNAndYear()
{
    char ssn[10];
    cout << "Enter SSN: " << endl;
    cin >> ssn;

    int year;
    cout << "Enter year: " << endl;
    cin >> year;
    addRecords add;

    pair <employee, vector<salaryRecord> > newEmployeePair = add.getPairBySSNAndYear(ssn, year);

    cout << newEmployeePair.first << endl;

    for (unsigned int i = 0; i < newEmployeePair.second.size(); i++){
        cout << newEmployeePair.second[i] << endl;
    }
}

void addRecordsUI::addEmployee(){

    char input;

    while(true){

        cout << "Press 1 to add an employee with record" << endl;
        cout << "Press 2 to add a salary record for a given employee SSN" << endl;
        cout << "Press 3 to get all salary records for a given SSN" << endl;
        cout << "Press 4 to get total salary for a given year and a given SSN" << endl;
        cout << "Press 5 to get the name of the employee with the highest total salary for a given year" << endl;

        cin >> input;

        if(input == '1'){

            addNewRecordBySSN();
        }

        else if(input == '2'){

            addRecord();
        }

        else if(input == '3'){

            displayRecordsBySsn();
        }
        else if(input == '4'){
            displayRecordsBySSNAndYear();
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
