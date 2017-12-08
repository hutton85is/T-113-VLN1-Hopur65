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

        void displayClientList();

        void pickLocation();

    private:
        template<typename Pizzaclass>
        void displayVector(vector<Pizzaclass> vec, bool choice);

        Baker baker;
};

#endif // BAKERUI_H
