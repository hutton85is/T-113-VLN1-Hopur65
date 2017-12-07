#ifndef SALA_H
#define SALA_H

#include "Pizza.h"
#include "PizzaSize.h"
#include "pizzatoppings.h"
#include "pizzacrust.h"
#include "pizzaextras.h"
#include "pizzalocations.h"
#include "pizzamenu.h"
#include "readWriteClass.h"
#include "client.h"
#include <cstring>
#include <stdlib.h>

class Sala
{
    public:
        /*
        * Make the constructor load variable lager with all available items for sale
        */
        Sala();
        virtual ~Sala();

        /*
        * Receive input choice from user, of different order choices and push it to on the corresponding vector
        * Return true if input is a valid integer.
        * Return false if input is an invalid integer.
        */
        bool enterPizzaSize(unsigned int input);
        bool enterCrust(unsigned int input);
        bool enterToppings(unsigned int input);
        bool enterMenu(unsigned int input);
        bool enterExtras(unsigned int input);
        bool enterLocation(unsigned int input);

        // Initiate a new pizza
        void newPizza();

        // Return a copy of client class
        client getCustomerOrdersVector();

        bool createOrder(string name, string address, int number);

        /*
        * Get functions used to retrieve from Pizza class a copy of corresponding vector, and return it to the UI
        */
        vector<PizzaCrust> getLagerpcrust();
        vector<PizzaExtras> getLagerpextras();
        vector<PizzaLocations> getLagerplocations();
        vector<PizzaMenu> getLagerpMenu();
        vector<PizzaSize> getLagerpsize();
        vector<PizzaToppings> getLagerptoppings();

        //Pizza order;
        vector<Pizza> order;
        // A vector containing classes to store how many items are on an order
        vector<PizzaHelper> pHelper;

    private:
        // variable lager contains all items available to sell
        // variable order contains all items a customer has ordered
        Pizza lager;

        client newCustomer;
};

#endif // SALA_H
