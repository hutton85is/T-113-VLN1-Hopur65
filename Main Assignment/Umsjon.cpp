#include "Umsjon.h"

Umsjon::Umsjon()
{
    ReadWriteClass rw;
    rw.loadAllVectors(lager);
}

<<<<<<< HEAD
=======
Umsjon::~Umsjon()
{

}

>>>>>>> f926114eaccea4974aa372e72f4890ab6b25fabd
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
    ReadWriteClass rw;
    rw.writeClassToFile<PizzaSize>(newSize, fname);
}

void Umsjon::createCrust(char crust_type[32], int price)
{
    PizzaCrust newCrust;

    strcpy(newCrust.crust_type, crust_type);
    newCrust.price = price;

    lager.pcrust.push_back(newCrust);

    const char* fname = "data/crust.dat";
    ReadWriteClass rw;
    rw.writeClassToFile(newCrust, fname);
}

void Umsjon::createToppings(char toppings[32], int price)
{
    PizzaToppings newToppings;

    strcpy(newToppings.toppings, toppings);
    newToppings.price = price;

    lager.ptoppings.push_back(newToppings);

    const char* fname = "data/toppings.dat";
    ReadWriteClass rw;
    rw.writeClassToFile<PizzaToppings>(newToppings, fname);
}

void Umsjon::createMenu(char choose_pizza[32], double price, char toppings[128])
{
    PizzaMenu newMenu;

    strcpy(newMenu.choose_pizza, choose_pizza);
    strcpy(newMenu.toppings, toppings);
    newMenu.price = price;

    cout << toppings << endl;
    cout << newMenu.toppings << endl;
    system("pause");

    lager.pmenu.push_back(newMenu);

    const char* fname = "data/menu.dat";
    ReadWriteClass rw;
    rw.writeClassToFile<PizzaMenu>(newMenu, fname);
}

void Umsjon::createExtras(char extras_type[32], int price)
{
    PizzaExtras newExtra;

    strcpy(newExtra.extras_type, extras_type);
    newExtra.price = price;

    lager.pextras.push_back(newExtra);

    const char* fname = "data/extra.dat";
    ReadWriteClass rw;
    rw.writeClassToFile<PizzaExtras>(newExtra, fname);
}

void Umsjon::createLocation(char place[32])
{
    PizzaLocations newLocation;

    strcpy(newLocation.place, place);

    lager.plocations.push_back(newLocation);

    const char* fname = "data/locations.dat";
    ReadWriteClass rw;
    rw.writeClassToFile<PizzaLocations>(newLocation, fname);
}
