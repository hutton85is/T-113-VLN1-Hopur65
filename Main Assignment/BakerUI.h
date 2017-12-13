#ifndef BAKERUI_H
#define BAKERUI_H

#include "UIHelper.h"
#include "Baker.h"
#include <cstdlib>

class BakerUI
{
    public:
        BakerUI();
        virtual ~BakerUI();

        void main();

        void displayAllOrders();

        void displayCustomerDueProgress();

        void displayCustomerInProgress();

        void displayCustomerDueProgressOrder(unsigned int customerNumber);

        void displayCustomerInProgressOrder(unsigned int customerNumber);

        /*
        * Choose location of baker and retrieve all pending customers.
        * return false if there are no pending customers, else true
        */
        bool pickLocation();

    private:

        Baker baker;

        UIHelper helperUI;
};

#endif // BAKERUI_H
