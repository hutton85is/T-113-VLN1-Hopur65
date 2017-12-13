/**
 * @brief Description of pizza topping and price
 *
 */



#ifndef PIZZATOPPINGS_H
#define PIZZATOPPINGS_H

#include <iostream>

using namespace std;

class PizzaToppings
{
    public:

        PizzaToppings();

        friend ostream& operator <<(ostream& outs, PizzaToppings& p_toppings);

        int price;

        char toppings[32];
};

#endif // PIZZATOPPINGS_H
