#ifndef AFHENDING_H
#define AFHENDING_H

#include "readWriteClass.h"
#include <iostream>
#include <string>

class Afhending
{
    public:
        Afhending();
        virtual ~Afhending();

        // Set location of baker and retrieve all customers from same location that orders have been finished
        void setAfhendingLocation(char currentLocation[32]);

        // Return all available pizza place locations
        vector<PizzaLocations> getPizzaLocations();

        // Return customer vector 'customersVec'
        vector<client> getCustomerVec();

        // Return pizza order of a chosen customer
        vector<Pizza> getOrderVec(unsigned int customersVecNumber);

        // Set status of customer as in progress
        void deliverOrder(unsigned int customersVecNumber);

    private:
        // Location of pizza place
        char afhendingLocation[32];

        // A vector of all customers ordering from same location as baker
        vector<client> customersVec;
};

#endif // AFHENDING_H
