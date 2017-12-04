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
        void createCrust();
        void createToppings();
        void createPizzaSize();
        void createMenu();
        void createExtras();
        void createLocation();

    private:
        Pizza lager;

};

#endif // UMSJON_H
