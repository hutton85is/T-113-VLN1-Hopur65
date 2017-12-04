#include "UmsjonUI.h"

UmsjonUI::UmsjonUI()
{

}

UmsjonUI::~UmsjonUI()
{
    //dtor
}

void UmsjonUI::addCrust()
{

}

bool UmsjonUI::yorn(char answer){

    return answer == 'y';
}

void UmsjonUI::main(){

    int input;

    cout << "Press 1 to add a new pizza size " << endl;
    cout << "Press 2 to add a new crust " << endl;
    cout << "Press 3 to add a new topping " << endl;
    cout << "Press 4 to add a new pizza to the menu " << endl;
    cout << "Press 5 to add a new extra " << endl;
    cout << "Press 6 to add a new location " << endl;

    cin >> input;

    Umsjon u;
    vector<PizzaSize> vec;
    u.getVector<PizzaSize>(vec);

    if(input == 1)
    {/*
        //PizzaSize tempClass;
        //vector<PizzaSize> vec = u.getVector(tempClass);
        vector<PizzaSize> vec;
        u.getVector<PizzaSize>(vec);
        for(unsigned int i = 0; i < vec.size(); i++)
        {
            cout << i << " : ";
            cout << vec[i].p_size << " " << vec[i].price << endl;
        }
        u.createPizzaSize();
        system("CLS");
    }
    else if(input == 2)
    {
        //PizzaCrust tempClass;
        //vector<PizzaCrust> vec = u.getVector(tempClass);
        vector<PizzaCrust> vec;
        u.getVector<PizzaCrust>(vec);
        for(unsigned int i = 0; i < vec.size(); i++)
        {
            cout << i << " : ";
            cout << vec[i].crust_type << " " << vec[i].price << endl;
        }
        u.createCrust();
        system("CLS");*/
    }
    else if(input == 3)
    {
        u.createToppings();
        system("CLS");
    }
    else if(input == 4)
    {
        u.createMenu();
        system("CLS");
    }
    else if(input == 5)
    {
        u.createExtras();
        system("CLS");
    }
    else if(input == 6){
        u.createLocation();
        system("CLS");
    }
}


