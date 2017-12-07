#ifndef BAKERUI_H
#define BAKERUI_H

#include "Baker.h"
#include <cstdlib>

class BakerUI
{
    public:
        BakerUI();
        virtual ~BakerUI();

        void main();

        void displayClient();

    private:
        template<typename Pizzaclass>
        void displayVector(vector<Pizzaclass> vec, bool choice);
};

#endif // BAKERUI_H
