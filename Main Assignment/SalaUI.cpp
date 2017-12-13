#include "SalaUI.h"


SalaUI::SalaUI()
{

}

SalaUI::~SalaUI()
{
    //dtor
}

void SalaUI::displayFullOrder(Sala s)
{

    client customer = s.getCustomerOrdersVector();

    if(customer.name[0] != '\0')
    {
        cout << customer << endl;
    }

    for(unsigned int i = 0; i < s.getOrder().size(); i++)
    {
        cout << "Pizza order " << i+1 << endl;

        cout << s.getOrder()[i] << endl;

        cout << endl;
    }
    cout << "************" << endl;
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

void SalaUI::mainOrder()
{
    unsigned int input;

    // Initiate variables
    s.newPizza();

    // Set location at the very beginning of SalaUI
    displayVector(s.getLagerplocations(), true);
    cout << endl;

    cout << "Enter what location you want to order from: ";
    cin >> input;

    s.enterLocation(input);

    while(true)
    {
        system("CLS");

        displayFullOrder(s);

        cout << "Skradu thina pontun : " << endl;
        cout << "Til thess ad velja pizza staerd veldu           1." << endl;
        cout << "Til thess ad velja pizza crust veldu            2." << endl;
        cout << "Til thess ad velja alegg a pizzuna veldu        3." << endl;
        cout << "Til thess ad velja pizzu af matsedli veldu      4." << endl;
        cout << "Til thess ad panta medlaeti veldu               5." << endl;
        cout << "Til thess ad baeta vid pizzu veldu              6." << endl;
        cout << "Til thess ad breyta afhendingarstad veldu       7." << endl;
        cout << "Til thess ad klara pöntun veldu                 8." << endl;
        cout << "Til thess ad haetta vid pontun veldu            9." << endl;
        //cout << "Til thess ad breyta pontun veldu                8." << endl;

        cin >> input;
        system("CLS");

    if(input == 1)
    {
        try
        {
            displayVector(s.getLagerpsize(), true);

            cout << "Enter what size pizza you would like: ";
            cin >> input;
            system("pause");

            if(!cin)
            {//athuga hvort input se int
                throw InputErrorException("Invalid input, on entering pizzasize");
            }
            s.enterPizzaSize(input);
        }

        catch(InputErrorException e)
        {
            Error er;
            er.logInputErrorException(e, "Exceptions/InputErrorException.dat");
            e.getMessage();
            system("pause");
        }
    }

        else if(input == 2)
        {
            try
            {
                displayVector(s.getLagerpcrust(), true);
                cout << endl;

                cout << "Enter what type of crust you would like: ";
                cin >> input;
                system("pause");

                if(!cin)
                {
                    throw InputErrorException("Invalid input, on entering pizzacrust");
                }
                s.enterCrust(input);
            }
            catch(InputErrorException e)
            {
                Error er;
                er.logInputErrorException(e, "Exceptions/InputErrorException.dat");
                e.getMessage();
                system("pause");
            }
        }
        else if(input == 3)
        {
            try
            {
                displayVector(s.getLagerptoppings(), true);
                cout << endl;

                cout << "What toppings would you like on your pizza: ";
                cin >> input;
                system("pause");

                if(!cin)
                {
                    throw InputErrorException("Invalid input, on entering toppings");
                }

                s.enterToppings(input);
            }
            catch(InputErrorException e)
            {
                Error er;
                er.logInputErrorException(e, "Exceptions/InputErrorException.dat");
                e.getMessage();
                system("pause");
            }
        }
        else if(input == 4)
        {
            try
            {
                displayVector(s.getLagerpMenu(), true);
                cout << endl;

                cout << "Enter what pizza you would like from the menu: ";
                cin >> input;
                system("pause");

                if(!cin)
                {
                    throw InputErrorException("Invalid choice on menu");
                }
                s.enterMenu(input);
            }
            catch(InputErrorException e)
            {
                Error er;
                er.logInputErrorException(e, "Exceptions/InputErrorException.dat");
                e.getMessage();
                system("pause");
            }
        }
        else if(input == 5)
        {
            try
            {
            displayVector(s.getLagerpextras(), true);
            cout << endl;

            cout << "Enter what extras you would like: ";
            cin >> input;
            system("pause");

            if(!cin)
            {
                throw InputErrorException("Invalid input on extras");
            }
            s.enterExtras(input);
            }
            catch(InputErrorException e)
            {
                Error er;
                er.logInputErrorException(e, "Exceptions/InputErrorException.dat");
                e.getMessage();
                system("pause");
            }
        }
        else if(input == 6)
        {
            //here I add everything to pizzavector and ask for another pizza
            s.newPizza();
        }
        else if(input == 7)
        {
            try
            {
            displayVector(s.getLagerplocations(), true);
            cout << endl;

            cout << "Enter what location you want to order from: ";
            cin >> input;
            system("Pause");

            if(!cin)
            {
                throw InputErrorException("Invalid input on location");
            }
            s.enterLocation(input);
            }
            catch(InputErrorException e)
            {
                Error er;
                er.logInputErrorException(e, "Exceptions/InputErrorException.dat");
                e.getMessage();
                system("pause");
            }
        }
        else if(input == 8)
        {
            string name;
            cout << "Hvada nafn a ad vera a pontuninni: ";
            cin >> ws;
            getline(cin, name);

            string address;
            cout << "A hvada heimilisfang a ad skra pontunina: ";
            cin >> address;

            int number;
            cout << "Hvert er husnumerid: ";
            cin >> number;

            char paid;
            cout << "A ad borga pontunina strax j/n: ";
            cin >> paid;

            char delivery;
            cout << "Viltu fa heimsendingu? j/n" << endl;
            cin >> delivery;

            char ans;
            string comment = "";
            cout << "Viltu skra athugasemd med pontun? j/n" << endl;
            cin >> ans;
            if(ans == 'j'){

                cout << "Skradu inn athugasemd: ";
                cin >> ws;
                getline(cin, comment);
            }

            s.createOrder(name, address, number, paid == 'j', delivery == 'j', comment);

            system("CLS");
            cout << "HERE IS YOUR ORDER" << endl;
            cout << "----------------------------" << endl;
            displayFullOrder(s);
            cout << "----------------------------" << endl;
            cout << endl;
            cout << endl;
            cout << endl;

            system("pause");
            break;
        }
        else if (input == 9)
        {
            break;
        }
        system("CLS");
    }
}


