#include "Umsjon.h"

Umsjon::Umsjon()
{
}

Umsjon::~Umsjon()
{
    //dtor
}

<<<<<<< HEAD
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
{
    cout << menuSize[0].first << endl;
    cout << menuSize[0].second << endl;
=======
void Umsjon::enterCrust(){

    pair <char[32],int> par;

    cout << "What kind of crust do you want: ";
    cin >> par.first;
    pizzaBotn.push_back(par);
}

void Umsjon::enterToppings(){

    pair <char[32],int> par;

        while(true){
            cout << "Enter toppings. If none press x: ";
            cin >> par.first;

        if(par.first[0] == 'x'){

            break;
        }
    }
>>>>>>> c749013cd73b6f96d706b6c6be5416d545ee6ed4
}
