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

        //Vectors containing classes of available items for sale
        vector <PizzaToppings> ptoppings;
        vector <PizzaSize> psize;
        vector <PizzaCrust> pcrust;
        vector <PizzaExtras> pextras;
        vector <PizzaMenu> pmenu;
        vector <PizzaLocations> plocations;

        Pizza order(const char* name);

        /*
        * Function that writes a template class to binary file under filename
        * and path under variable 'fname'. If the file does not exist, it is created.
        */
        template <typename pizzaClass>
        void writeClassToFile(pizzaClass& classToWrite, const char* fname);

        // Function that loads all vectors from database containing all items available for sale and stores them in Pizza class 'p'
        void loadAllVectors(Pizza& p);

    private:
        /* boolean function that loads a vector from a specific file storing a template class
        * loadvector is the template vector to be loaded from file
        * fileName is a variable containing the path and filename to the class to load
        * pClass is a variable containing the template class to be loaded from a file
        */
        template <typename pizzaClass>
        bool loadSpecificVector(vector<pizzaClass>& loadVector, const char* fileName, pizzaClass& pClass);

        // This is a dummy loader that if I dont include I cant use writeClassToFile function
        void dummyLoader();
};

#endif // PIZZA_H
