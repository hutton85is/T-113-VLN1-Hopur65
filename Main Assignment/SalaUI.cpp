#include "SalaUI.h"

SalaUI::SalaUI()
{

}

SalaUI::~SalaUI()
{
    //dtor
}

bool SalaUI::yorn(char answer){

    return answer == 'y';
}

void SalaUI::displayFullOrder(Sala s)
{
    displayVector(s.getOrderpsize(), false);
    displayVector(s.getOrderpcrust(), false);
    displayVector(s.getOrderpMenu(), false);
    displayVector(s.getOrderptoppings(), false);
    displayVector(s.getOrderplocations(), false);
}

template<typename Pizzaclass>
void SalaUI::displayVector(vector<Pizzaclass> vec, bool choice)
{
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        if (choice)
        {
            cout << i << ". ";
        }
        cout << vec[i] << endl;
    }
}

void SalaUI::mainOrder()
{
    Sala s;

    while(true)
    {
        unsigned int input;

        cout << "Your current order" << endl;
        displayFullOrder(s);
        cout << "*************************" << endl;

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

        if(input == 1)
        {
            displayVector(s.getLagerpsize(), true);

            cout << "Enter what size pizza you would like: ";
            cin >> input;

            s.enterPizzaSize(input);
        }
        else if(input == 2)
        {
            displayVector(s.getLagerpcrust(), true);
            cout << endl;

            cout << "Enter what type of crust you would like: ";
            cin >> input;

            s.enterCrust(input);
        }
        else if(input == 3)
        {
            displayVector(s.getLagerptoppings(), true);
            cout << endl;

            cout << "What toppings would you like on your pizza: ";
            cin >> input;

            s.enterToppings(input);
        }
        else if(input == 4)
        {
            displayVector(s.getLagerpMenu(), true);
            cout << endl;

            cout << "Enter what pizza you would like from the menu: ";
            cin >> input;

            s.enterMenu(input);
        }
        else if(input == 5)
        {
            displayVector(s.getLagerpextras(), true);
            cout << endl;

            cout << "Enter what extras you would like: ";
            cin >> input;

            s.enterExtras(input);
        }
        else if(input == 6)
        {
            displayVector(s.getLagerplocations(), true);
            cout << endl;

            cout << "Enter what location you want to order from: ";
            cin >> input;

            s.enterLocation(input);
        }
        else if(input == 7)
        {
            string name;
            cout << "Enter name for order: ";
            cin >> ws;
            getline(cin, name);

            string address;
            cout << "Enter street address: ";
            cin >> address;

            int number;
            cout << "Enter address number: ";
            cin >> number;

            s.createOrder(name, address, number);

            system("CLS");
            cout << "HERE IS YOUR ORDER" << endl;
            cout << "----------------------------" << endl;
            displayFullOrder(s);
            cout << "----------------------------" << endl;
            cout << endl;
            cout << endl;
            cout << endl;

            system("pause");
            break;
        }
        else if (input == 8)
        {
            break;
        }
        system("CLS");
    }
}


