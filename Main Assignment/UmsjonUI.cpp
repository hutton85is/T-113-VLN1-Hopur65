#include "UmsjonUI.h"

UmsjonUI::UmsjonUI()
{

}

UmsjonUI::~UmsjonUI()
{
    //dtor
}

template<typename Pizzaclass>
void UmsjonUI::displayVector(vector<Pizzaclass> vec)
{
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    cout << endl;
}

bool UmsjonUI::yorn(char answer){

    return answer == 'y';
}

void UmsjonUI::main(){

    while(true){

        system("CLS");

        int input;

        cout << "Press 1 to add a new pizza size " << endl;
        cout << "Press 2 to add a new crust " << endl;
        cout << "Press 3 to add a new topping " << endl;
        cout << "Press 4 to add a new pizza to the menu " << endl;
        cout << "Press 5 to add a new extra " << endl;
        cout << "Press 6 to add a new location " << endl;

        cin >> input;

        Umsjon u;

        if(input == 1)
        {
            displayVector(u.getpsize());
            cout << "Enter new pizza size: ";
            char p_size[32];
            cin >> p_size;
            cout << "Enter price of " << p_size << " size: ";
            int price;
            cin >> price;
            u.createPizzaSize(p_size, price);
            system("CLS");
        }
        else if(input == 2)
        {
            displayVector(u.getpcrust());
            cout << "Enter new type of pizza crust: ";
            char crust_type[32];
            cin >> crust_type;
            cout << "Enter price of " << crust_type << " crust: ";
            int price;
            cin >> price;
            u.createCrust(crust_type, price);
            system("CLS");
        }
        else if(input == 3)
        {
            displayVector(u.getptoppings());
            cout << "Enter new type of topping: ";
            char toppings[32];
            cin >> toppings;
            cout << "Enter price of " << toppings << ": ";
            int price;
            cin >> price;
            u.createToppings(toppings, price);
            system("CLS");
        }
        else if(input == 4)
        {
            displayVector(u.getpMenu());
            cout << "Enter new pizza to the menu: ";
            char choose_pizza[32];
            cin >> choose_pizza;
            cout << "Enter price of " << choose_pizza << " pizza: ";
            int price;
            cin >> price;
            u.createMenu(choose_pizza, price);
            system("CLS");
        }
        else if(input == 5){
            displayVector(u.getpextras());

            cout << "Enter new type of extras: ";
            char extras_type[32];
            cin >> extras_type;
            cout << "Enter price of " << extras_type << ": ";
            int price;
            cin >> price;
            u.createExtras(extras_type, price);
            system("CLS");
        }
        else if(input == 6)
        {
            displayVector(u.getplocations());

            cout << "Enter new location: ";
            char place[32];
            cin >> place;
            u.createLocation(place);
            system("CLS");
        }
        break;
    }
}


