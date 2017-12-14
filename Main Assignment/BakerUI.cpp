#include "BakerUI.h"

BakerUI::BakerUI()
{

}

void BakerUI::displayCustomerDueProgress()
{
    vector<Client> customersVec = baker.getCustomersVecDueProgress();
    for(unsigned int i = 0; i < customersVec.size(); i++)
    {
        cout << i << ". " << customersVec[i] << endl;
    }
}

void BakerUI::displayCustomerInProgress()
{
    vector<Client> customersVec = baker.getCustomersVecInProgress();
    for(unsigned int i = 0; i < customersVec.size(); i++)
    {
        cout << i << ". " << customersVec[i] << endl;
    }
}

bool BakerUI::pickLocation()
{
    try
    {
        helperUI.displayHeader();
        int input;
        vector<PizzaLocations> availLocations = baker.getPizzaLocations();
        int availLocationsSize = availLocations.size();
        for(int i = 0; i < availLocationsSize; i++)
        {
            cout << i << ". " << availLocations[i] << endl;
        }
        cout << endl;

        cout << "Veldu thina stadsetningu ur listanum: ";
        cin >> input;
        system("CLS");

        if(!cin || availLocationsSize <= input || input < 0)
        {
            throw InputErrorException("Inslattarvilla a vali a stadsetningu i BakerUI");
        }

        baker.setBakerLocation(availLocations[input].place);
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
    return !(baker.getCustomerVec().empty());
}

void BakerUI::displayCustomerDueProgressOrder(unsigned int customerNumber)
{
    vector<Client> customer = baker.getCustomersVecDueProgress();
    vector<Pizza> order = baker.getCustomersOrderDueProgress(customerNumber);
    cout << customerNumber << ". " << customer[customerNumber] << endl;
    for(unsigned int i = 0; i < order.size(); i++)
    {
        cout << "Pizza " << i+1 << ". " << order[i] << endl;
    }
}

void BakerUI::displayCustomerInProgressOrder(unsigned int customerNumber)
{
    vector<Client> customer = baker.getCustomersVecInProgress();
    vector<Pizza> order = baker.getCustomersOrderInProgress(customerNumber);
    cout << customerNumber << ". " << customer[customerNumber] << endl;
    for(unsigned int i = 0; i < order.size(); i++)
    {
        cout << "Pizza " << i+1 << ". " << order[i] << endl;
    }
}

void BakerUI::displayAllOrders()
{
    vector<Client> customerVec = baker.getCustomerVec();
    for(unsigned int i = 0; i < customerVec.size(); i++)
    {
        cout << customerVec[i] << endl;
        cout << "------------" << endl;
    }
}

void BakerUI::chooseSeeAllOrders()
{
    helperUI.displayHeader();
    displayAllOrders();
}

void BakerUI::chooseSeeDueOrders()
{
    helperUI.displayHeader();
    if (baker.getCustomersVecDueProgress().size())
    {
        displayCustomerDueProgress();

        int customerID;
        cout << endl;
        cout << "Veldu pontun til ad skoda nanar: ";
        cin >> customerID;
        system("CLS");
        if(!cin)
        {
            throw InputErrorException("Innslattarvilla a pontun til ad skoda nanar");
        }
        helperUI.displayHeader();
        displayCustomerDueProgressOrder(customerID);

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
            baker.workOnOrder(customerID);
        }
    }
    else
    {
        cout << "Engin pontun sem bidur afgreidslu: " << endl;
        cout << endl;
        system("pause");
    }
}

void BakerUI::chooseSeeInProgressOrders()
{
    helperUI.displayHeader();

    if (baker.getCustomersVecInProgress().size())
    {
        displayCustomerInProgress();

        int customerID;
        cout << endl;
        cout << "Veldu pontun til ad skoda nanar: ";
        cin >> customerID;
        system("CLS");
        if(!cin)
        {
            throw InputErrorException("Innslattarvilla a pontun til ad skoda nanar");
        }

        helperUI.displayHeader();
        displayCustomerInProgressOrder(customerID);

        string choice;
        cout << "Velja pontun til ad klara? j/n: ";
        cin >> ws;
        getline(cin, choice);
        if(!cin)
        {
            throw InputErrorException("Innslattarvilla a vali um pontun til ad klara");
        }

        // if choice is 'y', yes change order status to in progress
        if (choice[0] == 'j')
        {
            baker.finishOrder(customerID);
        }
    }
    else
    {
        cout << "Engin pontun sem bidur afgreidslu: " << endl;
        cout << endl;
        system("pause");
    }
}

void BakerUI::main()
{
    int input;
    // Only continue if there are some pending customers
    if (pickLocation())
    {
        while(true && baker.getCustomerVec().size())
        {
            try
            {
                system("CLS");
                helperUI.displayHeader();
                cout << "Til thess ad sja allar pantanir veldu                     1. "  << endl;
                cout << "Til thess ad velja pontun til ad vinna i veldu            2. "  << endl;
                cout << "Til thess ad velja pontun sem tilbuna veldu               3. "  << endl;
                cout << "Til thess ad haetta veldu                                 4. "  << endl;
                cout << endl;
                cout << "Veldu her: ";

                cin >> input;
                system("CLS");

                if(!cin || input < 0 || input > 4)
                {
                    throw InputErrorException("Inslattarvilla i vallista bakeryUI");
                }

                if(input == 1)
                {
                    chooseSeeAllOrders();
                    cout << endl;
                    system("pause");
                }
                else if(input == 2)
                {
                    chooseSeeDueOrders();
                }
                else if(input == 3)
                {
                    chooseSeeInProgressOrders();
                }
                else if(input == 4)
                {
                    break;
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
    }

    else
    {
        helperUI.displayHeader();
        cout << "Thad eru engar pantanir i bid: " << baker.getBakerLocation() << endl;
        cout << endl;
        system("pause");
    }
}
