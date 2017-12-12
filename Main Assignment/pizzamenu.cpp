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
    if(p_menu.choose_pizza[0] != '\0')
    {
        outs << p_menu.choose_pizza << " : " << p_menu.price;
        if(p_menu.toppings[0] != '\0')
        {
            outs << endl;
            outs << p_menu.toppings;
        }
    }
    return outs;
}


