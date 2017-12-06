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
        bool yorn(char answer);
        void mainOrder();

    private:

        /*
        * display all contents of a vector
        * vector<Pizzaclass vec: is the template vector to display
        * bool choice: is a variable if valid displays its current position in the vector
        */
        template <typename Pizzaclass>
        void displayVector(vector<Pizzaclass> vec, bool choice);

        /*
        * A function to display the full order made
        * Sala s: contains the class storing all contents of the order to display
        */
        void displayFullOrder(Sala s);
};

#endif // SALAUI_H
