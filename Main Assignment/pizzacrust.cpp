#include "pizzacrust.h"

PizzaCrust::PizzaCrust()
{
        price = 0;
        crust_type[0] = '\0';
    //ctor
}

PizzaCrust::~PizzaCrust()
{
    //dtor
}

ostream& operator <<(ostream& outs, PizzaCrust& p_crust)
{
    outs << p_crust.crust_type << " : " << p_crust.price << endl;
    return outs;
}
