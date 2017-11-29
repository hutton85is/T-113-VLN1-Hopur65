#ifndef PIZZA_H
#define PIZZA_H

#include <vector>
#include <iostream>
#include <utility>

class Pizza
{
    public:
        Pizza();
        virtual ~Pizza();

        vector <pair <char[32],int> > pizzaCrust;
        vector <pair <char[32],int> > pizzaSize;
        vector <pair <char[32],int> > pizzaMenu;
        vector <pair <char[32],int> > pizzaLocation;
        vector <pair <char[32],int> > pizzaToppings;
        vector <pair <char[32],int> > pizzaExtras;
    protected:

    private:
};

#endif // PIZZA_H
