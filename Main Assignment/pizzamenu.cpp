#include "pizzamenu.h"

PizzaMenu::PizzaMenu()
{
         price = 0;
         choose_pizza[0] = '\0';
         toppings[0] = '\0';

    //ctor
}

PizzaMenu::~PizzaMenu()
{
    //dtor
}
ostream& operator <<(ostream& outs, PizzaMenu& p_menu)
{
    outs << p_menu.choose_pizza << " : " << p_menu.price;
    outs << endl;
    outs << p_menu.toppings;
    return outs;
}


