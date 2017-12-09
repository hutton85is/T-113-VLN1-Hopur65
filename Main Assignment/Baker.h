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

        // Return customer vector with same location as baker
        vector<client> getCustomerVec();

        // Return pizza order of a chosen customer
        vector<Pizza> getOrderVec(unsigned int customersVecNumber);

        vector<PizzaHelper> getpHelperVec();

        // Return all available pizza place locations
        vector<PizzaLocations> getPizzaLocations();

        // Return baker location
        string getBakerLocation();

    private:
        // A vector of customers ordering from same location as location of baker
        vector<client> customersVec;
        //vector<Pizza> order;
        //vector<PizzaHelper> pHelper;
        char bakerLocation[32];
};

#endif // BAKER_H
