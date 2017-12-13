#ifndef AFHENDINGUI_H
#define AFHENDINGUI_H

#include "Afhending.h"
#include "UIHelper.h"
#include "Error.h"

class AfhendingUI
{
    public:
        AfhendingUI();

        void main();
        /*
        * Choose location of baker and retrieve all pending customers.
        * return false if there are no pending customers, else true
        */
        bool pickLocation();

        // Display all finished orders, variable 'show' is to use as true if number of orders is to display
        void displayAllCustomers(bool show);

        // Display customer order that has vector identifier as customerNumber
        void displayCustomerOrder(unsigned int customerNumber);

    private:
        Afhending afhending;

        UIHelper helperUI;
};

#endif // AFHENDINGUI_H
