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
        template <typename Pizzaclass>
        void displayVector(vector<Pizzaclass> vec, bool choice);
        void displayFullOrder(Sala s);
};

#endif // SALAUI_H
