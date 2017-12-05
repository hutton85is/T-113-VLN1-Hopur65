#include "Umsjon.h"

Umsjon::Umsjon()
{
    lager.loadAllVectors(lager);
}

Umsjon::~Umsjon()
{
    //dtor
}

vector<PizzaCrust> Umsjon::getpcrust()
{
    return lager.pcrust;
}

vector<PizzaExtras> Umsjon::getpextras()
{
    return lager.pextras;
}

vector<PizzaLocations> Umsjon::getplocations()
{
    return lager.plocations;
}

vector<PizzaMenu> Umsjon::getpMenu()
{
    return lager.pmenu;
}

vector<PizzaSize> Umsjon::getpsize()
{
    return lager.psize;
}

vector<PizzaToppings> Umsjon::getptoppings()
{
    return lager.ptoppings;
}

void Umsjon::createPizzaSize(char p_size[32], int price)
{
    PizzaSize newSize;

    strcpy (newSize.p_size, p_size);
    newSize.price = price;

    lager.psize.push_back(newSize);

    const char* fname = "data/size.dat";
    lager.writeClassToFile<PizzaSize>(newSize, fname);
}

void Umsjon::createCrust(char crust_type[32], int price)
{
    PizzaCrust newCrust;

    strcpy(newCrust.crust_type, crust_type);
    newCrust.price = price;

    lager.pcrust.push_back(newCrust);

    const char* fname = "data/crust.dat";
    lager.writeClassToFile<PizzaCrust>(newCrust, fname);
}

void Umsjon::createToppings(char toppings[32], int price)
{
    PizzaToppings newToppings;

    strcpy(newToppings.toppings, toppings);
    newToppings.price = price;

    lager.ptoppings.push_back(newToppings);

    const char* fname = "data/toppings.dat";
    lager.writeClassToFile<PizzaToppings>(newToppings, fname);
}

void Umsjon::createMenu(char choose_pizza[32], int price)
{
    PizzaMenu newMenu;

    strcpy(newMenu.choose_pizza, choose_pizza);
    newMenu.price = price;

    lager.pmenu.push_back(newMenu);

    const char* fname = "data/menu.dat";
    lager.writeClassToFile<PizzaMenu>(newMenu, fname);
}

void Umsjon::createExtras(char extras_type[32], int price)
{
    PizzaExtras newExtra;

    strcpy(newExtra.extras_type, extras_type);
    newExtra.price = price;

    lager.pextras.push_back(newExtra);

    const char* fname = "data/extra.dat";
    lager.writeClassToFile<PizzaExtras>(newExtra, fname);
}

void Umsjon::createLocation(char place[32])
{
    PizzaLocations newLocation;

    strcpy(newLocation.place, place);

    lager.plocations.push_back(newLocation);

    const char* fname = "data/locations.dat";
    lager.writeClassToFile<PizzaLocations>(newLocation, fname);
}
