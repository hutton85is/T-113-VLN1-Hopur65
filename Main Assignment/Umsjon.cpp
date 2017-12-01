#include "Umsjon.h"

Umsjon::Umsjon()
{
    lager.loadAllVectors(lager);
}

Umsjon::~Umsjon()
{
    //dtor
}

void Umsjon::enterPizzaSize()
{
    PizzaSize newSize;
    cout << "Enter pizza size: " << endl;
    cin >> newSize.p_size;
    cout << "Enter price of pizza size: " << newSize.p_size << endl;
    cin >> newSize.price;
    lager.psize.push_back(newSize);
    lager.writeSizeVector(newSize);
}

void Umsjon::enterCrust()
{
    PizzaCrust newCrust;
    cout << "What kind of crust do you want: ";
    cin >> newCrust.crust_type;
    cout << "What is the price of " << newCrust.crust_type << ": " << endl;
    cin >> newCrust.price;
    lager.pcrust.push_back(newCrust);
}

void Umsjon::enterToppings()
{
    PizzaToppings newToppings;
    cout << "Enter toppings. If none press x: " << endl;
    cin >> newToppings.toppings;
    cout << "What is the price of " << newToppings.toppings << ": " << endl;
    cin >> newToppings.price;
    lager.ptoppings.push_back(newToppings);
    lager.writeToppingsVector(newToppings);
}

void Umsjon::enterMenu()
{
    PizzaMenu newMenu;
    cout << "Enter a new pizza: " << endl;
    cin >> newMenu.choose_pizza;
    cout << "What is the price of " << newMenu.choose_pizza << ": " << endl;
    cin >> newMenu.price;
    lager.pmenu.push_back(newMenu);
}

void Umsjon::enterExtras()
{
    PizzaExtras newExtra;
    cout << "Enter a new extra: " << endl;
    cin >> newExtra.extras_type;
    cout << "What is the price of " << newExtra.extras_type << endl;
    cin >> newExtra.price;
    lager.pextras.push_back(newExtra);

}

void Umsjon::enterLocation()
{
    PizzaLocations newLocation;

    cout << "Enter new location: ";
    cin >> newLocation.pick_up;
    lager.plocations.push_back(newLocation);
}
