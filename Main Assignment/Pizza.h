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

        bool loadFile(Pizza& p);
        void writeFile(Pizza& p);
        void displaySize(vector <PizzaSize>& vec);
        friend istream& operator >>(istream &ins, Pizza& p);

    private:
};

#endif // PIZZA_H
