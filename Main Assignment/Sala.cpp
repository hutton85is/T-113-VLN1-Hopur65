#include "Sala.h"

Sala::Sala()
{
    lager.loadFile(lager);
}

Sala::~Sala()
{
    //dtor
}

void Sala::enterPizzaSize(){

    PizzaSize = newSize;
    cout << "What size do you want? " << endl;
    cin >> newSize.p_size;
    order.push_back(newSize)
}

void Sala::enterCrust(){

    PizzaCrust = newCrust;
    cout << "What kind of crust would you like? ";
    cin >> newCrust.crust_type;
    order.push_back(newCrust);
}

void Sala::enterToppings(){

    PizzaToppings =newToppings;
    cout << "Enter toppings. If none press x: ";
    cin >> newToppings.p_toppings;
    order.push_back(newToppings);
}

void Sala::enterMenu(){

    PizzaMenu = newMenu;
    cout << "Check out our menu and choose your pizza";
    cin >> newMenu.choose_menu;
    order.push_back(newMenu);
}

void Sala::enterExtras(){

    PizzaExtras = newExtra;
    cout << "Would you like any extras? ";
    cin >> newExtra.extras_type;
    order.push_back(newExtra);
}

void Sala::enterLocation(){

    PizzaLocation = newLocation;
    cout << "Where would you like to pick up your pizza? ";
    cin >> newLocation.pick_up;
    order.push_back(newLocation);
}

