#include "BakerUI.h"

BakerUI::BakerUI()
{
    //ctor
}

BakerUI::~BakerUI()
{
    //dtor
}

void BakerUI::displayCustomerDueProgress()
{
    vector<client> customersVec = baker.getCustomersVecDueProgress();
    for(unsigned int i = 0; i < customersVec.size(); i++)
    {
        cout << i << ". " << customersVec[i] << endl;
    }
}

void BakerUI::displayCustomerInProgress()
{
    vector<client> customersVec = baker.getCustomersVecInProgress();
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
        char input;
        vector<PizzaLocations> availLocations = baker.getPizzaLocations();
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
            throw InputErrorException("Inslattarvilla i vallista UmsjonUI");
        }

        baker.setBakerLocation(availLocations[input - 48].place);
        if(baker.getCustomerVec().empty())
        {
            return false;
        }
    }
    catch(InputErrorException e)
    {
        Error er;
        er.logInputErrorException(e, "Exceptions/InputErrorException.dat");
        e.getMessage();
        system("pause");
    }
    return true;
}

void BakerUI::displayCustomerDueProgressOrder(unsigned int customerNumber)
{
    vector<client> customer = baker.getCustomersVecDueProgress();
    vector<Pizza> order = baker.getCustomersOrderDueProgress(customerNumber);
    cout << customerNumber << ". " << customer[customerNumber] << endl;
    for(unsigned int i = 0; i < order.size(); i++)
    {
        cout << "Pizza " << i+1 << ". " << order[i] << endl;
    }
}

void BakerUI::displayCustomerInProgressOrder(unsigned int customerNumber)
{
    vector<client> customer = baker.getCustomersVecInProgress();
    vector<Pizza> order = baker.getCustomersOrderInProgress(customerNumber);
    cout << customerNumber << ". " << customer[customerNumber] << endl;
    for(unsigned int i = 0; i < order.size(); i++)
    {
        cout << "Pizza " << i+1 << ". " << order[i] << endl;
    }
}

void BakerUI::displayAllOrders()
{
    vector<client> customerVec = baker.getCustomerVec();
    for(unsigned int i = 0; i < customerVec.size(); i++)
    {
        cout << customerVec[i] << endl;
        cout << "------------" << endl;
    }
}

void BakerUI::main()
{
        unsigned int input;
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

                    if(!cin)
                    {
                        throw InputErrorException("Inslattarvilla i vallista bakeryUI");
                    }

                    if(input == 1)
                    {
                        helperUI.displayHeader();
                        displayAllOrders();
                        cout << endl;
                        system("pause");
                    }
                    else if(input == 2)
                    {
                        helperUI.displayHeader();
                        if (baker.getCustomersVecDueProgress().size())
                        {
                            displayCustomerDueProgress();

                            unsigned int customerID;
                            cout << endl;
                            cout << "Veldu pontun til ad skoda nanar: ";
                            cin >> customerID;
                            system("CLS");
                            helperUI.displayHeader();
                            displayCustomerDueProgressOrder(customerID);

                            char choice;
                            cout << "Velja pontun til ad vinna i? j/n: ";
                            cin >> choice;

                            // if choice is 'y', yes change order status to in progress
                            if (choice == 'j')
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
                    else if(input == 3)
                    {
                        helperUI.displayHeader();

                        if (baker.getCustomersVecInProgress().size())
                        {
                            displayCustomerInProgress();

                            unsigned int customerID;
                            cout << endl;
                            cout << "Veldu pontun til ad skoda nanar: ";
                            cin >> customerID;
                            system("CLS");

                            helperUI.displayHeader();
                            displayCustomerInProgressOrder(customerID);

                            char choice;
                            cout << "Velja pontun til ad klara? j/n: ";
                            cin >> choice;

                            // if choice is 'y', yes change order status to in progress
                            if (choice == 'j')
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
                    else if(input == 4)
                    {
                        break;
                    }
                }

                catch(InputErrorException e)
                {
                    Error er;
                    er.logInputErrorException(e, "Exceptions/InputErrorException.dat");
                    e.getMessage();
                    system("pause");
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

