#include "BakerUI.h"

BakerUI::BakerUI()
{
    //ctor
}

BakerUI::~BakerUI()
{
    //dtor
}

void BakerUI::displayCustomerOrder(unsigned int customerNumber)
{
    vector<client> customer = baker.getCustomerVec();
    vector<Pizza> order = baker.getOrderVec(customerNumber);
    cout << customerNumber << ". " << customer[customerNumber] << endl;
    displayVector(order, true);
}

void BakerUI::displayCustomerList()
{
    vector<client> customersVec = baker.getCustomerVec();
    displayVector(customersVec, true);
}

char BakerUI::pickCustomer()
{
    char input;
    cout << "Veldu pontun til ad skoda nanar" << endl;
    cin >> input;
    return input;
}

bool BakerUI::pickLocation()
{
    char input;
    vector<PizzaLocations> availLocations = baker.getPizzaLocations();
    displayVector(availLocations, true);

    cout << "Veldu thina stadsetningu ur listanum" << endl;
    cin >> input;

    baker.setBakerLocation(availLocations[input - 48].place);
    if(baker.getCustomerVec().empty())
    {
        return false;
    }
    return true;
}

void BakerUI::displayAllOrders()
{
    for(unsigned int i = 0; i < baker.getCustomerVec().size(); i++)
    {
        displayCustomerOrder(i);
        cout << "------------" << endl;
    }
}

void BakerUI::main()
{
    char input;

    // Only continue if there are some pending customers
    if (pickLocation())
    {
        while(true)
        {
            system("CLS");
            cout << "Til thess ad sja allar pantanir veldu                     1. "  << endl;
            cout << "Til thess ad velja pontun til ad afgreida veldu           2. "  << endl;
            cout << "Tile thess ad velja pontun sem tilbuna veldu              3. "  << endl;
            cout << "Til thess ad haetta veldu                                 4. "  << endl;
            cout << endl;

            cin >> input;

            if(input == '1')
            {
                system("CLS");
                displayAllOrders();
                system("pause");
            }
            else if(input == '2')
            {
                system("CLS");
                displayCustomerList();
                char customerNumber = pickCustomer();
                system("CLS");
                displayCustomerOrder(customerNumber - 48);

                system("pause");
            }
            else if(input == '3')
            {

            }
            else if(input == '4')
            {
                break;
            }
        }
    }
    else
    {
        system("CLS");
        cout << "There are no pending customers for " << baker.getBakerLocation() << endl;
        system("pause");
    }
}

template<typename Pizzaclass>
void BakerUI::displayVector(vector<Pizzaclass> vec, bool choice)
{
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        if (choice)
        {
            cout << "Pizza " << i << ". ";
        }
        cout << vec[i] << endl;
        cout << endl;
    }
}
