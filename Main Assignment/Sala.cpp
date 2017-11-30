#include "Sala.h"

Sala::Sala()
{
    //ctor
}

Sala::~Sala()
{
    //dtor
}

void Sala::enterPizzaSize()
{
    cout << "What size do you want? " << endl;
    p.displayVector(p.menuSize);
    cin >> p.setSize;
}

void Sala::enterCrust(){

    cout << "What kind of crust would you like? ";
    p.displayVector(p.menuCrust);
    cin >> p.setCrust;
}

void Sala::enterToppings(){

    cout << "Enter toppings. If none press x: ";
    p.displayVector(p.menuToppings);
    cin >> p.setToppings;
}

void Sala::enterMenu(){

    cout << "Check out our menu and choose your pizza";
    p.displayVector(p.menuPizzas);
    cin >> p.setMenu;
}

void Sala::enterExtras(){

    cout << "Would you like any extras? ";
    p.displayVector(p.menuExtras);
    cin >> p.setExtras;
}

void Sala::enterLocation(){

    cout << "Where would you like to pick up your pizza? ";
    p.displayVector(p.menuLocation);
    cin >> p.setLocation;
}

