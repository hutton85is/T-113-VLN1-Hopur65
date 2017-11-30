#include "Pizza.h"

Pizza::Pizza()
{
}

Pizza::~Pizza()
{
    //dtor
}

bool Pizza::loadFile(Pizza& p)
{
    ifstream file;
    file.open("pizza.txt");
    if(file.is_open())
    {
        file >> p;
        file.close();
        return true;
    }
    return false;
}

istream& operator >>(istream &ins, Pizza& p)
{
    //cin >> ins;
    return ins;
}

void Pizza::writePizzaToppings(PizzaToppings& ptop)
{
    ofstream file;
    file.open("/data/toppings", ios_base::binary|ios_base::app);
    file.write((char*)(&ptop), sizeof(PizzaToppings));
    file.close();
}
