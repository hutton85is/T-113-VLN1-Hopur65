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

        int input;

        cout << "Press 1 to choose your pizza size " << endl;
        cout << "Press 2 to choose your crust " << endl;
        cout << "Press 3 to choose toppings " << endl;
        cout << "Press 4 to choose a pizza from the menu " << endl;
        cout << "Press 5 to choose extras " << endl;
        cout << "Press 6 to choose location " << endl;

        cin >> input;


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


