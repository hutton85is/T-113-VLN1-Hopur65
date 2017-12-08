#include "BakerUI.h"

BakerUI::BakerUI()
{
    //ctor
}

BakerUI::~BakerUI()
{
    //dtor
}

void BakerUI::main()
{
    while(true)
    {
        system("CLS");
        cout << "Til thess ad velja pontun ad skoda veldu                  1. "  << endl;
        cout << "Til thess ad velja pontun til ad afgreida veldur          2. "  << endl;
        cout << "Tile thess ad haetta veldu                                3. "  << endl;
        cout << endl;

        char input;
        cin >> input;

        if(input == '1')
        {
            system("CLS");
            readWriteClass rw;
            vector<client> customersVec;
            client customers;
            rw.loadSpecificVector(customersVec, "order/customerlist.dat", customers);
            for(unsigned int i = 0; i < customersVec.size(); i++)
            {
                cout << customersVec[i] << endl;
            }
            system("pause");
        }
        else if(input == '2')
        {

        }
        else if(input == '3')
        {
            break;
        }

        //displayClient();
    }
}

void BakerUI::displayClient()
{
    string name;
    cout << "Enter name on order: ";
    cin >> ws;
    getline(cin, name);
    name = "order/" + name + ".dat";
    const char* fname = name.c_str();

    Baker b(fname);
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
    cout << "************" << endl;
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
