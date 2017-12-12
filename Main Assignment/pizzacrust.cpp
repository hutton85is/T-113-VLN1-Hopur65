#include "pizzacrust.h"

PizzaCrust::PizzaCrust()
{
        price = 0;
        crust_type[0] = '\0';
}

ostream& operator <<(ostream& outs, PizzaCrust& p_crust)
{
    outs << p_crust.crust_type << " : " << p_crust.price;
    return outs;
}
