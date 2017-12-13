/**
 * @brief A helper class to store count of items on a single pizza order
 *
 *
 */



#ifndef PIZZAHELPER_H
#define PIZZAHELPER_H

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
