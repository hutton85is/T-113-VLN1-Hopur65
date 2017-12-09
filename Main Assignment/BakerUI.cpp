#include "BakerUI.h"

BakerUI::BakerUI()
{
    //ctor
}

BakerUI::~BakerUI()
{
    //dtor
}

void BakerUI::displayClientOrder()
{
    vector<Pizza> order;
    vector<client> customersVec = baker.getCustomerVec();

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
            displayClientOrder();
            system("pause");
        }
        else if(input == '3')
        {
            break;
        }
    }
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
