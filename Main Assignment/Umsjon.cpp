#include "Umsjon.h"

Umsjon::Umsjon()
{
    p.loadFile(p);
}

Umsjon::~Umsjon()
{
    //dtor
}

void Umsjon::enterPizzaSize(char tmpSize[32], int tmpprice)
{
<<<<<<< HEAD
=======
    PizzaSize newSize;
<<<<<<< HEAD
>>>>>>> 91c2f4539886b891f330e0e805b450fc9c6c910a
    cout << "enter pizza size" << endl;
=======
    cout << "Enter pizza size" << endl;
>>>>>>> c21c3f09a7f5679a6b948cd0e2bc547bc4b06571
    cin >> newSize.p_size;
    cout << "Enter price of pizza size: " << newSize.p_size << endl;
    cin >> newSize.price;
    p.psize.push_back(newSize);
}

<<<<<<< HEAD
void Umsjon::enterCrust(char tmpSize[32], int tmpprice){

=======
void Umsjon::enterCrust()
{
    PizzaCrust newCrust;
>>>>>>> 91c2f4539886b891f330e0e805b450fc9c6c910a
    cout << "What kind of crust do you want: ";
    cin >> newCrust.crust_type;
    cout << "What is the price of " << newCrust.crust_type << endl;
    cin >> newCrust.price;
    p.menuCrust.push_back(newCrust);
}

<<<<<<< HEAD
void Umsjon::enterToppings(char tmpSize[32], int tmpprice){

    cout << "Enter toppings. If none press x: ";
    cin >> tempToppings;
    p.setToppings(tempToppings);
}

void Umsjon::enterMenu(char tmpSize[32], int tmpprice){
=======
void Umsjon::enterToppings()
{
    PizzaToppings newToppings;
    cout << "Enter toppings. If none press x: ";
    cin >> newToppings.toppings;
    cout << "What is the price of " << newToppings.toppings << endl;
    cin >> newToppings.price;
    p.menuToppings.push_back(newToppings);
>>>>>>> c21c3f09a7f5679a6b948cd0e2bc547bc4b06571

}

<<<<<<< HEAD
void Umsjon::enterExtras(char tmpSize[32], int tmpprice){
=======
void Umsjon::enterMenu()
{
    PizzaMenu newMenu;
    cout << "Enter a new pizza: ";
    cin >> newMenu.choose_pizza;
    cout << "What is the price of " << newMenu.choose_pizza << endl;
    cin >> newMenu.price;
    p.menuPizzas.push_back(newMenu);

}
>>>>>>> c21c3f09a7f5679a6b948cd0e2bc547bc4b06571

void Umsjon::enterExtras()
{
    PizzaExtras newExtra;
    cout << "Enter a new extra: ";
    cin >> newExtra.extras_type;
    cout << "What is the price of " << newExtra.extras_type << endl;
    cin >> newExtra.price;
    p.menuExtras.push_back(newExtra);

<<<<<<< HEAD
void Umsjon::enterLocation(char tmpSize[32], int tmpprice){
=======
}

void Umsjon::enterLocation()
{
    PizzaLocations newLocation;
    char yesOrno;
>>>>>>> c21c3f09a7f5679a6b948cd0e2bc547bc4b06571

    cout << "Enter new location: ";
    cin >> newLocation.pick_up;
    cout << "Do you want to get your order delivered? y or no? " << endl;
    cin << yesorno << endl;
    if ('y' == yesOrno)
    {
     cout << "We will be there soon with your warm pizza!" << endl;
     newLocation.pick_up = 1;
    }
    else
    {
     cout << "You can pick up your delicious pizza at " << newLocation.pick_up << endl;
     newLocation.pick_up = 0;
    }

    p.menuLocation.push_back(newLocation);

}
