#include "PizzaLocations.h"

PizzaLocations::PizzaLocations()
{
          place[0] = '\0';
          //pick_up = 0;
}

PizzaLocations::~PizzaLocations()
{

}
ostream& operator <<(ostream& outs, PizzaLocations& p_locations)
{
    outs << p_locations.place;
    return outs;
}
