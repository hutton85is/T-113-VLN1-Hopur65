#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>

//#include "pizzaSize.h"

using namespace std;


class Pizza
{
    public:
        Pizza();
        virtual ~Pizza();

        vector<pizzaSize> Size;
        vector<pizzaToppings> Toppings;
        vector<pizzaCrust> Crust;
        vector<pizzaExtras> Extras;
        vector<pizzaPizzas> Pizzas;
        vector<pizzaLocation> Location;

        bool loadFile(Pizza& p);
        void writeFile(Pizza& p);
        void displaySize(vector <pizzaSize>& vec);
        friend istream& operator >>(istream &ins, Pizza& p);

    private:
};

#endif // PIZZA_H
