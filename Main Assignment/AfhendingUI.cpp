#include "AfhendingUI.h"

AfhendingUI::AfhendingUI()
{
    //ctor
}

bool AfhendingUI::pickLocation()
{
    try
    {
        helperUI.displayHeader();
        int input;
        vector<PizzaLocations> availLocations = afhending.getPizzaLocations();
        for(unsigned int i = 0; i < availLocations.size(); i++)
        {
            cout << i << ". " << availLocations[i] << endl;
        }
        cout << endl;

        cout << "Veldu thina stadsetningu ur listanum: ";
        cin >> input;
        system("CLS");

        if(!cin)
        {
            throw InputErrorException("Inslattarvilla a vali a stadsetningu");
        }

        afhending.setAfhendingLocation(availLocations[input - 48].place);
    }
    catch(InputErrorException e)
    {
        Error er;
        er.logInputErrorException(e, "Exceptions/InputErrorException.dat");
        cout << e.getMessage() << endl;
        system("pause");
        cin.clear();
        cin.ignore(INT_MAX,'\n');
    }
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
    try
    {
        int input;

        // Only continue if there are some pending customers
        if (pickLocation())
        {
            while(true && afhending.getCustomerVec().size())
            {
                system("CLS");
                helperUI.displayHeader();
                cout << "Til thess ad sja allar pantanir veldu                     1. "  << endl;
                cout << "Til thess ad velja pontun til ad afhenda veldu            2. "  << endl;
                cout << "Til thess ad haetta veldu                                 3. "  << endl;
                cout << endl;
                cout << "Veldur her: ";

                cin >> input;
                system("CLS");

                if(!cin || input < 0 || input > 3)
                {
                    throw InputErrorException("Inslattarvilla i vallista AfhendingUI");
                }

                if(input == '1')
                {
                    helperUI.displayHeader();
                    displayAllCustomers(false);
                    cout << endl;
                    system("pause");
                }
                else if(input == '2')
                {
                    helperUI.displayHeader();
                    displayAllCustomers(true);

                    int customerID;
                    cout << endl;
                    cout << "Veldu pontun til ad skoda nanar: ";
                    cin >> customerID;
                    system("CLS");
                    if(!cin)
                    {
                        throw InputErrorException("Innslattarvilla a vali um pontun til ad skoda nanar");
                    }

                    helperUI.displayHeader();
                    displayCustomerOrder(customerID);

                    string choice;
                    cout << "Velja pontun til ad vinna i? j/n: ";
                    cin >> ws;
                    getline(cin, choice);
                    if(!cin)
                    {
                        throw InputErrorException("Innslattarvilla a vali um pontun til ad vinna i");
                    }

                    // if choice is 'y', yes change order status to in progress
                    if (choice[0] == 'j')
                    {
                        afhending.deliverOrder(customerID);
                    }
                }
                else if(input == '3')
                {
                    break;
                }
            }
        }
        else
        {
            helperUI.displayHeader();
            cout << "Thad eru engar pantanir i bid: " << afhending.getAfhendingLocation() << endl;
            cout << endl;
            system("pause");
        }
    }
    catch(InputErrorException e)
    {
        Error er;
        er.logInputErrorException(e, "Exceptions/InputErrorException.dat");
        cout << e.getMessage() << endl;
        system("pause");
        cin.clear();
        cin.ignore(INT_MAX,'\n');
    }
}
