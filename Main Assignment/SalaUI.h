#ifndef SALAUI_H
#define SALAUI_H

#include "Sala.h"
#include <stdlib.h>


class SalaUI
{
    public:
        SalaUI();
        virtual ~SalaUI();
        bool yorn(char answer);
        void mainOrder();

    private:
};

#endif // SALAUI_H
