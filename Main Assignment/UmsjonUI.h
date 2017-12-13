/**
 * @brief User interface for creating new Pizza items for sale and new Pizza locations
 *
 */


#ifndef UMSJONUI_H
#define UMSJONUI_H

#include "Umsjon.h"
#include <stdlib.h>

#include "UIHelper.h"
#include "Error.h"
#include <climits>


class UmsjonUI
{
    public:

        UmsjonUI();

        void main();

    private:

        template <typename Pizzaclass>
        void displayVector(vector<Pizzaclass> vec, bool show);

        void createNewPizzaSize();

        void createNewPizzaCrust();

        void createNewPizzaTopping();

        void createNewPizzaMenu();

        void createNewPizzaExtras();

        void createNewPizzaLocation();

        UIHelper helperUI;

        Umsjon u;
};

#endif // UMSJONUI_H
