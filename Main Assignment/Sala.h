/**
* Sala handles functionality for SalaUI.
*/

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
        /**
        * Constructor initiates vector variable lager, with everything available for ordering on a pizza
        */
        Sala();

        /**
         * All enter functions push items selected by customer to order vector
         *
         * @param input: is the location of item in order vector for a specific item ordered
         */
        void enterCrust(unsigned int input);
        void enterExtras(unsigned int input);
        void enterLocation(unsigned int input);
        void enterMenu(unsigned int input);
        void enterToppings(unsigned int input);
        void enterPizzaSize(unsigned int input);



        /**
        * Initiate a new Pizza order and push back former order to vector order
        */
        // Initiate a new pizza
        void newPizza();

        void calculateSumOfOrder();

        void createOrder(string name, string address, int number, bool paid, bool delivery, string comment);

        /**
        * Write client and pizza order to file and client to a directory containing a list of customers
        *
        * @param name is customers name
        * @param address is customers address
        * @param number is customers address number
        * @param paid is true if order is paid, else false
        * @param delivery is true if customer wants a delivery, else false
        */
        void createOrder(string name, string address, int number, bool paid, bool delivery);

        client getCustomerOrdersVector();

        vector<PizzaCrust> getLagerpcrust();
        vector<PizzaExtras> getLagerpextras();
        vector<PizzaLocations> getLagerplocations();
        vector<PizzaMenu> getLagerpMenu();
        vector<PizzaSize> getLagerpsize();
        vector<PizzaToppings> getLagerptoppings();
        vector<Pizza> getOrder();
        client getClient();

        friend ostream& operator <<(ostream& outs, Sala& s);

    private:
        Pizza lager;

        client newCustomer;

        /**
        * @param order Customer orders are stored on this vector. When customer options for a another pizza
        * the former order is pushed back on this vector
        */
        vector<Pizza> order;

        /**
        * @param pHelper A helper vector storing quantity of all items on a single order
        */
        vector<PizzaHelper> pHelper;
};

#endif // SALA_H
