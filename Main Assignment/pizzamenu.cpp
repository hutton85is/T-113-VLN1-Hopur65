#include "PizzaMenu.h"

PizzaMenu::PizzaMenu()
{
         price = 0;
         choose_pizza[0] = '\0';
         toppings[0] = '\0';
}

PizzaMenu::~PizzaMenu()
{

}
ostream& operator <<(ostream& outs, PizzaMenu& p_menu)
{
    outs << p_menu.choose_pizza << " : " << p_menu.toppings;
    return outs;
}


