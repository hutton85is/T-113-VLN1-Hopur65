#include "pizzaextras.h"

PizzaExtras::PizzaExtras()
{
        price = 0;
        extras_type[0] = '\0';
    //ctor
}

PizzaExtras::~PizzaExtras()
{
    //dtor
}
ostream& operator <<(ostream& outs, PizzaExtras& p_extras)
{
    outs << p_extras.extras_type << " : " << p_extras.price << endl;
    return outs;
}
