#ifndef BAKER_H
#define BAKER_H

#include "readWriteClass.h"
#include <iostream>
#include <string>

class Baker
{
    public:
        Baker();
        virtual ~Baker();

        void setBakerLocation(char currentLocation[32]);

        vector<client> getCustomerVec();
        vector<Pizza> getOrderVec();
        vector<PizzaHelper> getpHelperVec();
        vector<PizzaLocations> getPizzaLocations();

    private:
        vector<client> customersVec;
        vector<Pizza> order;
        vector<PizzaHelper> pHelper;
        char bakerLocation[32];
};

#endif // BAKER_H
