#include "PizzaExtras.h"

PizzaExtras::PizzaExtras()
{
        price = 0;
        extras_type[0] = '\0';
}

ostream& operator <<(ostream& outs, PizzaExtras& p_extras)
{
    outs << p_extras.extras_type << " : " << p_extras.price;
    return outs;
}
