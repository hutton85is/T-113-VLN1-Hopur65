#include "SalaUI.h"


SalaUI::SalaUI()
{

}

void SalaUI::choosePizzaSize()
{
    displayVector(s.getLagerpsize(), true);

    int input;

    cout << "Sladu inn hvada staerd af pizzu thu vilt: ";
    cin >> input;

    if(!cin)
    {
        throw InputErrorException("Innslattarvilla a pizzustaerd");
    }

    s.enterPizzaSize(input);
}

void SalaUI::choosePizzaCrust()
{
    helperUI.displayHeader();

    vector<PizzaCrust> PizzaCrustVec = s.getLagerpcrust();

    if(PizzaCrustVec.size())
    {
        displayVector(PizzaCrustVec, true);

        int input;

        cout << endl;
        cout << "Sladu inn hvernig pizza botn thu vilt: ";
        cin >> input;

        if(!cin)
        {
            throw InputErrorException("Innslattarvilla a pizzubotn");
        }

        s.enterCrust(input);
    }
    else
    {
        helperUI.displayHeader();

        cout << "Thad er engin Pizza botn i bodi enntha" << endl;
        cout << endl;
        system("pause");
    }
}

void SalaUI::choosePizzaTopping()
{
    helperUI.displayHeader();

    vector<PizzaToppings> PizzaToppingsVec = s.getLagerptoppings();

    if(PizzaToppingsVec.size())
    {
        displayVector(s.getLagerptoppings(), true);

        int input;

        cout << endl;
        cout << "Hvernig alegg ma bjoda ther a pizzuna: ";
        cin >> input;

        if(!cin)
        {
            throw InputErrorException("Innslattarvilla a aleggi");
        }

        s.enterToppings(input);
    }
    else
    {
        cout << "Thad eru engin alegg i bodi enntha" << endl;
        cout << endl;
        system("pause");
    }
}

void SalaUI::choosePizzaMenu()
{
    helperUI.displayHeader();

    vector<PizzaMenu> PizzaMenuVec = s.getLagerpMenu();

    // If pizza size has not been entered, do it now before adding pizza from the menu
    if(s.getOrder()[s.getClient().orderCounter - 1].psize.empty())
    {
        choosePizzaSize();
    }
    else if(PizzaMenuVec.size())
    {
        displayVector(s.getLagerpMenu(), true);

        int input;

        cout << endl;
        cout << "Hvernig pizzu viltu af matsedli: ";
        cin >> input;

        if(!cin)
        {
            throw InputErrorException("Innslattarvilla a vali a matsedli");
        }

        s.enterMenu(input);
    }
    else
    {
        helperUI.displayHeader();
        cout << "Thad er engin pizza a matsedli i bodi enntha" << endl;
        cout << endl;
        system("pause");
    }
}

void SalaUI::choosePizzaExtras()
{
    helperUI.displayHeader();

    vector<PizzaExtras> PizzaExtrasVec = s.getLagerpextras();

    if(PizzaExtrasVec.size())
    {
        displayVector(s.getLagerpextras(), true);

        int input;

        cout << endl;
        cout << "Hvada medlaeti ma bjoda ther: ";
        cin >> input;

        if(!cin)
        {
            throw InputErrorException("Innslattarvilla a medlaeti");
        }

        s.enterExtras(input);
    }
    else
    {
        helperUI.displayHeader();
        cout << "Thad er ekkert medlaeti i bodi enntha" << endl;
        cout << endl;
    }
}

void SalaUI::chooseDifferentPizzaLocation()
{
    helperUI.displayHeader();

    vector<PizzaLocations> PizzaLocationsVec = s.getLagerplocations();

    if(PizzaLocationsVec.size())
    {
        displayVector(s.getLagerplocations(), true);

        int input;

        cout << endl;

        cout << "Sladu inn stadsetningu sem thu vilt panta fra: ";
        cin >> input;

        if(!cin)
        {
            throw InputErrorException("Innslattarvilla a vali a stadsetningu");
        }

        s.enterLocation(input);
    }
    else
    {
        helperUI.displayHeader();
        cout << endl;
        cout << "That er enginn stadur opnadur enntha" << endl;
        cout << endl;
    }
}

