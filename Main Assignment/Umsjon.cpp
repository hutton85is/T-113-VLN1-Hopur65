#include "Umsjon.h"

Umsjon::Umsjon()
{
    //ctor
}

Umsjon::~Umsjon()
{
    //dtor
}

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
}
