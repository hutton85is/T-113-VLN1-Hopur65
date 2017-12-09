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

        cout << "Til thess ad skra nyja pizza staerd veldu       1." << endl;
        cout << "Til thess ad skra nyja pizza crust veldu        2." << endl;
        cout << "Til thess ad skra nytt alegg veldu              3." << endl;
        cout << "Til thess ad skra nyja pizzu a matsedil veldu   4." << endl;
        cout << "Til thess ad skra nytt medlaeti veldu           5." << endl;
        cout << "Til thess ad skra nyjan afhendingarstad veldu   6." << endl;

        cin >> input;

        system("CLS");

        Umsjon u;

        if(input == 1)
        {
            displayVector(u.getpsize());
            cout << "Sladu inn nyja staerd af pizzu: ";
            char p_size[32];
            cin >> p_size;
            cout << "sladu inn verd a " << p_size << ": ";
            int price;
            cin >> price;
            u.createPizzaSize(p_size, price);
            system("CLS");
        }
        else if(input == 2)
        {
            displayVector(u.getpcrust());
            cout << "Sladu inn nyja typu af crust: ";
            char crust_type[32];
            cin >> crust_type;
            cout << "Sladu inn verd a " << crust_type << ": ";
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
            cout << "Sladu inn nyja pizzu a matsedil: ";
            char choose_pizza[32];
            cin >> choose_pizza;
            cout << "Sladu inn verd a " << choose_pizza << ": ";
            int price;
            cin >> price;
            u.createMenu(choose_pizza, price);
            system("CLS");
        }
        else if(input == 5){
            displayVector(u.getpextras());

            cout << "Sladu inn nytt medlaeti: ";
            char extras_type[32];
            cin >> extras_type;
            cout << "Sladu inn verd a " << extras_type << ": ";
            int price;
            cin >> price;
            u.createExtras(extras_type, price);
            system("CLS");
        }
        else if(input == 6)
        {
            displayVector(u.getplocations());

            cout << "Sladu inn nyja stadsetningu pizza stadar: ";
            char place[32];
            cin >> place;
            u.createLocation(place);
            system("CLS");
        }
        break;
    }
}


