#include "AfhendingUI.h"

AfhendingUI::AfhendingUI()
{
    //ctor
}

AfhendingUI::~AfhendingUI()
{
    //dtor
}

bool AfhendingUI::pickLocation()
{
    char input;
    vector<PizzaLocations> availLocations = afhending.getPizzaLocations();
    for(unsigned int i = 0; i < availLocations.size(); i++)
    {
        cout << i << ". " << availLocations[i] << endl;
    }
    cout << endl;

    cout << "Veldu thina stadsetningu ur listanum" << endl;
    cin >> input;

    afhending.setAfhendingLocation(availLocations[input - 48].place);
    return !(afhending.getCustomerVec().empty());
}

void AfhendingUI::displayAllCustomers(bool show)
{
    vector<client> customerVec = afhending.getCustomerVec();
    for(unsigned int i = 0; i < customerVec.size(); i++)
    {
        if(show)
        {
            cout << i << ". ";
        }
        cout << customerVec[i] << endl;
        cout << "------------" << endl;
    }
}

void AfhendingUI::displayCustomerOrder(unsigned int customerNumber)
{
    vector<client> customer = afhending.getCustomerVec();
    vector<Pizza> order = afhending.getOrderVec(customerNumber);
    cout << customerNumber << ". " << customer[customerNumber] << endl;
    for(unsigned int i = 0; i < order.size(); i++)
    {
        cout << "Pizza " << i+1 << ". " << order[i] << endl;
    }
}

void AfhendingUI::main()
{
    char input;

    // Only continue if there are some pending customers
    if (pickLocation())
    {
        while(true)
        {
            system("CLS");
            cout << "Til thess ad sja allar pantanir veldu                     1. "  << endl;
            cout << "Til thess ad velja pontun til ad afhenda veldu            2. "  << endl;
            cout << "Til thess ad haetta veldu                                 3. "  << endl;
            cout << endl;

            cin >> input;

            if(input == '1')
            {
                system("CLS");
                displayAllCustomers(false);
                system("pause");
            }
            else if(input == '2')
            {
                system("CLS");
                displayAllCustomers(true);

                unsigned int customerID;
                cout << "Veldu pontun til ad skoda nanar" << endl;
                cin >> customerID;
                system("CLS");

                displayCustomerOrder(customerID);

                char choice;
                cout << "Velja pontun til ad vinna i? j/n: ";
                cin >> choice;

                // if choice is 'y', yes change order status to in progress
                if (choice == 'j')
                {
                    afhending.deliverOrder(customerID);
                }
                system("pause");
            }
            else if(input == '3')
            {
                system("CLS");
                break;
            }
        }
    }
}
