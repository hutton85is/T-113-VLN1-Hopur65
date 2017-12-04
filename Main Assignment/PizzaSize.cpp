#include "PizzaSize.h"

PizzaSize::PizzaSize()
{
        price = 0;
        p_size[0] = '\0';
    //ctor
}

PizzaSize::~PizzaSize()
{
    //dtor
}
ostream& operator <<(ostream& outs, PizzaSize& p_size)
{
    outs << p_size.p_size << " : " << p_size.price;
    return outs;
}
