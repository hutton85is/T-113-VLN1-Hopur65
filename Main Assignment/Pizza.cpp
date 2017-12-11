#include "Pizza.h"

Pizza::Pizza()
{
}

Pizza::~Pizza()
{
    //dtor
}

ostream& operator <<(ostream& out, Pizza& p)
{
    for(unsigned int i = 0; i < p.plocations.size(); i++)
    {
        out << p.plocations[i] << endl;
    }

    for(unsigned int i = 0; i < p.psize.size(); i++)
    {
        out << p.psize[i] << " kr." << endl;
    }

    for(unsigned int i = 0; i < p.pmenu.size(); i++)
    {
        out << p.pmenu[i] << " kr." << endl;
    }

    for(unsigned int i = 0; i < p.pcrust.size(); i++)
    {
        out << p.pcrust[i] << " kr." << endl;
    }

    for(unsigned int i = 0; i < p.ptoppings.size(); i++)
    {
        out << p.ptoppings[i] << " kr." << endl;
    }

    for(unsigned int i = 0; i < p.pextras.size(); i++)
    {
        out << p.pextras[i] << " kr." << endl;
    }

    return out;
}
