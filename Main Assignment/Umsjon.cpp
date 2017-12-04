#include "Umsjon.h"

Umsjon::Umsjon()
{
    lager.loadAllVectors(lager);
}

Umsjon::~Umsjon()
{
    //dtor
}

void Umsjon::createPizzaSize()
{
    PizzaSize newSize;
    for(unsigned int i = 0; i < lager.psize.size();i++){
        cout << i << " : ";
        cout << lager.psize[i].p_size << " " << lager.psize[i].price << endl;
    }
    cout << endl;
    cout << "Enter new pizza size: ";
    cin >> newSize.p_size;
    cout << "Enter price of " << newSize.p_size << " size: ";
    cin >> newSize.price;

    lager.psize.push_back(newSize);

    const char* fname = "data/size.dat";
    lager.writeClassToFile<PizzaSize>(newSize, fname);
}

void Umsjon::createCrust()
{
    PizzaCrust newCrust;
    for(unsigned int i = 0; i < lager.pcrust.size();i++){
        cout << i << " : ";
        cout << lager.pcrust[i].crust_type << " " << lager.pcrust[i].price;
    }
    cout << endl;
    cout << "What kind of crust do you want to add: ";
    cin >> newCrust.crust_type;
    cout << "What is the price of " << newCrust.crust_type << ": ";
    cin >> newCrust.price;

    lager.pcrust.push_back(newCrust);

    const char* fname = "data/crust.dat";
    lager.writeClassToFile<PizzaCrust>(newCrust, fname);
}

void Umsjon::createToppings()
{
    PizzaToppings newToppings;
    for(unsigned int i = 0; i < lager.ptoppings.size();i++){
        cout << i << " : ";
        cout << lager.ptoppings[i].toppings << " " << lager.ptoppings[i].price << endl;
    }
    cout << endl;
    cout << "Enter new topping ";
    cin >> newToppings.toppings;
    cout << "What is the price of " << newToppings.toppings << ": ";
    cin >> newToppings.price;

    lager.ptoppings.push_back(newToppings);

    const char* fname = "data/toppings.dat";
    lager.writeClassToFile<PizzaToppings>(newToppings, fname);
}

void Umsjon::createMenu()
{
    PizzaMenu newMenu;
    for(unsigned int i = 0; i < lager.pmenu.size();i++){
        cout << i << " : ";
        cout << lager.pmenu[i].choose_pizza << " " << lager.pmenu[i].price << endl;
    }
    cout << endl;
    cout << "Enter a new pizza to the menu: ";
    cin >> newMenu.choose_pizza;
    cout << "What is the price of " << newMenu.choose_pizza << " pizza: ";
    cin >> newMenu.price;

    lager.pmenu.push_back(newMenu);

    const char* fname = "data/menu.dat";
    lager.writeClassToFile<PizzaMenu>(newMenu, fname);
}

void Umsjon::createExtras()
{
    PizzaExtras newExtra;
    for(unsigned int i = 0; i < lager.pextras.size();i++){
        cout << i << " : ";
        cout << lager.pextras[i].extras_type << " " << lager.pextras[i].price << endl;
    }
    cout << endl;
    cout << "Enter a new extra: ";
    cin >> newExtra.extras_type;
    cout << "What is the price of " << newExtra.extras_type << ": ";
    cin >> newExtra.price;

    lager.pextras.push_back(newExtra);

    const char* fname = "data/extra.dat";
    lager.writeClassToFile<PizzaExtras>(newExtra, fname);
}

void Umsjon::createLocation()
{
    PizzaLocations newLocation;
    for(unsigned int i = 0; i < lager.plocations.size();i++){
        cout << i << " : ";
        cout << lager.plocations[i].place << endl;
    }
    cout << endl;
    cout << "Enter new location: ";
    cin >> newLocation.place;

    lager.plocations.push_back(newLocation);

    const char* fname = "data/locations.dat";
    lager.writeClassToFile<PizzaLocations>(newLocation, fname);
}
