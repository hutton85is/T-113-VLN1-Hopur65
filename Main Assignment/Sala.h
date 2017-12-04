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
        bool enterPizzaSize(int input);
        bool enterCrust(int input);
        bool enterToppings(int input);
        bool enterMenu(int input);
        bool enterExtras(int input);
        bool enterLocation(int input);

        vector<PizzaCrust> getpcrust();
        vector<PizzaExtras> getpextras();
        vector<PizzaLocations> getplocations();
        vector<PizzaMenu> getpMenu();
        vector<PizzaSize> getpsize();
        vector<PizzaToppings> getptoppings();

    private:
        Pizza lager, order;

};

#endif // SALA_H
