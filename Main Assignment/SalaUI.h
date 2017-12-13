/**
* @brief SalaUI handles all user interface interactions due to selling a pizza
*/

#ifndef SALAUI_H
#define SALAUI_H

#include "Sala.h"
#include <stdlib.h>
#include <windows.h>

#include "Error.h"
#include "UIHelper.h"
#include <climits>


class SalaUI
{
    public:
        SalaUI();

        void mainOrder();

    private:

        void choosePizzaLocation();

        void choosePizzaSize();

        void choosePizzaCrust();

        void choosePizzaTopping();

        void choosePizzaMenu();

        void choosePizzaExtras();

        void chooseDifferentPizzaLocation();

        void finishOrder();

        UIHelper helperUI;

        Sala s;

        /*
        * Display all contents of a template vector
        * vector<Pizzaclass> vec: A template vector storing all classes to display
        * bool choice: if 'choice' is true vector position is also displayed, else not
        */
        template <typename Pizzaclass>
        void displayVector(vector<Pizzaclass> vec, bool choice);
};

#endif // SALAUI_H
