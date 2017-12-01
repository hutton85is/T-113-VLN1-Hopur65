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


<<<<<<< HEAD
    protected:
=======
>>>>>>> 8bdcee357f086540e6c22a3b0bd1ab7b5e2bfb3a

    private:
};

#endif // PIZZAMENU_H
