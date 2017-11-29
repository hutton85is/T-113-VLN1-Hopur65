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
        void enterCrust(Pizza& p);
        void enterToppings(Pizza& p);
        void enterPizzaSize(Pizza& p);
        void enterMenu(Pizza& p);
        void enterExtras(Pizza& p);
        void enterLocation(Pizza& p);


    private:
        Pizza p;


};

#endif // UMSJON_H
