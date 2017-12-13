#include "UmsjonUI.h"

UmsjonUI::UmsjonUI()
{

}

UmsjonUI::~UmsjonUI()
{
    //dtor
}

template<typename Pizzaclass>
void UmsjonUI::displayVector(vector<Pizzaclass> vec, bool show)
{
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        if(show)
        {
            cout << i << ". ";
        }
        cout << vec[i] << endl;
    }
    cout << endl;
}

bool UmsjonUI::yorn(char answer)
{
    return answer == 'y';
}

void UmsjonUI::main()
{
    while(true)
    {
        try
        {
            system("CLS");

            unsigned int input;

            helperUI.displayHeader();
            cout << "Til thess ad skra nyja pizza staerd veldu       1." << endl;
            cout << "Til thess ad skra nyja pizza crust veldu        2." << endl;
            cout << "Til thess ad skra nytt alegg veldu              3." << endl;
            cout << "Til thess ad skra nyja pizzu a matsedil veldu   4." << endl;
            cout << "Til thess ad skra nytt medlaeti veldu           5." << endl;
            cout << "Til thess ad skra nyjan afhendingarstad veldu   6." << endl;
            cout << "Til thess ad haetta veldu                       7." << endl;
            cout << endl;
            cout << "Veldur her: ";

            cin >> input;
            system("CLS");

            if(!cin)
            {
                throw InputErrorException("Inslattarvilla i vallista UmsjonUI");
            }

            Umsjon u;

            if(input == 1)
            {
                helperUI.displayHeader();
                displayVector(u.getpsize(), false);
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
                helperUI.displayHeader();
                displayVector(u.getpcrust(), false);
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
                helperUI.displayHeader();
                if(u.getptoppings().size())
                {
                    displayVector(u.getptoppings(), false);
                }
                cout << "Sladu inn nyja tegund af aleggi: ";
                char toppings[32];
                cin >> toppings;
                cout << "Sladu inn verd a " << toppings << ": ";
                int price;
                cin >> price;
                u.createToppings(toppings, price);
                system("CLS");
            }
            else if(input == 4)
            {
                helperUI.displayHeader();
                displayVector(u.getpMenu(), false);
                cout << "Sladu inn nyja pizzu a matsedil: ";
                char choose_pizza[32];
                cin >> choose_pizza;
                system("CLS");

                helperUI.displayHeader();
                bool moreToppings = true;
                string toppings = "";
                vector<PizzaToppings> AllPizzaToppingsVec = u.getptoppings();
                while(moreToppings)
                {
                    int newToppingID;
                    displayVector(u.getptoppings(), true);
                    cout << "Sladu inn alegg til ad hafa a " << choose_pizza << ": ";
                    cin >> newToppingID;

                    string tempString(AllPizzaToppingsVec[newToppingID].toppings);

                    if(toppings == "")
                    {
                        toppings = tempString;
                    }
                    else
                    {
                        toppings = toppings + ", " + tempString;
                    }

                    cout << "Viltu velja fleiri alegg? j/n: ";
                    char yn;
                    cin >> yn;
                    if (yn == 'n')
                    {
                        moreToppings = false;
                    }
                    system("CLS");
                }

                helperUI.displayHeader();

                cout << "Sladu inn verd a " << choose_pizza << " sem hlutfall af grunn Pizzu: ";
                double price;
                cin >> price;

                char *newToppings = new char[128];
                strcpy(newToppings, toppings.c_str());

                u.createMenu(choose_pizza, price, newToppings);
                delete [] newToppings;
                system("CLS");
            }
            else if(input == 5){
                helperUI.displayHeader();
                displayVector(u.getpextras(), false);

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
                helperUI.displayHeader();
                displayVector(u.getplocations(), false);

                cout << "Sladu inn nyja stadsetningu pizza stadar: ";
                char place[32];
                cin >> place;
                u.createLocation(place);
                system("CLS");
            }
            else if(input == 7)
            {
                system("CLS");
                break;
            }
        }
        catch(InputErrorException e)
        {
            Error er;
            er.logInputErrorException(e, "Exceptions/InputErrorException.dat");
            e.getMessage();
            system("pause");
            cin.clear();
            cin.ignore(INT_MAX,'\n');
        }
    }
}


