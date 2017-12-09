#ifndef BAKERUI_H
#define BAKERUI_H

#include "Baker.h"
#include <cstdlib>

class BakerUI
{
    public:
        BakerUI();
        virtual ~BakerUI();

        void main();

        void displayAllOrders();

        void displayCustomerList();

        void displayCustomerOrder(unsigned int customerNumber);

        /*
        * Choose location of baker and retrieve all pending customers.
        * return false if there are no pending customers, else true
        */
        bool pickLocation();

        char pickCustomer();

    private:
        template<typename Pizzaclass>
        void displayVector(vector<Pizzaclass> vec, bool choice);

        Baker baker;
};

#endif // BAKERUI_H
