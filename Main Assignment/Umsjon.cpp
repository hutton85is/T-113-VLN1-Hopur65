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
    cout << "enter pizza size" << endl;
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
    cout << "What is the price of " << newCrust.crust_type << endl;
    cin >> newCrust.price;
    p.psize.push_back(newCrust);
}

void Umsjon::enterToppings(){

    cout << "Enter toppings. If none press x: ";
    cin >> tempToppings;
    p.setToppings(tempToppings);
}

void Umsjon::enterMenu(){

    cout << "Enter a new pizza: ";
    cin >> tempMenu;
    p.setPizzas(tempMenu);
}

void Umsjon::enterExtras(){


    cout << "Enter a new extra: ";
    cin >> tempExtras;
    p.setExtrax(tempExtras);
}

void Umsjon::enterLocation(){


    cout << "Enter new location: ";
    cin >> tempLocation;
    p.setLocation(tempLocation);
}
