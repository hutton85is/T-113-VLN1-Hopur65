#include "Pizza.h"

Pizza::Pizza()
{
}

Pizza::~Pizza()
{
    //dtor
}


int Pizza::calculateSumOfOrder()
{
    int returnSum = 0;
    if(psize.size())
    {
        returnSum += psize[0].price;
    }

    if(pcrust.size())
    {
        returnSum += pcrust[0].price;
    }

    for(unsigned int i = 0; i < ptoppings.size(); i++)
    {
        returnSum += ptoppings[i].price;
    }

    for(unsigned int i = 0; i < pextras.size(); i++)
    {
        returnSum += pextras[i].price;
    }

    return returnSum;
}

ostream& operator <<(ostream& out, Pizza& p)
{
    for(unsigned int i = 0; i < p.psize.size(); i++)
    {
        out << "    " << p.psize[i] << " kr." << endl;
    }

    for(unsigned int i = 0; i < p.pmenu.size(); i++)
    {
        out << "    " << "Pizza " << p.pmenu[i] << endl;
    }

    for(unsigned int i = 0; i < p.pcrust.size(); i++)
    {
        out << "    " << p.pcrust[i] << " kr." << endl;
    }

    for(unsigned int i = 0; i < p.ptoppings.size(); i++)
    {
        out << "    " << p.ptoppings[i] << " kr." << endl;
    }

    for(unsigned int i = 0; i < p.pextras.size(); i++)
    {
        out << "    " << p.pextras[i] << " kr." << endl;
    }

    return out;
}
