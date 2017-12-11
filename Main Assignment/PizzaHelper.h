#ifndef PIZZAHELPER_H
#define PIZZAHELPER_H
/*
* This is a helper class for Pizza class. It stores how many items are in each vector for reading them out of a binary file
*/

class PizzaHelper
{
    public:
        PizzaHelper();
        virtual ~PizzaHelper();

        unsigned int crustCounter;
        unsigned int toppingsCounter;
        unsigned int extrasCounter;
        unsigned int menuCounter;
        unsigned int locationCounter;
        unsigned int sizeCounter;
};

#endif // PIZZAHELPER_H
