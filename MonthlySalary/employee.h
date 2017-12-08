#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <vector>
#include <iostream>

using namespace std;


class employee
{
    public:
        char name[40];
        char ssn[10];
        int recordCounter;
        employee();
        virtual ~employee();
        friend ostream& operator << (ostream& out, employee& emp);



    private:
};

#endif // EMPLOYEE_H
