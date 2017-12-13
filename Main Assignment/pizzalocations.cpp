#include "PizzaLocations.h"

PizzaLocations::PizzaLocations()
{
          place[0] = '\0';
}

ostream& operator <<(ostream& outs, PizzaLocations& p_locations)
{
    outs << p_locations.place;
    return outs;
}
