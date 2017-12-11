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
<<<<<<< HEAD



    private:
=======
>>>>>>> 5d1a0e5657ae6b82c2003fb3df292bc43d751c3d
};

#endif // EMPLOYEE_H
