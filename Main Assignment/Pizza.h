#ifndef PIZZA_H
#define PIZZA_H

#include <vector>
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

        //PizzaClass vectors
        vector <PizzaToppings> ptoppings;
        vector <PizzaSize> psize;
        vector <PizzaCrust> pcrust;
        vector <PizzaExtras> pextras;
        vector <PizzaMenu> pmenu;
        vector <PizzaLocations> plocations;

        template <typename pizzaClass>
        void writeSpecificClassToFile(pizzaClass& classToWrite, const char* fname);

        void loadAllVectors(Pizza& p);

    private:
        template <typename pizzaClass>
        bool loadSpecificVector(vector<pizzaClass>& loadVector, const char* fileName, pizzaClass& pClass);
        void loaderDummy();
};

#endif // PIZZA_H
