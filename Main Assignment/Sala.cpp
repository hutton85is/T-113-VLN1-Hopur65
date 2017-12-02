#include "Sala.h"

Sala::Sala()
{
    lager.loadAllVectors(lager);
}

Sala::~Sala()
{
    //dtor
}

void Sala::enterPizzaSize(){

    PizzaSize newSize;

    cout << "What size do you want? " << endl;
    for (unsigned int i = 0; i < lager.psize.size(); i++)
    {
        cout << i << " : " << lager.psize[i].p_size << " " << lager.psize[i].price << endl;
    }

    cin >> newSize.p_size;
    unsigned int i = 0;
    for (; i < lager.psize.size() || newSize.p_size == lager.psize[i].p_size; i++)

    if (i != lager.psize.size())
    {
        order.psize.push_back(lager.psize[i]);
    }
    else{
        cout << "Nothing available at the moment" << endl;
    }
}

void Sala::enterCrust(){

    PizzaCrust newCrust;

    cout << "What kind of crust would you like? ";
    for (unsigned int i = 0; i < lager.pcrust.size(); i++)
    {
        cout << i << " : " << lager.pcrust[i].crust_type << " " << lager.pcrust[i].price << endl;
    }

    cin >> newCrust.crust_type;
    unsigned int i = 0;
    for (; i < lager.pcrust.size() || newCrust.crust_type == lager.pcrust[i].crust_type; i++)

        if(i != lager.pcrust.size())
        {
        order.pcrust.push_back(lager.pcrust[i]);
        }
        else{
            cout << "Nothing available at the moment" << endl;
        }

}

void Sala::enterToppings(){

    PizzaToppings newToppings;

    cout << "Enter toppings. If none press x: ";
    for(unsigned int i = 0; i < lager.ptoppings.size(); i++)
    {
        cout << i << " : " << lager.ptoppings[i].toppings << " " << lager.ptoppings[i].price << endl;
    }
    cin >> newToppings.toppings;
    unsigned int i = 0;
    for (; i < lager.ptoppings.size() || newToppings.toppings == lager.ptoppings[i].toppings; i++)

        if(i != lager.ptoppings.size())
        {
          order.ptoppings.push_back(lager.ptoppings[i]);
        }
        else{
            cout << "Nothing available at the moment" << endl;
        }

}

void Sala::enterMenu(){

    PizzaMenu newMenu;

    cout << "Check out our menu and choose your pizza";
    for (unsigned int i = 0; i < lager.pmenu.size(); i++)
    {
        cout << i << " : " << lager.pmenu[i].choose_pizza << " " << lager.pmenu[i].price << endl;
    }
    cin >> newMenu.choose_pizza;
    unsigned int i = 0;
    for (; i < lager.pmenu.size() || newMenu.choose_pizza == lager.pmenu[i].choose_pizza; i++)

        if(i != lager.pmenu.size())
        {
          order.pmenu.push_back(lager.pmenu[i]);
        }
        else{
            cout << "Nothing available at the moment" << endl;
        }
}

void Sala::enterExtras(){

    PizzaExtras newExtra;

    cout << "Would you like any extras? ";
    for (unsigned int i = 0; i < lager.pextras.size(); i++)
    {
        cout << i << " i " << lager.pextras[i].extras_type << " " << lager.pextras[i].price << endl;
    }

    cin >> newExtra.extras_type;
    unsigned int i = 0;
    for (; i < lager.pextras.size() || newExtra.extras_type == lager.pextras[i].extras_type; i++)

    if(i != lager.pextras.size())
    {
       order.pextras.push_back(lager.pextras[i]);
    }
    else{
        cout << "Nothing available at the moment" << endl;
    }

}

void Sala::enterLocation(){

    PizzaLocations newLocation;
    int choose;
    char yn;
    cout << "Choose your location." << endl;
    for(unsigned int i = 0; i < lager.plocations.size();i++){
        cout << i;
        cout << lager.plocations[i].place << endl;
    }
    cin >> choose;
    newLocation = lager.plocations[choose];

    cout << "Do you want to get your order delivered? yes or no? " << endl;
    cin >> yn;
    if ('y' == yn)
    {
     cout << "We will be there soon with your warm pizza!" << endl;
     newLocation.pick_up = 1;
    }
    else
    {
     cout << "You can pick up your delicious pizza at " << order.plocations[choose] << endl;
     newLocation.pick_up = 0;
    }
    order.plocations.push_back(newLocation);
}



