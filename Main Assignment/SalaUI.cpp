#include "SalaUI.h"

SalaUI::SalaUI()
{

}

SalaUI::~SalaUI()
{
    //dtor
}

void SalaUI::displayFullOrder(Sala s)
{

    client customer = s.getCustomerOrdersVector();

    if(customer.name[0] != '\0')
    {
        cout << customer << endl;
    }

    for(unsigned int i = 0; i < s.order.size(); i++)
    {
        cout << "Pizza order " << i+1 << endl;

        if(s.pHelper[i].sizeCounter)
        {
            displayVector(s.order[i].psize, false);
        }
        if(s.pHelper[i].crustCounter)
        {
            displayVector(s.order[i].pcrust, false);
        }
        if(s.pHelper[i].menuCounter)
        {
            displayVector(s.order[i].pmenu, false);
        }
        if(s.pHelper[i].toppingsCounter)
        {
            displayVector(s.order[i].ptoppings, false);
        }
        if(s.pHelper[i].extrasCounter)
        {
            displayVector(s.order[i].pextras, false);
        }
        if(s.pHelper[i].locationCounter)
        {
            displayVector(s.order[i].plocations, false);
        }
    }
    cout << "************" << endl;
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
    // Initiate variables
    s.newPizza();

    while(true)
    {
        unsigned int input;

        displayFullOrder(s);

        cout << "Press 1 to choose your pizza size" << endl;
        cout << "Press 2 to choose your crust" << endl;
        cout << "Press 3 to choose toppings" << endl;
        cout << "Press 4 to choose a pizza from the menu" << endl;
        cout << "Press 5 to choose extras" << endl;
        cout << "Press 6 to add another pizza" << endl;
        cout << "Press 7 to choose location" << endl;
        cout << "Press 8 to finish an order" << endl;
        cout << "Press 9 to cancel the order" << endl;

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
            //here I add everything to pizzavector and ask for another pizza
            s.newPizza();
        }
        else if(input == 7)
        {
            displayVector(s.getLagerplocations(), true);
            cout << endl;

            cout << "Enter what location you want to order from: ";
            cin >> input;

            s.enterLocation(input);
        }
        else if(input == 8)
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
        else if (input == 9)
        {
            break;
        }
        system("CLS");
    }
}


