#ifndef PIZZAMENU_H
#define PIZZAMENU_H

#include <iostream>

using namespace std;

class PizzaMenu
{
    public:
        PizzaMenu();
        virtual ~PizzaMenu();

        friend ostream& operator <<(ostream& outs, PizzaMenu& p_menu);

        double price;
        char choose_pizza[32];
        char toppings[128];
};

#endif // PIZZAMENU_H
