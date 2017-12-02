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

    while(true){

        system("CLS");

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
            system("CLS");
        }
        if(input == 2){
            u.enterCrust();
            system("CLS");
        }
        if(input == 3){
            u.enterToppings();
            system("CLS");
        }
        if(input == 4){
            u.enterMenu();
            system("CLS");
        }
        if(input == 5){
            u.enterExtras();
            system("CLS");
        }
        if(input == 6){
            u.enterLocation();
            system("CLS");
        }
        break;
    }
}


