#include "PizzaToppings.h"

PizzaToppings::PizzaToppings()
{
        price = 0;
        toppings[0] = '\0';
}

PizzaToppings::~PizzaToppings()
{

}
ostream& operator <<(ostream& outs, PizzaToppings& p_toppings)
{
    outs << p_toppings.toppings << " : " << p_toppings.price;
    return outs;
}
