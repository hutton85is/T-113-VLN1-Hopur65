/**
* @brief Customer orders and all items available for sale are stored in this class
*
*/


#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>

#include "PizzaSize.h"
#include "pizzatoppings.h"
#include "pizzacrust.h"
#include "pizzaextras.h"
#include "pizzalocations.h"
#include "pizzamenu.h"

using namespace std;

class Pizza
{
    public:
        Pizza();
        virtual ~Pizza();

        vector <PizzaToppings> ptoppings;

        vector <PizzaSize> psize;

        vector <PizzaCrust> pcrust;

        vector <PizzaExtras> pextras;

        vector <PizzaMenu> pmenu;

        vector <PizzaLocations> plocations;

        int calculateSumOfOrder();

        friend ostream& operator <<(ostream& out, Pizza& p);
};

#endif // PIZZA_H
