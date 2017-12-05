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

void SalaUI::mainOrder()
{
    while(true)
    {
        system("CLS");

        unsigned int input;

        cout << "Press 1 to choose your pizza size" << endl;
        cout << "Press 2 to choose your crust" << endl;
        cout << "Press 3 to choose toppings" << endl;
        cout << "Press 4 to choose a pizza from the menu" << endl;
        cout << "Press 5 to choose extras" << endl;
        cout << "Press 6 to choose location" << endl;
        cout << "Press 7 to finish an order" << endl;
        cout << "Press 8 to cancel the order" << endl;

        cin >> input;
        system("CLS");
        Sala s;

        if(input == 1)
        {
            vector<PizzaSize> vec = s.getpsize();
            for (unsigned int i = 0; i < vec.size(); i++)
            {
                cout << i << " : " << vec[i] << endl;
            }
            cout << endl;

            cout << "Enter what size pizza you would like: ";
            cin >> input;

            s.enterPizzaSize(input);
        }
        else if(input == 2)
        {
            vector<PizzaCrust> vec = s.getpcrust();
            for (unsigned int i = 0; i < vec.size(); i++)
            {
                cout << i << " : " << vec[i] << endl;
            }
            cout << endl;

            cout << "Enter what type of crust you would like: ";
            cin >> input;

            s.enterCrust(input);
        }
        else if(input == 3)
        {
            vector<PizzaToppings> vec = s.getptoppings();
            for (unsigned int i = 0; i < vec.size(); i++)
            {
                cout << i << " : " << vec[i] << endl;
            }
            cout << endl;

            cout << "What toppings would you like on your pizza: ";
            cin >> input;

            s.enterToppings(input);
        }
        else if(input == 4)
        {
            vector<PizzaMenu> vec = s.getpMenu();
            for (unsigned int i = 0; i < vec.size(); i++)
            {
                cout << i << " : " << vec[i] << endl;
            }
            cout << endl;

            cout << "Enter what pizza you would like from the menu: ";
            cin >> input;

            s.enterMenu(input);
        }
        else if(input == 5)
        {
            vector<PizzaExtras> vec = s.getpextras();
            for (unsigned int i = 0; i < vec.size(); i++)
            {
                cout << i << " : " << vec[i] << endl;
            }
            cout << endl;

            cout << "Enter what extras you would like: ";
            cin >> input;

            s.enterExtras(input);
        }
        else if(input == 6)
        {
            vector<PizzaLocations> vec = s.getplocations();
            for (unsigned int i = 0; i < vec.size(); i++)
            {
                cout << i << " : " << vec[i] << endl;
            }
            cout << endl;

            cout << "Enter what location you want to order from: ";
            cin >> input;

            s.enterLocation(input);
        }
        else if(input == 7)
        {
            string name;
            cout << "Enter name for order: ";
            getline(cin, name);

            char address[32];
            cout << "Enter street address: ";
            cin >> address;

            int number;
            cout << "Enter address number";
            cin >> number;
        }
        else if (input == 8)
        {
            break;
        }
    }
}


