#include "Sala.h"

Sala::Sala()
{
    lager.loadFile(lager);
}

Sala::~Sala()
{
    //dtor
}

void Sala::enterPizzaSize(){

    PizzaSize newSize;
    cout << "What size do you want? " << endl;
    cin >> newSize.p_size;
    unsigned int i = 0;
    for (; i < lager.psize.size() || newSize.p_size == lager.psize[i].p_size; i++);
    order.psize.push_back(lager.psize[i]);
}

void Sala::enterCrust(){

    PizzaCrust newCrust;
    cout << "What kind of crust would you like? ";
    cin >> newCrust.crust_type;
    unsigned int i = 0;
    for (; i < lager.pcrust.size() || newCrust.crust_type == lager.pcrust[i].crust_type; i++)
    order.pcrust.push_back(lager.pcrust[i]);
}

void Sala::enterToppings(){

    PizzaToppings newToppings;
    cout << "Enter toppings. If none press x: ";
    cin >> newToppings.toppings;
    unsigned int i = 0;
    for (; i < lager.ptoppings.size() || newToppings.toppings == lager.ptoppings[i].toppings; i++)
    order.ptoppings.push_back(lager.ptoppings[i]);
}

void Sala::enterMenu(){

    PizzaMenu newMenu;
    cout << "Check out our menu and choose your pizza";
    cin >> newMenu.choose_pizza;
    unsigned int i = 0;
    for (; i < lager.pmenu.size() || newMenu.choose_pizza == lager.pmenu[i].choose_pizza; i++)
    order.pmenu.push_back(lager.pmenu[i]);
}

void Sala::enterExtras(){

    PizzaExtras newExtra;
    cout << "Would you like any extras? ";
    cin >> newExtra.extras_type;
    unsigned int i = 0;
    for (; i < lager.pextras.size() || newExtra.extras_type == lager.pextras[i].extras_type; i++);
    order.pextras.push_back(lager.pextras[i]);
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
    newLocation = order.plocations[choose];

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



