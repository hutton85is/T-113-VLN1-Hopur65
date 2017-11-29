#ifndef UMSJON_H
#define UMSJON_H

#include <iostream>
<<<<<<< HEAD
=======

>>>>>>> 365c2446da153555747210bf1228738c20142678
#include "Pizza.h"

using namespace std;

class Umsjon
{
    public:
        Umsjon();
        virtual ~Umsjon();
        void enterCrust();
        void enterToppings();

        void enterPizzaSize();

        void print();

    protected:

    private:
        Pizza p;

    private:
};

#endif // UMSJON_H
