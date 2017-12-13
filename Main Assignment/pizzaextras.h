/**
 * @brief Information about extras available and price
 *
 */

#ifndef PIZZAEXTRAS_H
#define PIZZAEXTRAS_H

#include <iostream>

using namespace std;

class PizzaExtras
{
    public:

        PizzaExtras();

        friend ostream& operator <<(ostream& outs, PizzaExtras& p_extras);

        int price;

        char extras_type[32];

    private:


};

#endif // PIZZAEXTRAS_H
