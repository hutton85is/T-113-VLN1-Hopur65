#ifndef UMSJON_H
#define UMSJON_H

#include <typeinfo>

#include "Pizza.h"

using namespace std;

class Umsjon
{
    public:
        Umsjon();
        virtual ~Umsjon();
        void createCrust();
        void createToppings();
        void createPizzaSize();
        void createMenu();
        void createExtras();
        void createLocation();

        /*
        * A template function that returns a copy of a vector of type pizzaClass, from class 'Pizza'
        */
        template<typename pizzaClass>
        void getVector(vector<pizzaClass>& vec);
        //vector<pizzaClass> getVector(pizzaClass tempClass);

    private:
        Pizza lager;
        void loaderDummy();

};

#endif // UMSJON_H
