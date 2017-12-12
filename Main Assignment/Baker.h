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

        /**
        * Function that set's baker location and sort's orders
        * into vector's depending on order status 'in progress'
        * or 'due progress'
        *
        * @param currentLocation is baker's location
        */
        void setBakerLocation(char currentLocation[32]);

        vector<client> getCustomerVec();

        vector<client> getCustomersVecInProgress();

        vector<client> getCustomersVecDueProgress();

        /**
        * @return a vector of all customer orders due progress and in progress
        */
        vector<Pizza> getOrderVec(unsigned int customersVecNumber);

        /**
        * @return a vector only with customer orders due progress
        */
        vector<Pizza> getCustomersOrderDueProgress(unsigned int customerNumber);

        /**
        * @return a vector only with customer orders in progress
        */
        vector<Pizza> getCustomersOrderInProgress(unsigned int customerNumber);

        vector<PizzaLocations> getPizzaLocations();

        string getBakerLocation();

        /**
        * Move customer from customersVecDueProgress to customersVecInProgress
        * and rewrite file containing customer order with updated client class
        *
        * @param customersVecNumber is the position of customer to update in vector
        */
        void workOnOrder(unsigned int customersVecNumber);

        /**
        * Move customer from customersVecInProgress and rewrite file containing
        * customer order with updated client class
        *
        * @param customerID
        */
        void finishOrder(unsigned int customerID);

    private:
        vector<client> customersVec;

        vector<client> customersVecInProgress;

        vector<client> customersVecDueProgress;

        char bakerLocation[32];
};

#endif // BAKER_H
