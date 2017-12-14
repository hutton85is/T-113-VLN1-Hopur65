/**
* @brief User interface for setting customers order as in progress and/or finished
*
*/

#ifndef BAKERUI_H
#define BAKERUI_H

#include "UIHelper.h"
#include "Baker.h"
#include <cstdlib>
#include "ErrorException.h"
#include <climits>

class BakerUI
{
    public:
        BakerUI();

        void main();

        void displayAllOrders();

        void displayCustomerDueProgress();

        void displayCustomerInProgress();

        void displayCustomerDueProgressOrder(unsigned int customerNumber);

        void displayCustomerInProgressOrder(unsigned int customerNumber);

        void chooseSeeAllOrders();

        void chooseSeeDueOrders();

        void chooseSeeInProgressOrders();

        /**
        * @brief Choose location of baker
        *
        * @return false if there are no pending customers, else true
        */
        bool pickLocation();

    private:

        Baker baker;

        UIHelper helperUI;
};

#endif // BAKERUI_H
