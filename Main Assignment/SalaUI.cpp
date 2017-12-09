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

    for(unsigned int i = 0; i < s.getOrder().size(); i++)
    {
        cout << "Pizza order " << i+1 << endl;

        cout << s.getOrder()[i] << endl;

        cout << endl;
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
    unsigned int input;

    // Initiate variables
    s.newPizza();

    // Set location at the very beginning of SalaUI
    displayVector(s.getLagerplocations(), true);
    cout << endl;

    cout << "Enter what location you want to order from: ";
    cin >> input;

    s.enterLocation(input);

    while(true)
    {
        system("CLS");

        displayFullOrder(s);

        cout << "Skradu thina pontun : " << endl;
        cout << "Til thess ad velja pizza staerd veldu           1." << endl;
        cout << "Til thess ad velja pizza crust veldu            2." << endl;
        cout << "Til thess ad velja alegg a pizzuna veldu        3." << endl;
        cout << "Til thess ad velja pizzu af matsedli veldu      4." << endl;
        cout << "Til thess ad panta medlaeti veldu               5." << endl;
        cout << "Til thess ad baeta vid pizzu veldu              6." << endl;
        cout << "Til thess ad breyta afhendingarstad veldu       7." << endl;
        cout << "Til thess ad klara pöntun veldu                 8." << endl;
        cout << "Til thess ad haetta vid pontun veldu            9." << endl;
        //cout << "Til thess ad breyta pontun veldu                8." << endl;

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


