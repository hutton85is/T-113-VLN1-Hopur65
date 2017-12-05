#include "Sala.h"

Sala::Sala()
{
    readWriteClass rw;
    rw.loadAllVectors(lager);
}

Sala::~Sala()
{
    //dtor
}

vector<PizzaCrust> Sala::getpcrust()
{
    return lager.pcrust;
}

vector<PizzaExtras> Sala::getpextras()
{
    return lager.pextras;
}

vector<PizzaLocations> Sala::getplocations()
{
    return lager.plocations;
}

vector<PizzaMenu> Sala::getpMenu()
{
    return lager.pmenu;
}

vector<PizzaSize> Sala::getpsize()
{
    return lager.psize;
}

vector<PizzaToppings> Sala::getptoppings()
{
    return lager.ptoppings;
}

bool Sala::enterPizzaSize(unsigned int input)
{
    if (input < sizeof(lager.psize) && 0 <= input)
    {
        order.psize.push_back(lager.psize[input]);
        readWriteClass rw;
        rw.writeClassToFile(lager.psize[input],"Order/psize.dat");
        return true;
    }

    return false;
}

bool Sala::enterCrust(unsigned int input)
{
    if (input < sizeof(lager.pcrust) && 0 <= input)
    {
        order.pcrust.push_back(lager.pcrust[input]);
        readWriteClass rw;
        rw.writeClassToFile(lager.pcrust[input],"Order/pcrust.dat");
        return true;
    }

    return false;
}

bool Sala::enterToppings(unsigned int input)
{
    if (input < sizeof(lager.ptoppings) && 0 <= input)
    {
        order.ptoppings.push_back(lager.ptoppings[input]);
        readWriteClass rw;
        rw.writeClassToFile(lager.ptoppings[input],"Order/ptoppings.dat");
        return true;
    }

    return false;
}

bool Sala::enterMenu(unsigned int input)
{
    if (input < sizeof(lager.pmenu) && 0 <= input)
    {
        order.pmenu.push_back(lager.pmenu[input]);
        readWriteClass rw;
        rw.writeClassToFile(lager.pmenu[input],"Order/pmenu.dat");
        return true;
    }

    return false;
}

bool Sala::enterExtras(unsigned int input)
{
    if (input < sizeof(lager.pextras) && 0 <= input)
    {
        order.pextras.push_back(lager.pextras[input]);
        readWriteClass rw;
        rw.writeClassToFile(lager.pextras[input],"Order/pextras.dat");
        return true;
    }

    return false;
}

bool Sala::enterLocation(unsigned int input)
{
    if (input < sizeof(lager.plocations) && 0 <= input)
    {
        order.plocations.push_back(lager.plocations[input]);
        readWriteClass rw;
        rw.writeClassToFile(lager.plocations[input],"Order/plocations.dat");
        return true;
    }

    return false;
}
