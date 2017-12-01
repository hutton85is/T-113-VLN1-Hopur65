#include "Umsjon.h"

Umsjon::Umsjon()
{
    p.loadFile(p);
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
    p.psize.push_back(newSize);
}

void Umsjon::enterCrust()
{
    PizzaCrust newCrust;
    cout << "What kind of crust do you want: ";
    cin >> newCrust.crust_type;
    cout << "What is the price of " << newCrust.crust_type << ": " << endl;
    cin >> newCrust.price;
    p.pcrust.push_back(newCrust);
}

void Umsjon::enterToppings()
{
    PizzaToppings newToppings;
    cout << "Enter toppings. If none press x: " << endl;
    cin >> newToppings.toppings;
    cout << "What is the price of " << newToppings.toppings << ": " << endl;
    cin >> newToppings.price;
    p.ptoppings.push_back(newToppings);
    p.writePizzaToppings(newToppings);

}

void Umsjon::enterMenu()
{
    PizzaMenu newMenu;
    cout << "Enter a new pizza: " << endl;
    cin >> newMenu.choose_pizza;
    cout << "What is the price of " << newMenu.choose_pizza << ": " << endl;
    cin >> newMenu.price;
    p.pmenu.push_back(newMenu);
}

void Umsjon::enterExtras()
{
    PizzaExtras newExtra;
    cout << "Enter a new extra: " << endl;
    cin >> newExtra.extras_type;
    cout << "What is the price of " << newExtra.extras_type << endl;
    cin >> newExtra.price;
    p.pextras.push_back(newExtra);

}

void Umsjon::enterLocation()
{
    PizzaLocations newLocation;
    char yn;

    cout << "Enter new location: ";
    cin >> newLocation.pick_up;
    cout << "Do you want to get your order delivered? y or no? " << endl;
    cin >> yn;
    if ('y' == yn)
    {
     cout << "We will be there soon with your warm pizza!" << endl;
     newLocation.pick_up = 1;
    }
    else
    {
     cout << "You can pick up your delicious pizza at " << newLocation.pick_up << endl;
     newLocation.pick_up = 0;
    }
    p.plocations.push_back(newLocation);
}
