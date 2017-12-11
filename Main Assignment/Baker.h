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

        // Return customer vector 'customersVec'
        vector<client> getCustomerVec();

        // Return customer vector 'customersVecInProgress'
        vector<client> getCustomersVecInProgress();

        // Return customer vector 'customersVecDueProgress'
        vector<client> getCustomersVecDueProgress();

        // Return pizza order of a chosen customer
        vector<Pizza> getOrderVec(unsigned int customersVecNumber);

        vector<PizzaHelper> getpHelperVec();

        // Return all available pizza place locations
        vector<PizzaLocations> getPizzaLocations();

        // Return baker location
        string getBakerLocation();

        void workOnOrder(unsigned int customersVecNumber);

    private:
        // A vector of all customers ordering from same location as baker
        vector<client> customersVec;

        // A vector of customers whose orders are being worked on from same location as baker
        vector<client> customersVecInProgress;

        // A vector of customer orders whose orders are currently waiting to be worked on
        vector<client> customersVecDueProgress;

        char bakerLocation[32];
};

#endif // BAKER_H
