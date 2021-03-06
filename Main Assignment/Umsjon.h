/**
 * @brief Functional class for UmsjonUI
 *
 * This class creates new items for sale and locations of new Pizza places
 */


#ifndef UMSJON_H
#define UMSJON_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

#include "Pizza.h"
#include "PizzaSize.h"
#include "PizzaToppings.h"
#include "PizzaCrust.h"
#include "PizzaExtras.h"
#include "PizzaLocations.h"
#include "PizzaMenu.h"
#include "ReadWriteClass.h"

using namespace std;

class Umsjon
{
    public:

        Umsjon();

        /**
        * @brief All create functions generate a new item for sale or a location
        *
        */

        void createCrust(char crust_type[32], int price);

        void createToppings(char toppings[32], int price);

        void createPizzaSize(char p_size[32], int price);

        void createMenu(char choose_pizza[32], double price, char toppings[128]);

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
