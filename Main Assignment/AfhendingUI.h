/**
* @brief User interface for delivering finished orders
*
*/

#ifndef AFHENDINGUI_H
#define AFHENDINGUI_H

#include "Afhending.h"
#include "UIHelper.h"
#include "Error.h"
#include <climits>

class AfhendingUI
{
    public:
        AfhendingUI();

        /**
        * @brief Menu with available options
        */
        void main();

        /**
        * @brief choose location of baker and retrieve all customers with finished orders
        *
        * @return true if there are customers available, else false
        */
        bool pickLocation();

        void displayAllCustomers(bool show);

        void displayCustomerOrder(unsigned int customerNumber);

    private:

        Afhending afhending;

        UIHelper helperUI;

        void chooseSeeAllOrders();

        void chooseSeeFinishedOrders();
};

#endif // AFHENDINGUI_H
