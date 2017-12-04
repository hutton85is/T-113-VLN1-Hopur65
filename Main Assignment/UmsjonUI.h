#ifndef UMSJONUI_H
#define UMSJONUI_H

#include "Umsjon.h"
#include <stdlib.h>


class UmsjonUI
{
    public:
        UmsjonUI();
        virtual ~UmsjonUI();
        bool yorn(char answer);
        void main();

    private:
        template <typename Pizzaclass>
        void displayVector(vector<Pizzaclass> vec);
};

#endif // UMSJONUI_H
