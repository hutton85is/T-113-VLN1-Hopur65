#ifndef PIZZATOPPINGS_H
#define PIZZATOPPINGS_H

#include <iostream>

using namespace std;

class PizzaToppings
{
    public:
        PizzaToppings();
        virtual ~PizzaToppings();

        friend ostream& operator <<(ostream& outs, PizzaToppings& p_toppings);

        int price;
        char toppings[32];

    protected:

    private:
};

#endif // PIZZATOPPINGS_H
