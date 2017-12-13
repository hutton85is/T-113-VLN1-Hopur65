/**
* @brief Sala handles functionality for SalaUI
*
*/

#ifndef SALA_H
#define SALA_H

#include "Pizza.h"
#include "PizzaSize.h"
#include "PizzaToppings.h"
#include "PizzaCrust.h"
#include "PizzaExtras.h"
#include "PizzaLocations.h"
#include "PizzaMenu.h"
#include "ReadWriteClass.h"
#include "Client.h"
#include <cstring>
#include <stdlib.h>

class Sala
{
    public:
        /**
        * @brief Constructor initiates vector variable lager with everything available for ordering on a pizza
        *
        */
        Sala();

        /**
         * @brief All enter functions push items selected by customer to order vector
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
        * @brief Initiate a new Pizza order and push back former order to vector order
        *
        */
        void newPizza();

        void calculateSumOfOrder();

        /**
        * @brief Write client and pizza order to file, and client to a directory containing a list of customers
        *
        * @param name is customers name
        * @param address is customers address
        * @param number is customers address number
        * @param paid is true if order is paid, else false
        * @param delivery is true if customer wants a delivery, else false
        * @param comment is customer comment to follow with the order
        */
        void createOrder(string name, string address, int number, bool paid, bool delivery, string comment);

        Client getCustomerOrdersVector();

        vector<PizzaCrust> getLagerpcrust();

        vector<PizzaExtras> getLagerpextras();

        vector<PizzaLocations> getLagerplocations();

        vector<PizzaMenu> getLagerpMenu();

        vector<PizzaSize> getLagerpsize();

        vector<PizzaToppings> getLagerptoppings();

        vector<Pizza> getOrder();

        Client getClient();

        friend ostream& operator <<(ostream& outs, Sala& s);

    private:

        Pizza lager;

        Client newCustomer;

        vector<Pizza> order;

        vector<PizzaHelper> pHelper;
};

#endif // SALA_H
