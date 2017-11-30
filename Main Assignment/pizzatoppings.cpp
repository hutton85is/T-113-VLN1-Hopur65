#include "pizzatoppings.h"

PizzaToppings::PizzaToppings()
{
        price = 0;
        toppings[0] = '\0';
    //ctor
}

PizzaToppings::~PizzaToppings()
{
    //dtor
}
ostream& operator <<(ostream& outs, PizzaToppings& p_toppings)
{
    outs << p_toppings.toppings << " : " << p_toppings.price << endl;
    return outs;
}
