/**
* @brief Class that handles all user interface interactions due to selling a pizza
*
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

        void displayOrder();

        UIHelper helperUI;

        Sala s;

        template <typename Pizzaclass>
        void displayVector(vector<Pizzaclass> vec, bool choice);
};

#endif // SALAUI_H
