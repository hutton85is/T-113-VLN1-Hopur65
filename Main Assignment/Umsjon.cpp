#include "Umsjon.h"

Umsjon::Umsjon()
{
}

Umsjon::~Umsjon()
{
    //dtor
}

void Umsjon::enterPizzaSize(char tmpSize[32], int tmpprice)
{
    cout << "enter pizza size" << endl;
    cin >> tempSize;
    p.setSize(tempSize);
}

void Umsjon::enterCrust(char tmpSize[32], int tmpprice){

    cout << "What kind of crust do you want: ";
    cin >> tempCrust;
    p.setCrust(tempCrust);
}

void Umsjon::enterToppings(char tmpSize[32], int tmpprice){

    cout << "Enter toppings. If none press x: ";
    cin >> tempToppings;
    p.setToppings(tempToppings);
}

void Umsjon::enterMenu(char tmpSize[32], int tmpprice){

    cout << "Enter a new pizza: ";
    cin >> tempMenu;
    p.setPizzas(tempMenu);
}

void Umsjon::enterExtras(char tmpSize[32], int tmpprice){

    cout << "Enter a new extra: ";
    cin >> tempExtras;
    p.setExtrax(tempExtras);
}

void Umsjon::enterLocation(char tmpSize[32], int tmpprice){

    cout << "Enter new location: ";
    cin >> tempLocation;
    p.setLocation(tempLocation);
}
