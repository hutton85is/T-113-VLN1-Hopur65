#ifndef SALAUI_H
#define SALAUI_H

#include "Sala.h"
#include <stdlib.h>
#include <windows.h>

class SalaUI
{
    public:
        SalaUI();
        virtual ~SalaUI();

        void mainOrder();

    private:

        Sala s;

        /*
        * Display all contents of a template vector
        * vector<Pizzaclass> vec: A template vector storing all classes to display
        * bool choice: if 'choice' is true vector position is also displayed, else not
        */
        template <typename Pizzaclass>
        void displayVector(vector<Pizzaclass> vec, bool choice);

        /*
        * Display all items contained in an order
        * s: contains a copy of Sala used to store the order and customer information
        */
        void displayFullOrder(Sala s);
};

#endif // SALAUI_H
