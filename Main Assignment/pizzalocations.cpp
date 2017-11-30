#include "pizzalocations.h"

PizzaLocations::PizzaLocations()
{
          price = 0;
          pick_up = 0;
    //ctor
}

PizzaLocations::~PizzaLocations()
{
    //dtor
}
ostream& operator <<(ostream& outs, PizzaLocations& p_locations)
{
    outs << p_locations.pick_up << " : "  << endl;
    return outs;
}
