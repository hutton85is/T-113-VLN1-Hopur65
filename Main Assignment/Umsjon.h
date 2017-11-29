#ifndef UMSJON_H
#define UMSJON_H

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Umsjon
{
    public:
        Umsjon();
        virtual ~Umsjon();
        void enterCrust();
        void enterToppings();

<<<<<<< HEAD
        void enterPizzaSize();

        void print();

    protected:

    private:
        Pizza p;
=======

    private:
        //vector <pair <string,int> > pizzaSize;
        vector <pair <char[32],int> > pizzaBotn;
        vector <pair <char[32],int> > alegg;
>>>>>>> c749013cd73b6f96d706b6c6be5416d545ee6ed4
};

#endif // UMSJON_H
