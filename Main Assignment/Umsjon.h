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

        void enterPizzaSize();

        void print();

    protected:

    private:
        Pizza p;
};

#endif // UMSJON_H
