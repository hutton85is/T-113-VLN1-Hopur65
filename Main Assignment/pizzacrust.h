/**
 * @brief Information about pizza crust type and price
 *
 */


#ifndef PIZZACRUST_H
#define PIZZACRUST_H

#include <iostream>

using namespace std;

class PizzaCrust
{
    public:
        PizzaCrust();

        friend ostream& operator <<(ostream& outs, PizzaCrust& p_crust);

        int price;
        char crust_type[32];
};

#endif // PIZZACRUST_H
