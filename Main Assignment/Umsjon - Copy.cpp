#include "Umsjon.h"

Umsjon::Umsjon()
{
}

Umsjon::~Umsjon()
{
    //dtor
}

void Umsjon::enterPizzaSize(Pizza& p)
{
    pair <char[32], int> tempPair;
    cout << "enter pizza size" << endl;
    cin >> tempPair.first;
    cout << "enter prize of pizza" << endl;
    cin >> tempPair.second;
    p.menuSize.push_back(tempPair);
}


void Umsjon::enterCrust(Pizza& p){

    pair <char[32],int> tempPair;
    cout << "What kind of crust do you want: ";
    cin >> tempPair.first;
    cout << "Enter price: ";
    cin >> tempPair.second;
    p.menuCrust.push_back(tempPair);
}

void Umsjon::enterToppings(Pizza& p){

    pair <char[32],int> tempPair;
    cout << "Enter toppings. If none press x: ";
    cin >> tempPair.first;
    cout << "Enter price: ";
    cin >> tempPair.second;
    p.menuToppings.push_back(tempPair);
    p.writeFile(p);
}

void Umsjon::enterMenu(Pizza& p){

    pair <char[32],int> tempPair;
    cout << "Enter a new pizza: ";
    cin >> tempPair.first;
    cout << "Enter price: ";
    cin >> tempPair.second;
    p.menuPizzas.push_back(tempPair);
}

void Umsjon::enterExtras(Pizza& p){

    pair <char[32],int> tempPair;
    cout << "Enter a new extra: ";
    cin >> tempPair.first;
    cout << "Enter price: ";
    cin >> tempPair.second;
    p.menuExtras.push_back(tempPair);
}

void Umsjon::enterLocation(Pizza& p){

    pair <char[32],int> tempPair;
    cout << "Enter new location: ";
    cin >> tempPair.first;
    cout << "Enter price: ";
    cin >> tempPair.second;
    p.menuLocation.push_back(tempPair);
}
