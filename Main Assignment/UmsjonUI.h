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
        virtual ~UmsjonUI();
        bool yorn(char answer);
        void main();

    private:
        template <typename Pizzaclass>
        void displayVector(vector<Pizzaclass> vec, bool show);

        UIHelper helperUI;
};

#endif // UMSJONUI_H
