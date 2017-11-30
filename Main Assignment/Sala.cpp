#include "Sala.h"

Sala::Sala()
{
    lager.loadVectors(lager);
}

Sala::~Sala()
{
    //dtor
}

void Sala::enterPizzaSize(){

    PizzaSize newSize;
    cout << "What size do you want? " << endl;
    cin >> newSize.p_size;
    order.psize.push_back(newSize);
}

void Sala::enterCrust(){

    PizzaCrust newCrust;
    cout << "What kind of crust would you like? ";
    cin >> newCrust.crust_type;
    order.pcrust.push_back(newCrust);
}

void Sala::enterToppings(){

    PizzaToppings newToppings;
    cout << "Enter toppings. If none press x: ";
    cin >> newToppings.toppings;
    order.ptoppings.push_back(newToppings);
}

void Sala::enterMenu(){

    PizzaMenu newMenu;
    cout << "Check out our menu and choose your pizza";
    cin >> newMenu.choose_pizza;
    order.pmenu.push_back(newMenu);
}

void Sala::enterExtras(){

    PizzaExtras newExtra;
    cout << "Would you like any extras? ";
    cin >> newExtra.extras_type;
    order.pextras.push_back(newExtra);
}

void Sala::enterLocation(){

    PizzaLocations newLocation;
    cout << "Where would you like to pick up your pizza? ";
    cin >> newLocation.pick_up;
    order.plocations.push_back(newLocation);
}

