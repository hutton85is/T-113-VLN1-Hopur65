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
        bool pick_up;

    private:
};

#endif // PIZZALOCATIONS_H
