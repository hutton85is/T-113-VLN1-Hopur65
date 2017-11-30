#ifndef PIZZAMENU_H
#define PIZZAMENU_H

#include <iostream>

using namespace std;

class PizzaMenu
{
    public:
        PizzaMenu();
        virtual ~PizzaMenu();

        friend ostream& operator <<(ostream& outs, PizzaMenu& p_menu);

        int price;
        char choose_pizza[32];

    protected:

    private:
};

#endif // PIZZAMENU_H
