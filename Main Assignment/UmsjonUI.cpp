#include "UmsjonUI.h"

UmsjonUI::UmsjonUI()
{

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
}

void UmsjonUI::createNewPizzaSize()
{
    helperUI.displayHeader();
    helperUI.displayBelowHeader("Ny staerd af pizzu");

    cout << endl;
    helperUI.displayColumn("Staerd", "Verd(kr.)");

    displayVector(u.getpsize(), false);

    helperUI.displayCloseTable();

    cout << endl;

    cout << "Sladu inn nyju staerdina her: ";
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
    cout << "Sladu inn verd a " << p_size << ": ";
    cin >> price;

    if(!cin || price < 0)
    {
        throw InputErrorException("Innslattarvilla a verdi a pizzustaerd");
    }

    u.createPizzaSize(p_size, price);
}

void UmsjonUI::createNewPizzaCrust()
{
    helperUI.displayHeader();
    helperUI.displayBelowHeader("Ny staerd af pizzu botn");

    cout << endl;
    helperUI.displayColumn("Pizza botn", "Verd(kr.)");
    displayVector(u.getpcrust(), false);
    helperUI.displayCloseTable();

    cout << endl;

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
}

void UmsjonUI::createNewPizzaTopping()
{
    helperUI.displayHeader();
    helperUI.displayBelowHeader("Ny tegund af aleggi");

    cout << endl;
    helperUI.displayColumn("Alegg", "Verd(kr.)");

    displayVector(u.getptoppings(), false);
    helperUI.displayCloseTable();

    cout << endl;

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
}

void UmsjonUI::createNewPizzaMenu()
{
    helperUI.displayHeader();
    helperUI.displayBelowHeader("Ny pizza a matsedil");

    cout << endl;
    helperUI.displayColumn("Heiti Pizzu", "Aleggstegundir");

    displayVector(u.getpMenu(), false);
    helperUI.displayCloseTable();

    cout << endl;

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

    bool moreToppings = true;
    string toppings = "";
    vector<PizzaToppings> AllPizzaToppingsVec = u.getptoppings();

    while(moreToppings)
    {
        vector<PizzaToppings> pToppingsVec = u.getptoppings();
        int pToppingsVecSize = pToppingsVec.size();

        helperUI.displayHeader();
        helperUI.displayBelowHeader("Ny pizza a matsedil");
        cout << endl;

        displayVector(pToppingsVec, true);

        //cout <<

        int newToppingID;

        cout << endl;
        cout << "Pizza " << choose_pizza << ": " << toppings << endl << endl;
        cout << "Sladu inn nytt alegg ";
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
    helperUI.displayBelowHeader("Ny pizza a matsedil");

    cout << endl;

    cout << "Sladu inn verd a Pizza " << choose_pizza << " sem hlutfall af grunn Pizzu: ";
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
}

void UmsjonUI::createNewPizzaExtras()
{
    helperUI.displayHeader();
    helperUI.displayBelowHeader("Ny tegund af medlaeti");

    cout << endl;
    helperUI.displayColumn("Heiti medlaetis", "Verd(kr.)");
    displayVector(u.getpextras(), false);
    helperUI.displayCloseTable();

    cout << endl;

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
}

void UmsjonUI::createNewPizzaLocation()
{
    helperUI.displayHeader();
    helperUI.displayBelowHeader("Nyr pizza stadur");

    cout << endl;
    helperUI.displayColumn("Stadsetning", "");
    displayVector(u.getplocations(), false);
    helperUI.displayCloseTable();

    cout << endl;

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
            helperUI.displayBelowHeader("Skra nyjar vorur");
            cout << endl;
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

            if(!cin || input < 1 || 7 < input)
            {
                throw InputErrorException("Inslattarvilla i vallista UmsjonUI");
            }

            if(input == 1)
            {
                createNewPizzaSize();
            }
            else if(input == 2)
            {
                createNewPizzaCrust();
            }
            else if(input == 3)
            {
                createNewPizzaTopping();
            }
            else if(input == 4)
            {
                createNewPizzaMenu();
            }
            else if(input == 5)
            {
                createNewPizzaExtras();
            }
            else if(input == 6)
            {
                createNewPizzaLocation();
            }
            else if(input == 7)
            {
                system("CLS");
                break;
            }
        }
        catch(InputErrorException e)
        {
            ErrorException er;
            er.logInputErrorException(e);
            cout << e.getMessage() << endl;
            system("pause");
            cin.clear();
            cin.ignore(INT_MAX,'\n');
        }
    }
}
