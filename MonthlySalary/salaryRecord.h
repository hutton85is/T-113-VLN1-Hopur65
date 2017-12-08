#ifndef SALARYRECORD_H
#define SALARYRECORD_H

#include<string>
#include<iostream>

using namespace std;


class salaryRecord
{
    public:
        int salary;
        int month;
        int year;
        salaryRecord();
        virtual ~salaryRecord();
        int get_salary();
        int get_month();
        int get_year();


        friend ostream& operator << (ostream& out, salaryRecord& record);

    private:

};

#endif // SALARYRECORD_H
