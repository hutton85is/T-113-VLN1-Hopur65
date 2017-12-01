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
        cout << "Press 1 to add a new pizza size: ";
        cout << "Press 2 to add a new crust: ";
        cout << "Press 3 to add a new topping: ";
        cout << "Press 4 to add a new pizza to the menu: ";
        cout << "Press 5 to add a new extra: ";
        cout << "Press 6 to add a new location: ";

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


