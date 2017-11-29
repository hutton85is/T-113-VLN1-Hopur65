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
        void enterSize();
        void enterCrust();
        void enterToppings();


    private:
        Pizza p;


#endif // UMSJON_H
