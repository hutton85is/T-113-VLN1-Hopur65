#include "AfhendingUI.h"

AfhendingUI::AfhendingUI()
{

}

bool AfhendingUI::pickLocation()
{
    try
    {
        helperUI.displayHeader();
        helperUI.displayBelowHeader("Afhending");
        cout << endl;
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
            throw InputErrorException("Inslattarvilla a vali a stadsetningu i AfhendingUI");
        }

        afhending.setAfhendingLocation(availLocations[input].place);
    }
    catch(InputErrorException e)
    {
        ErrorException er;
        er.logInputErrorException(e);
        cout << e.getMessage() << endl;
        system("pause");
        cin.clear();
        cin.ignore(INT_MAX,'\n');
    }
    return !(afhending.getCustomerVec().empty());
}

void AfhendingUI::displayAllCustomers(bool show)
{
    vector<Client> customerVec = afhending.getCustomerVec();

    for(unsigned int i = 0; i < customerVec.size(); i++)
    {
        if(show)
        {
            cout << i << ". " << endl;
        }
        cout << customerVec[i] << endl;
        cout << "    Pontun tilbuin: ";
        if (customerVec[i].finished)
        {
            cout << "ja" << endl;
        }
        else
        {
            cout << "nei" << endl;
        }
        cout << "    Pontun afhent: ";
        if (customerVec[i].orderDelivered)
        {
            cout << "ja" << endl;
        }
        else
        {
            cout << "nei" << endl;
        }
        cout << "    Heimsending: ";
        if (customerVec[i].deliverOrder)
        {
            cout << "ja" << endl;
        }
        else
        {
            cout << "nei" << endl;
        }
        cout << "------------" << endl;
    }
}

void AfhendingUI::displayCustomerOrder(unsigned int customerNumber)
{
    vector<Client> customer = afhending.getCustomerVec();
    vector<Pizza> order = afhending.getOrderVec(customerNumber);

    cout << customer[customerNumber] << endl;
    cout << "    Pontun tilbuin: ";
    if (customer[customerNumber].finished)
    {
        cout << "ja" << endl;
    }
    else
    {
        cout << "nei" << endl;
    }
    cout << "    Pontun afhent: ";
    if (customer[customerNumber].orderDelivered)
    {
        cout << "ja" << endl;
    }
    else
    {
        cout << "nei" << endl;
    }
    cout << "    Heimsending: ";
    if (customer[customerNumber].deliverOrder)
    {
        cout << "ja" << endl;
    }
    else
    {
        cout << "nei" << endl;
    }
    cout << endl;
    for(unsigned int i = 0; i < order.size(); i++)
    {
        cout << "   *Pizza " << i+1 << ". " << endl;
        cout << order[i] << endl;
    }
    cout << "------------" << endl;
    cout << endl;
}

void AfhendingUI::chooseSeeAllOrders()
{
    helperUI.displayHeader();
    helperUI.displayBelowHeader("Afhending");
    cout << endl;
    displayAllCustomers(false);
}

void AfhendingUI::chooseSeeFinishedOrders()
{
    helperUI.displayHeader();
    helperUI.displayBelowHeader("Afhending");
    cout << endl;
    displayAllCustomers(true);

    int customerID;
    cout << endl;
    cout << "Veldu pontun til ad skoda nanar: ";
    cin >> customerID;
    system("CLS");

    int CustomerVecSize = afhending.getCustomerVec().size();

    if(!cin || customerID < 0 || CustomerVecSize - 1 < customerID)
    {
        throw InputErrorException("Innslattarvilla a vali um pontun til ad skoda nanar");
    }

    helperUI.displayHeader();
    helperUI.displayBelowHeader("Afhending");
    cout << endl;
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

void AfhendingUI::main()
{
    try
    {
        int input;

        if (pickLocation())
        {
            while(true && afhending.getCustomerVec().size())
            {
                system("CLS");
                helperUI.displayHeader();
                helperUI.displayBelowHeader("Afhending");
                cout << endl;
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

                if(input == 1)
                {
                    chooseSeeAllOrders();
                    cout << endl;
                    system("pause");
                }
                else if(input == 2)
                {
                    chooseSeeFinishedOrders();
                }
                else if(input == 3)
                {
                    break;
                }
            }
        }
        else
        {
            helperUI.displayHeader();
            helperUI.displayBelowHeader("Afhending");
            cout << endl;
            cout << "Thad eru engar pantanir i bid: " << afhending.getAfhendingLocation() << endl;
            cout << endl;
            system("pause");
        }
    }
    catch(InputErrorException e)
    {
        ErrorException er;
        er.logInputErrorException(e);
        cout << e.getMessage() << endl;
        system("pause");
        cin.clear();
        cin.ignore(INT_MAX,'\n');
    }
}
