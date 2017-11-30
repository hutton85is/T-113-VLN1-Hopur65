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
>>>>>>> 91c2f4539886b891f330e0e805b450fc9c6c910a
    cout << "enter pizza size" << endl;
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
    p.psize.push_back(newCrust);
}

void Umsjon::enterToppings(char tmpSize[32], int tmpprice){

    cout << "Enter toppings. If none press x: ";
    cin >> tempToppings;
    p.setToppings(tempToppings);
}

void Umsjon::enterMenu(char tmpSize[32], int tmpprice){

    cout << "Enter a new pizza: ";
    cin >> tempMenu;
    p.setPizzas(tempMenu);
}

void Umsjon::enterExtras(char tmpSize[32], int tmpprice){

    cout << "Enter a new extra: ";
    cin >> tempExtras;
    p.setExtrax(tempExtras);
}

void Umsjon::enterLocation(char tmpSize[32], int tmpprice){

    cout << "Enter new location: ";
    cin >> tempLocation;
    p.setLocation(tempLocation);
}
