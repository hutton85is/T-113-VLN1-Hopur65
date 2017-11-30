#include "Pizza.h"

Pizza::Pizza()
{
}

Pizza::~Pizza()
{
    //dtor
}
/*
void Pizza::displaySize(vector <pizzaSize>& vec)
{

}
*/
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

void Pizza::writeFile(Pizza& p)
{
    ofstream file;
    file.open("/data/pizzaSize", ios_base::binary);
    for (unsigned int i = 0; i < p.ptoppings.size(); i++)
    {
        file.write((char*)(&p.ptoppings[i]), sizeof(PizzaToppings));
    }
    file.close();
}
