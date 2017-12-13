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

            int input;

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

<<<<<<< HEAD
        cout << "--------------------------------------------------" << endl;
        cout << "                  Pizzastadurinn!                 " << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Til thess ad skra nyja pizza staerd veldu       1." << endl;
        cout << "Til thess ad skra nyja pizza crust veldu        2." << endl;
        cout << "Til thess ad skra nytt alegg veldu              3." << endl;
        cout << "Til thess ad skra nyja pizzu a matsedil veldu   4." << endl;
        cout << "Til thess ad skra nytt medlaeti veldu           5." << endl;
        cout << "Til thess ad skra nyjan afhendingarstad veldu   6." << endl;
=======
            if(!cin || input < 1 || 7 < input)
            {
                throw InputErrorException("Inslattarvilla i vallista UmsjonUI");
            }
>>>>>>> master

            Umsjon u;

            if(input == 1)
            {
                helperUI.displayHeader();
                displayVector(u.getpsize(), false);

                cout << "Sladu inn nyja staerd af pizzu: ";
                string pSize;
                cin >> ws;
                getline(cin, pSize);

                char p_size[32];
                strncpy(p_size, pSize.c_str(), sizeof(p_size) - 1);

                if(!cin)
                {
                    throw InputErrorException("Innslattarvilla a pizzustaerd");
                }

                int price;
                cout << "sladu inn verd a " << p_size << ": ";
                cin >> price;

                if(!cin || price < 0)
                {
                    throw InputErrorException("Innslattarvilla a verdi a pizzustaerd");
                }

                u.createPizzaSize(p_size, price);
                system("CLS");
            }
            else if(input == 2)
            {
                helperUI.displayHeader();
                displayVector(u.getpcrust(), false);

                string pCrust;
                cout << "Sladu inn nyja typu af botni: ";
                cin >> ws;
                getline(cin, pCrust);

                char crust_type[32];
                strncpy(crust_type, pCrust.c_str(), sizeof(crust_type) - 1);

                if(!cin)
                {
                    throw InputErrorException("Innslattarvilla a botni");
                }

                cout << "Sladu inn verd a " << crust_type << ": ";
                int price;
                cin >> price;

                if(!cin || price < 0)
                {
                    throw InputErrorException("Innslattarvilla a verdi a pizzabotni");
                }

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

                string pToppings;
                cin >> ws;
                getline(cin, pToppings);

                char toppings[32];
                strncpy(toppings, pToppings.c_str(), sizeof(toppings) - 1);

                if(!cin)
                {
                    throw InputErrorException("Innslattarvilla a aleggi");
                }
                cout << "Sladu inn verd a " << toppings << ": ";
                int price;
                cin >> price;
                if(!cin || price < 0)
                {
                    throw InputErrorException("Innslattarvilla a verdi a aleggi");
                }
                u.createToppings(toppings, price);
                system("CLS");
            }
            else if(input == 4)
            {
                helperUI.displayHeader();

                displayVector(u.getpMenu(), false);

                cout << "Sladu inn nyja pizzu a matsedil: ";
                string pMenu;
                cin >> ws;
                getline(cin, pMenu);

                char choose_pizza[32];
                strncpy(choose_pizza, pMenu.c_str(), sizeof(choose_pizza) - 1);

                system("CLS");
                if(!cin)
                {
                    throw InputErrorException("Innslattarvilla a pizzu a matsedli");
                }

                helperUI.displayHeader();
                bool moreToppings = true;
                string toppings = "";
                vector<PizzaToppings> AllPizzaToppingsVec = u.getptoppings();
                while(moreToppings)
                {
                    vector<PizzaToppings> pToppingsVec = u.getptoppings();
                    int pToppingsVecSize = pToppingsVec.size();
                    displayVector(pToppingsVec, true);

                    int newToppingID;
                    cout << "Sladu inn alegg til ad hafa a " << choose_pizza << ": ";
                    cin >> newToppingID;

                    if(!cin || newToppingID < 0 || pToppingsVecSize <= newToppingID)
                    {
                        throw InputErrorException("Innslattarvilla a aleggi a pizzu");
                    }

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
                    string yn;
                    cin >> ws;
                    getline(cin, yn);
                    if (yn[0] == 'n')
                    {
                        moreToppings = false;
                    }
                    system("CLS");
                    if(!cin)
                    {
                        throw InputErrorException("Innslattarvilla a vali um fleiri alegg");
                    }
                }

                helperUI.displayHeader();

                cout << "Sladu inn verd a " << choose_pizza << " sem hlutfall af grunn Pizzu: ";
                double price;
                cin >> price;
                if(!cin || price < 0)
                {
                    throw InputErrorException("Innslattarvilla a verdi a grunn pizzu");
                }

                char *newToppings = new char[128];
                strcpy(newToppings, toppings.c_str());

                u.createMenu(choose_pizza, price, newToppings);
                delete [] newToppings;
                system("CLS");
            }
            else if(input == 5)
            {
                helperUI.displayHeader();
                displayVector(u.getpextras(), false);

                cout << "Sladu inn nytt medlaeti: ";
                string pExtras;
                cin >> ws;
                getline(cin, pExtras);

                char extras_type[32];
                strncpy(extras_type, pExtras.c_str(), sizeof(extras_type) - 1);

                if(!cin)
                {
                    throw InputErrorException("Innslattarvilla a medlaeti");
                }
                cout << "Sladu inn verd a " << extras_type << ": ";
                int price;
                cin >> price;
                if(!cin || price < 0)
                {
                    throw InputErrorException("Innslattarvilla a verdi a medlaeti");
                }

                u.createExtras(extras_type, price);
                system("CLS");
            }
            else if(input == 6)
            {
                helperUI.displayHeader();
                displayVector(u.getplocations(), false);

                cout << "Sladu inn nyja stadsetningu pizza stadar: ";
                string pLocations;
                cin >> ws;
                getline(cin, pLocations);

                char place[32];
                strncpy(place, pLocations.c_str(), sizeof(place) - 1);

                if(!cin)
                {
                    throw InputErrorException("Innslattarvilla a stadsetningu");
                }
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
            cout << e.getMessage() << endl;
            system("pause");
            cin.clear();
            cin.ignore(INT_MAX,'\n');
        }
    }
}


