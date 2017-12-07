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
<<<<<<< HEAD
        /*
        * Display all contents of a template vector
        * vector<Pizzaclass> vec: A template vector storing all classes to display
        * bool choice: if 'choice' is true vector position is also displayed, else not
=======

        /*
        * display all contents of a vector
        * vector<Pizzaclass vec: is the template vector to display
        * bool choice: is a variable if valid displays its current position in the vector
>>>>>>> 762a064b6398121e3e4b1ec1094165df32ed4269
        */
        template <typename Pizzaclass>
        void displayVector(vector<Pizzaclass> vec, bool choice);

        /*
<<<<<<< HEAD
        * Display all items contained in an order
        * s: contains a copy of Sala used to store the order and customer information
=======
        * A function to display the full order made
        * Sala s: contains the class storing all contents of the order to display
>>>>>>> 762a064b6398121e3e4b1ec1094165df32ed4269
        */
        void displayFullOrder(Sala s);
};

#endif // SALAUI_H
