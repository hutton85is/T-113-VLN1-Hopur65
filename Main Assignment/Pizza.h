#ifndef PIZZA_H
#define PIZZA_H

<<<<<<< HEAD
#include <vector>
#include <iostream>
#include <utility>
=======
#include <iostream>
#include <vector>
#include <utility>

using namespace std;
>>>>>>> 365c2446da153555747210bf1228738c20142678

class Pizza
{
    public:
        Pizza();
        virtual ~Pizza();

        vector <pair <char[32], int> > menuSize;
        vector <pair <char[32], int> > menuToppings;
        vector <pair <char[32], int> > menuCrust;
        vector <pair <char[32], int> > menuExtras;
        vector <pair <char[32], int> > menuPizzas;
        vector <pair <char[32], int> > menuLocation;

    protected:

    private:
};

#endif // PIZZA_H
