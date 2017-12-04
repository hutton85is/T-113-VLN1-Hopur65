#ifndef UMSJON_H
#define UMSJON_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

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
        void createCrust(char crust_type[32], int price);
        void createToppings(char toppings[32], int price);
        void createPizzaSize(char p_size[32], int price);
        void createMenu(char choose_pizza[32], int price);
        void createExtras(char extras_type[32], int price);
        void createLocation(char place[32]);

        vector<PizzaCrust> getpcrust();
        vector<PizzaExtras> getpextras();
        vector<PizzaLocations> getplocations();
        vector<PizzaMenu> getpMenu();
        vector<PizzaSize> getpsize();
        vector<PizzaToppings> getptoppings();

    private:
        Pizza lager;

};

#endif // UMSJON_H
