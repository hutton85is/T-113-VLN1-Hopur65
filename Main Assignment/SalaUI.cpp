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
        cout << "Pizza pontun : " << i+1 << endl;

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

    cout << "Veldu stad til thess ad panta fra : ";
    cin >> input;

    s.enterLocation(input);

    while(true)
    {
        system("CLS");

        displayFullOrder(s);

        cout << "--------------------------------------------------" << endl;
        cout << "                  Pizzastadurinn!                 " << endl;
        cout << "--------------------------------------------------" << endl;
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
            displayVector(s.getLagerpsize(), true);

            cout << "Hvada staerd af pizzu ma bjoda ther : ";
            cin >> input;

            s.enterPizzaSize(input);
        }
        else if(input == 2)
        {
            displayVector(s.getLagerpcrust(), true);
            cout << endl;

            cout << "Hvernig crust ma bjoda ther : ";
            cin >> input;

            s.enterCrust(input);
        }
        else if(input == 3)
        {
            displayVector(s.getLagerptoppings(), true);
            cout << endl;

            cout << "Hvada alegg ma bjoda ther a pizzuna :  ";
            cin >> input;

            s.enterToppings(input);
        }
        else if(input == 4)
        {
            displayVector(s.getLagerpMenu(), true);
            cout << endl;

            cout << "Hvada pizzu af matsedli ma bjoda ther : ";
            cin >> input;

            s.enterMenu(input);
        }
        else if(input == 5)
        {
            displayVector(s.getLagerpextras(), true);
            cout << endl;

            cout << "Hvada medlaeti ma bjoda ther : ";
            cin >> input;

            s.enterExtras(input);
        }
        else if(input == 6)
        {
            //here I add everything to pizzavector and ask for another pizza
            s.newPizza();
        }
        else if(input == 7)
        {
            displayVector(s.getLagerplocations(), true);
            cout << endl;

            cout << "Hvada stadsetningu ma bjoda ther ad fa pizzuna fra : ";
            cin >> input;

            s.enterLocation(input);
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

            s.createOrder(name, address, number, paid == 'j', delivery == 'j');

            system("CLS");
            cout << "--------------------------------------------------" << endl;
            cout << "               HERNA ER PONTUNIN THIN             " << endl;
            cout << "--------------------------------------------------" << endl;
            cout << endl;
            displayFullOrder(s);
            cout << "--------------------------------------------------" << endl;
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


