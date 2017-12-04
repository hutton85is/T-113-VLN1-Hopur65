#include "Sala.h"

Sala::Sala()
{
    lager.loadAllVectors(lager);
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

bool Sala::enterPizzaSize(int input)
{
    if (input < sizeof(lager.psize) && -1 < input)
    {
        order.psize.push_back(lager.psize[input]);
        return true;
    }

    return false;
}

bool Sala::enterCrust(int input)
{
    if (input < sizeof(lager.pcrust) && -1 < input)
    {
        order.pcrust.push_back(lager.pcrust[input]);
        return true;
    }

    return false;
}

bool Sala::enterToppings(int input)
{
    if (input < sizeof(lager.ptoppings) && -1 < input)
    {
        order.ptoppings.push_back(lager.ptoppings[input]);
        return true;
    }

    return false;
}

bool Sala::enterMenu(int input)
{
    if (input < sizeof(lager.pmenu) && -1 < input)
    {
        order.pmenu.push_back(lager.pmenu[input]);
        return true;
    }

    return false;
}

bool Sala::enterExtras(int input)
{
    if (input < sizeof(lager.pextras) && -1 < input)
    {
        order.pextras.push_back(lager.pextras[input]);
        return true;
    }

    return false;
}

bool Sala::enterLocation(int input)
{
    if (input < sizeof(lager.plocations) && -1 < input)
    {
        order.plocations.push_back(lager.plocations[input]);
        return true;
    }

    return false;
}



