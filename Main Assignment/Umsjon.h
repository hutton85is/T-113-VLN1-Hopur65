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
        vector <pair <char[32],int> > pizzaBotn;
        vector <pair <char[32],int> > alegg;
};

#endif // UMSJON_H
