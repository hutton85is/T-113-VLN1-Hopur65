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

    protected:

    private:
        vector<int, string> pizzaSize;
};

#endif // UMSJON_H
