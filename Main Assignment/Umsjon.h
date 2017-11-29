#ifndef UMSJON_H
#define UMSJON_H

#include <iostream>

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
