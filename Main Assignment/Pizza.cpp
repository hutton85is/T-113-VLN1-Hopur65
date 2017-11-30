#include "Pizza.h"

Pizza::Pizza()
{
}

Pizza::~Pizza()
{
    //dtor
}

bool Pizza::loadVectors(Pizza& p)
{
    PizzaToppings pTop;
    ifstream file;
    file.open("data/toppings.dat", ios_base::binary);

    if(file.is_open())
    {
        file.seekg(0, file.end);
        int records = file.tellg() / sizeof(PizzaToppings);
        file.seekg(0, file.beg);

        for(int i = 0; i < records; i++)
        {
            file.read((char*)(&pTop), sizeof(PizzaToppings));
            p.ptoppings.push_back(pTop);
        }
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
    file.open("data/toppings.dat", ios_base::binary|ios_base::app);
    file.write((char*)(&ptop), sizeof(PizzaToppings));
    file.close();
}
