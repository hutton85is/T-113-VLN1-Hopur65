#include "Umsjon.h"

Umsjon::Umsjon()
{
    //ctor
}

Umsjon::~Umsjon()
{
    //dtor
}


void Umsjon::enterSize(){

    pair <char[32],int> par;

    cout << "Enter size: ";
    cin >> par.first;
    cout << "Enter price: ";
    cin >> par.second;
    pizzaSize.push_back(par);
}
void Umsjon::enterCrust(){

    pair <char[32],int> par;

    cout << "Enter crust: ";
    cin >> par.first;
    cout << "Enter price: ";
    cin >> par.second;
    pizzaBotn.push_back(par);
}

void Umsjon::enterToppings(){

    pair <char[32],int> par;

    cout << "Enter toppings. If none press x: ";
    cin >> par.first;
    cout << "Enter price: ";
    cin >> par.second;
    pizzaToppings.push_back(par);
}

void Umsjon::enterMenu(){

    pair <char[32],int> par(){

    cout << "Enter pizza name: ";


    }

}


