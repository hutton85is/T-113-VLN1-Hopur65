#ifndef UMSJON_H
#define UMSJON_H

#include <iostream>
#include <vector>

using namespace std;

class Umsjon
{
    public:
        Umsjon();
        virtual ~Umsjon();
        void enterCrust();
        void enterToppings();


    private:
        //vector <pair <string,int> > pizzaSize;
        Pizza p;
};

#endif // UMSJON_H
