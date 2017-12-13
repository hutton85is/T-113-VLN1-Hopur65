/**
 * @brief Information on location of a Pizza place
 *
 */



#ifndef PIZZALOCATIONS_H
#define PIZZALOCATIONS_H

#include <iostream>

using namespace std;

class PizzaLocations
{
    public:

        PizzaLocations();

        virtual ~PizzaLocations();

        friend ostream& operator <<(ostream& outs, PizzaLocations& p_locations);

        char place[32];
};

#endif // PIZZALOCATIONS_H
