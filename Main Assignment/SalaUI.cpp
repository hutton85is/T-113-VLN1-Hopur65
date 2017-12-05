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

    while(true){

        unsigned int input;

        cout << "Press 1 to choose your pizza size " << endl;
        cout << "Press 2 to choose your crust " << endl;
        cout << "Press 3 to choose toppings " << endl;
        cout << "Press 4 to choose a pizza from the menu " << endl;
        cout << "Press 5 to choose extras " << endl;
        cout << "Press 6 to choose location " << endl;
        cout << "Press 7 to enter name for order" << endl;

        cin >> input;

        Sala s;

        if(input == 1)
        {
            vector<PizzaSize> vec = s.getOrderpsize();
            for (unsigned int i = 0; i < vec.size(); i++)
            {
                cout << i << " : " << vec[i] << endl;
            }
            cout << endl;

            cout << "Enter what size pizza you would like: ";
            cin >> input;

            s.enterPizzaSize(input);
            system("CLS");
        }
        else if(input == 2)
        {
            vector<PizzaCrust> vec = s.getOrderpcrust();
            for (unsigned int i = 0; i < vec.size(); i++)
            {
                cout << i << " : " << vec[i] << endl;
            }
            cout << endl;

            cout << "Enter what type of crust you would like: ";
            cin >> input;

            s.enterCrust(input);
            system("CLS");
        }
        else if(input == 3)
        {
            vector<PizzaToppings> vec = s.getOrderptoppings();
            for (unsigned int i = 0; i < vec.size(); i++)
            {
                cout << i << " : " << vec[i] << endl;
            }
            cout << endl;

            cout << "What toppings would you like on your pizza: ";
            cin >> input;

            s.enterToppings(input);
            system("CLS");
        }
        else if(input == 4)
        {
            vector<PizzaMenu> vec = s.getOrderpMenu();
            for (unsigned int i = 0; i < vec.size(); i++)
            {
                cout << i << " : " << vec[i] << endl;
            }
            cout << endl;

            cout << "Enter what pizza you would like from the menu: ";
            cin >> input;

            s.enterMenu(input);
            system("CLS");
        }
        else if(input == 5)
        {
            vector<PizzaExtras> vec = s.getOrderpextras();
            for (unsigned int i = 0; i < vec.size(); i++)
            {
                cout << i << " : " << vec[i] << endl;
            }
            cout << endl;

            cout << "Enter what extras you would like: ";
            cin >> input;

            s.enterExtras(input);
            system("CLS");
        }
        else if(input == 6)
        {
            vector<PizzaLocations> vec = s.getOrderplocations();
            for (unsigned int i = 0; i < vec.size(); i++)
            {
                cout << i << " : " << vec[i] << endl;
            }
            cout << endl;

            cout << "Enter what location you want to order from: ";
            cin >> input;

            s.enterLocation(input);
            system("CLS");
        }
        else if(input == 7){
            system("CLS");
        }
    }
}


