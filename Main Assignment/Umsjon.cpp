#include "Umsjon.h"

Umsjon::Umsjon()
{
}

Umsjon::~Umsjon()
{
    //dtor
}

void Umsjon::enterPizzaSize()
{
    Pizza p;
    pair <char[32], int> tempPair;
    cout << "enter pizza size" << endl;
    cin >> tempPair.first;
    cout << "enter prize of pizza" << endl;
    cin >> tempPair.second;
    p.menuSize.push_back(tempPair);
}

void Umsjon::print()
{}

void Umsjon::enterCrust(){

    pair <char[32],int> par;

    cout << "What kind of crust do you want: ";
    cin >> par.first;
}

void Umsjon::enterToppings(){
    pair <char[32],int> par;
    cout << "Enter toppings. If none press x: ";
    cin >> par.first;
}
