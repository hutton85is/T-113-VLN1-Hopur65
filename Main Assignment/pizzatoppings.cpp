#include "PizzaToppings.h"

PizzaToppings::PizzaToppings()
{
        price = 0;
        toppings[0] = '\0';
}

<<<<<<< HEAD
=======
PizzaToppings::~PizzaToppings()
{

}
>>>>>>> f926114eaccea4974aa372e72f4890ab6b25fabd
ostream& operator <<(ostream& outs, PizzaToppings& p_toppings)
{
    outs << p_toppings.toppings << " : " << p_toppings.price;
    return outs;
}
