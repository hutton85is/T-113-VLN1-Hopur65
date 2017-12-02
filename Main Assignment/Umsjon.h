#ifndef UMSJON_H
#define UMSJON_H

#include <iostream>
#include <vector>

#include "Pizza.h"
#include "PizzaSize.h"
#include "pizzatoppings.h"
#include "pizzacrust.h"
#include "pizzaextras.h"
#include "pizzalocations.h"
#include "pizzamenu.h"

using namespace std;

class Umsjon
{
    public:
        Umsjon();
        virtual ~Umsjon();
        void enterCrust();
        void enterToppings();
        void enterPizzaSize();
        void enterMenu();
        void enterExtras();
        void enterLocation();

    private:
        Pizza lager;

};

#endif // UMSJON_H
