#include "BakerUI.h"

BakerUI::BakerUI()
{
    //ctor
}

BakerUI::~BakerUI()
{
    //dtor
}

void BakerUI::displayClientList()
{
    vector<client> customersVec = baker.getCustomerVec();
    displayVector(customersVec, true);
}

void BakerUI::pickLocation()
{
    char input;
    vector<PizzaLocations> availLocations = baker.getPizzaLocations();
    displayVector(availLocations, true);

    cout << "Veldu thina stadsetningu ur listanum" << endl;
    cin >> input;

    baker.setBakerLocation(availLocations[input - 48].place);
}

void BakerUI::main()
{
    char input;

    pickLocation();


    while(true)
    {
        system("CLS");
        cout << "Til thess ad velja pontun ad skoda veldu                  1. "  << endl;
        cout << "Til thess ad velja pontun til ad afgreida veldu           2. "  << endl;
        cout << "Til thess ad haetta veldu                                 3. "  << endl;
        cout << endl;

        cin >> input;

        if(input == '1')
        {
            system("CLS");
            displayClientList();
            system("pause");
        }
        else if(input == '2')
        {
            system("CLS");
            displayClientList();
            system("pause");
        }
        else if(input == '3')
        {
            break;
        }
    }
}

void BakerUI::displayClient()
{/*
    string name;
    cout << "Enter name on order: ";
    cin >> ws;
    getline(cin, name);
    name = "order/" + name + ".dat";
    const char* fname = name.c_str();

    Baker b();
    vector<client> customerVec = b.getCustomerVec();
    vector<Pizza> orderVec = b.getOrderVec();
    vector<PizzaHelper> pHelperVec = b.getpHelperVec();

    for(unsigned int i = 0; i < orderVec.size(); i++)
    {
        cout << "Pizza order " << i+1 << endl;
        if(pHelperVec[i].sizeCounter)
        {
            displayVector(orderVec[i].psize, false);
        }
        if(pHelperVec[i].crustCounter)
        {
            displayVector(orderVec[i].pcrust, false);
        }
        if(pHelperVec[i].menuCounter)
        {
            displayVector(orderVec[i].pmenu, false);
        }
        if(pHelperVec[i].toppingsCounter)
        {
            displayVector(orderVec[i].ptoppings, false);
        }
        if(pHelperVec[i].extrasCounter)
        {
            displayVector(orderVec[i].pextras, false);
        }
        if(pHelperVec[i].locationCounter)
        {
            displayVector(orderVec[i].plocations, false);
        }
    }
    cout << "************" << endl;*/
}

template<typename Pizzaclass>
void BakerUI::displayVector(vector<Pizzaclass> vec, bool choice)
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
