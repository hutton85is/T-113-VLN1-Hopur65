/**
* @brief Functional class for BakerUI
*
* Class can set customer order as being worked on and finished working on.
*/

#ifndef BAKER_H
#define BAKER_H

#include "ReadWriteClass.h"
#include <iostream>
#include <string>

class Baker
{
    public:
        Baker();

        /**
        * @brief Set baker location and customize vectors
        *
        * Function that set's baker location and sort's orders
        * into vector's depending on order status 'in progress'
        * or 'due progress'
        *
        * @param currentLocation is baker's location
        */
        void setBakerLocation(char currentLocation[32]);

        vector<Client> getCustomerVec();

        vector<Client> getCustomersVecInProgress();

        vector<Client> getCustomersVecDueProgress();

        vector<Pizza> getOrderVec(unsigned int customersVecNumber);

        vector<Pizza> getCustomersOrderDueProgress(unsigned int customerNumber);

        vector<Pizza> getCustomersOrderInProgress(unsigned int customerNumber);

        vector<PizzaLocations> getPizzaLocations();

        string getBakerLocation();

        /**
        * @brief Set customer order as in progress
        *
        * Move customer from customersVecDueProgress to customersVecInProgress
        * and rewrite file containing customer order with updated client class
        *
        * @param customersVecNumber is the position of customer to update in vector
        */
        void workOnOrder(unsigned int customersVecNumber);

        /**
        * @brief Set customer order as finished
        *
        * Move customer from customersVecInProgress and set status as finished.
        * Rewrite file containing customer order with updated client class
        *
        * @param customerID is the position of customer to update in vector
        */
        void finishOrder(unsigned int customerID);

    private:
        vector<Client> customersVec;

        vector<Client> customersVecInProgress;

        vector<Client> customersVecDueProgress;

        char bakerLocation[32];
};

#endif // BAKER_H
