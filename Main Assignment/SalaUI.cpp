#include "SalaUI.h"

SalaUI::SalaUI()
{
    //ctor
}

SalaUI::~SalaUI()
{
    //dtor
}

bool SalaUI::yorn(char answer){

    return answer == 'y';
}

void SalaUI::mainOrder(){

    char input = 'y';

    while(true){
        cout << "Press 1 to choose your pizza size: ";
        cout << "Press 2 to choose your crust: ";
        cout << "Press 3 to choose toppings: ";
        cout << "Press 4 to choose a pizza from the menu: ";
        cout << "Press 5 to choose extras: ";
        cout << "Press 6 to choose location: ";


        Sala s;
        if(input == 1){
            s.enterPizzaSize();
        }
        if(input == 2){
            s.enterCrust();
        }
        if(input == 3){
            s.enterToppings();
        }
        if(input == 4){
            s.enterMenu();
        }
        if(input == 5){
            s.enterExtras();
        }
        if(input == 6){
            s.enterLocation();
        }
    }
}


