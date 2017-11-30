#ifndef SALA_H
#define SALA_H

#include "Pizza.h"
#include "PizzaSize.h"
#include "pizzatoppings.h"
#include "pizzacrust.h"
#include "pizzaextras.h"
#include "pizzalocations.h"
#include "pizzamenu.h"


class Sala
{
    public:
        Sala();
        virtual ~Sala();
        void enterCrust();
        void enterToppings();
        void enterPizzaSize();
        void enterMenu();
        void enterExtras();
        void enterLocation();



    private:
        Pizza lager, order;

};

#endif // SALA_H
