#ifndef BAKER_H
#define BAKER_H

#include "readWriteClass.h"

class Baker
{
    public:
        Baker(const char* fname);
        virtual ~Baker();

        vector<client> getCustomerVec();
        vector<Pizza> getOrderVec();
        vector<PizzaHelper> getpHelperVec();

    private:
        vector<client> customersVec;
        vector<Pizza> order;
        vector<PizzaHelper> pHelper;
};

#endif // BAKER_H
