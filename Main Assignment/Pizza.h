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


        void writeToppingsVector(PizzaToppings& wToppings);
        void writeSizeVector(PizzaSize& wSize);
        void writeCrustVector(PizzaCrust& wCrust);
        void writeExtrasVector(PizzaExtras& wExtras);
        void writeMenuVector(PizzaMenu& wMenu);
        void writeLocationsVector(PizzaLocations& wLocation);

        void loadAllVectors(Pizza& p);
        void displayToppings(vector <PizzaToppings>& vec);

    private:
        /*template <typename pizzaClass>
        bool loadSpecificVector(Pizza& p, unsigned int classSize, string fileName, pizzaClass p);*/
        bool loadToppingsVector(Pizza& p);
        bool loadSizeVector(Pizza& p);
        bool loadCrustVector(Pizza& p);
        bool loadExtrasVector(Pizza& p);
        bool loadMenuVector(Pizza& p);
        bool loadLocationsVector(Pizza& p);
};

#endif // PIZZA_H
