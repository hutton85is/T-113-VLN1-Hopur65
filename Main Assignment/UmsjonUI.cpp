#include "UmsjonUI.h"

UmsjonUI::UmsjonUI()
{

}

UmsjonUI::~UmsjonUI()
{
    //dtor
}

bool UmsjonUI::yorn(char answer){

    return answer == 'y';
}

void UmsjonUI::main(){

    char input = 'y';

    while(true){

        int input;

        cout << "Press 1 to add a new pizza size " << endl;
        cout << "Press 2 to add a new crust " << endl;
        cout << "Press 3 to add a new topping " << endl;
        cout << "Press 4 to add a new pizza to the menu " << endl;
        cout << "Press 5 to add a new extra " << endl;
        cout << "Press 6 to add a new location " << endl;

        cin >> input;

        Umsjon u;
        if(input == 1){
            u.enterPizzaSize();
        }
        if(input == 2){
            u.enterCrust();
        }
        if(input == 3){
            u.enterToppings();
        }
        if(input == 4){
            u.enterMenu();
        }
        if(input == 5){
            u.enterExtras();
        }
        if(input == 6){
            u.enterLocation();
        }
        break;
    }
}


