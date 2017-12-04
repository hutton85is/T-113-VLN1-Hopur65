#ifndef UMSJONUI_H
#define UMSJONUI_H

#include <stdlib.h>
#include "Umsjon.h"

class UmsjonUI
{
    public:
        UmsjonUI();
        virtual ~UmsjonUI();
        bool yorn(char answer);
        void main();

    private:
        void addCrust();
        void addToppings();
        void addExtras();
        void addMenu();
        void addLocation();
        void addSize();
};

#endif // UMSJONUI_H
