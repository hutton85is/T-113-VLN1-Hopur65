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
        * Return true if input is valid.
        * Return false if input is invalid.
        */
        bool enterPizzaSize(unsigned int input);
        bool enterCrust(unsigned int input);
        bool enterToppings(unsigned int input);
        bool enterMenu(unsigned int input);
        bool enterExtras(unsigned int input);
        bool enterLocation(unsigned int input);

        /* Create the order by writing it to a file
        * string name: is the name of the person creating the order and will be the name of the file storing the order
        * string address: is the address of the person making the order
        * int number: is the address number for the person making the order
        * return true if writing the order is successful else return false
        */
        bool createOrder(string name, string address, int number);

        /*
        * Load customer if he still has an undelivered order
        * const char* fname: path and filename to the order
        */
        void getCustomer(const char* fname);

        /*
        * Get functions used to retrieve from Pizza class a copy of corresponding vector, and return it to the UI
        */
        vector<PizzaCrust> getLagerpcrust();
        vector<PizzaExtras> getLagerpextras();
        vector<PizzaLocations> getLagerplocations();
        vector<PizzaMenu> getLagerpMenu();
        vector<PizzaSize> getLagerpsize();
        vector<PizzaToppings> getLagerptoppings();

        vector<PizzaCrust> getOrderpcrust();
        vector<PizzaExtras> getOrderpextras();
        vector<PizzaLocations> getOrderplocations();
        vector<PizzaMenu> getOrderpMenu();
        vector<PizzaSize> getOrderpsize();
        vector<PizzaToppings> getOrderptoppings();

        friend ostream& operator <<(ostream& outs, Sala& s);

    private:
        // variable lager contains all items available to sell
        // variable order contains all items a customer has ordered
        Pizza lager, order;

        client newCustomer;
};

#endif // SALA_H
