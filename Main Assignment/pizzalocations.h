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

        int price;
        bool pick_up;

    protected:

    private:
};

#endif // PIZZALOCATIONS_H
