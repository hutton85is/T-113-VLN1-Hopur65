/**
* Functional class for AfhendingUI
*/


#ifndef AFHENDING_H
#define AFHENDING_H

#include "readWriteClass.h"
#include <iostream>
#include <string>

class Afhending
{
    public:
        /**
        * Load all a directory containing all customers waiting for an order
        */
        Afhending();

        /**
        * Find all customers from customerlist.dat that are from a specific location
        * and whose orders have been finished, and are ready for a delivery
        *
        * @param currentLocation is the location of delivery
        */
        void setAfhendingLocation(char currentLocation[32]);

        vector<PizzaLocations> getPizzaLocations();
        vector<client> getCustomerVec();
        string getAfhendingLocation();


        /**
        * Read orders from file for a customer at specific position in customersVec
        *
        * @param customersVecNumber is the position of customer in customersVec
        */
        vector<Pizza> getOrderVec(unsigned int customersVecNumber);

        /**
        * EFTIR A� COMMENTA
        *
        * @param customersVecNumber is the position of customer in customersVec
        */
        void deliverOrder(unsigned int customersVecNumber);

    private:

        char afhendingLocation[32];

        vector<client> customersVec;
};

#endif // AFHENDING_H