void SalaUI::finishOrder()
{
    helperUI.displayHeader();
    string name;
    cout << "Hvada nafn a ad vera a pontuninni: ";
    cin >> ws;
    getline(cin, name);
    if(!cin)
    {
        throw InputErrorException("Innslattarvilla a nafni");
    }

    string address;
    cout << "A hvada heimilisfang a ad skra pontunina: ";
    cin >> address;
    if(!cin)
    {
        throw InputErrorException("Innslattarvilla a heimilisfangi");
    }

    int number;
    cout << "Hvert er husnumerid: ";
    cin >> number;
    if(!cin)
    {
        throw InputErrorException("Innslattarvilla a husnumeri");
    }

    char paid;
    cout << "A ad borga pontunina strax j/n: ";
    cin >> paid;
    if(!cin)
    {
        throw InputErrorException("Innslattarvilla a vali um borgun");
    }

    char delivery;
    cout << "Viltu fa heimsendingu? j/n" << endl;
    cin >> delivery;
    if(!cin)
    {
        throw InputErrorException("Innslattarvilla a vali a heimsendingu");
    }

    char ans;
    string comment = "";
    cout << "Viltu skra athugasemd med pontun? j/n   : " ;
    cin >> ans;
    if(!cin)
    {
        throw InputErrorException("Innslattarvilla a vali um athugasemd");
    }
    if(ans == 'j')
    {
        cout << "Skradu inn athugasemd: ";
        cin >> ws;
        getline(cin, comment);
        if(!cin)
        {
            throw InputErrorException("Innslattarvilla a athugasemd");
        }
    }

    s.createOrder(name, address, number, paid == 'j', delivery == 'j', comment);

    system("CLS");
    cout << "HERE IS YOUR ORDER" << endl;
    cout << "----------------------------" << endl;
    cout << s << endl;
    cout << "----------------------------" << endl;
    cout << endl;
    cout << endl;

    system("pause");
}

template<typename Pizzaclass>
void SalaUI::displayVector(vector<Pizzaclass> vec, bool choice)
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

void SalaUI::choosePizzaLocation()
{
    int input;

    // Initiate variables
    s.newPizza();

    helperUI.displayHeader();

    // Set location at the very beginning of SalaUI
    displayVector(s.getLagerplocations(), true);
    cout << endl;

    cout << "Enter what location you want to order from: ";
    cin >> input;

    int lagerLocationsVecSize = s.getLagerplocations().size();

    if(!cin || input < 0 || input > lagerLocationsVecSize - 1)
    {
        throw InputErrorException("Innslattarvilla a stadsetningu");
    }

    s.enterLocation(input);
}

void SalaUI::mainOrder()
{   try
    {
        choosePizzaLocation();
    }
    catch(InputErrorException e)
    {
        Error er;
        er.logInputErrorException(e, "Exceptions/InputErrorException.dat");
        cout << e.getMessage() << endl;
        system("pause");
        cin.clear();
        cin.ignore(INT_MAX,'\n');

        system("CLS");

        choosePizzaLocation();
    }
    while(true)
    {
        int input;

        try
        {
            system("CLS");

            helperUI.displayHeader();

            cout << endl;
            cout << s << endl;
            cout << endl;

            cout << "Skradu thina pontun : " << endl;
            cout << "Til thess ad velja pizza staerd veldu           1." << endl;
            cout << "Til thess ad velja pizza botn veldu             2." << endl;
            cout << "Til thess ad velja alegg a pizzuna veldu        3." << endl;
            cout << "Til thess ad velja pizzu af matsedli veldu      4." << endl;
            cout << "Til thess ad panta medlaeti veldu               5." << endl;
            cout << "Til thess ad baeta vid pizzu veldu              6." << endl;
            cout << "Til thess ad breyta afhendingarstad veldu       7." << endl;
            cout << "Til thess ad klara pöntun veldu                 8." << endl;
            cout << "Til thess ad haetta vid pontun veldu            9." << endl;

            cout << endl;

            cout << "Veldu herna: ";

            cin >> input;

            system("CLS");

            if(!cin || input < 0 || input > 9)
            {
                throw InputErrorException("Innslattarvilla i vallista SalaUI");
            }

            if(input == 1)
            {
                choosePizzaSize();
            }

            else if(input == 2)
            {
                choosePizzaCrust();
            }
            else if(input == 3)
            {
                choosePizzaTopping();
            }
            else if(input == 4)
            {
                choosePizzaMenu();
            }
            else if(input == 5)
            {
                choosePizzaExtras();
            }
            else if(input == 6)
            {
                s.newPizza();
            }
            else if(input == 7)
            {
                chooseDifferentPizzaLocation();
            }
            else if(input == 8)
            {
                finishOrder();
                break;
            }
            else if (input == 9)
            {
                break;
            }
            system("CLS");
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


