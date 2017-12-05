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

vector<PizzaCrust> Sala::getLagerpcrust()
{
    return lager.pcrust;
}

vector<PizzaExtras> Sala::getLagerpextras()
{
    return lager.pextras;
}

vector<PizzaLocations> Sala::getLagerplocations()
{
    return lager.plocations;
}

vector<PizzaMenu> Sala::getLagerpMenu()
{
    return lager.pmenu;
}

vector<PizzaSize> Sala::getLagerpsize()
{
    return lager.psize;
}

vector<PizzaToppings> Sala::getLagerptoppings()
{
    return lager.ptoppings;
}

vector<PizzaCrust> Sala::getOrderpcrust()
{
    return lager.pcrust;
}

vector<PizzaExtras> Sala::getOrderpextras()
{
    return lager.pextras;
}

vector<PizzaLocations> Sala::getOrderplocations()
{
    return lager.plocations;
}

vector<PizzaMenu> Sala::getOrderpMenu()
{
    return lager.pmenu;
}

vector<PizzaSize> Sala::getOrderpsize()
{
    return lager.psize;
}

vector<PizzaToppings> Sala::getOrderptoppings()
{
    return lager.ptoppings;
}

bool Sala::enterPizzaSize(unsigned int input)
{
    if (input < sizeof(lager.psize) && 0 <= input)
    {
        order.psize.push_back(lager.psize[input]);
        return true;
    }

    return false;
}

bool Sala::enterCrust(unsigned int input)
{
    if (input < sizeof(lager.pcrust) && 0 <= input)
    {
        order.pcrust.push_back(lager.pcrust[input]);
        return true;
    }

    return false;
}

bool Sala::enterToppings(unsigned int input)
{
    if (input < sizeof(lager.ptoppings) && 0 <= input)
    {
        order.ptoppings.push_back(lager.ptoppings[input]);
        return true;
    }

    return false;
}

bool Sala::enterMenu(unsigned int input)
{
    if (input < sizeof(lager.pmenu) && 0 <= input)
    {
        order.pmenu.push_back(lager.pmenu[input]);
        return true;
    }

    return false;
}

bool Sala::enterExtras(unsigned int input)
{
    if (input < sizeof(lager.pextras) && 0 <= input)
    {
        order.pextras.push_back(lager.pextras[input]);
        return true;
    }

    return false;
}

bool Sala::enterLocation(unsigned int input)
{
    if (input < sizeof(lager.plocations) && 0 <= input)
    {
        order.plocations.push_back(lager.plocations[input]);
        return true;
    }

    return false;
}
