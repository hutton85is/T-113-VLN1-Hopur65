#include "Pizza.h"

Pizza::Pizza()
{
}

Pizza::~Pizza()
{
    //dtor
}

void Pizza::loadAllVectors(Pizza& p)
{
    loadCrustVector(p);
    loadExtrasVector(p);
    loadLocationsVector(p);
    loadSizeVector(p);
    loadToppingsVector(p);
    loadMenuVector(p);
    //loadSpecificVector(p, sizeof(PizzaCrust), "crust", PizzaCrust p);
}

/*template <typename pizzaClass>
bool Pizza::loadSpecificVector(Pizza& p, unsigned int classSize, string fileName, pizzaClass pSize)
{
    //p.psize
    //PizzaSize pSize;
    PizzaClass pSize;
    ifstream file;
    file.open("data/" + fileName + ".dat", ios_base::binary);

    if(file.is_open())
    {
        file.seekg(0, file.end);
        int records = file.tellg() / sizeof(classSize);
        file.seekg(0, file.beg);

        for(int i = 0; i < records; i++)
        {
            file.read((char*)(&pSize), sizeof(classSize));
            p.psize.push_back(pSize);
        }
        file.close();
        return true;
    }
    return false;
}*/

bool Pizza::loadSizeVector(Pizza& p)
{
    PizzaSize pSize;
    ifstream file;
    file.open("data/size.dat", ios_base::binary);

    if(file.is_open())
    {
        file.seekg(0, file.end);
        int records = file.tellg() / sizeof(PizzaSize);
        file.seekg(0, file.beg);

        for(int i = 0; i < records; i++)
        {
            file.read((char*)(&pSize), sizeof(PizzaSize));
            p.psize.push_back(pSize);
        }
        file.close();
        return true;
    }
    return false;
}

bool Pizza::loadCrustVector(Pizza& p)
{
    PizzaCrust pCrust;
    ifstream file;
    file.open("data/crust.dat", ios_base::binary);

    if(file.is_open())
    {
        file.seekg(0, file.end);
        int records = file.tellg() / sizeof(PizzaCrust);
        file.seekg(0, file.beg);

        for(int i = 0; i < records; i++)
        {
            file.read((char*)(&pCrust), sizeof(PizzaCrust));
            p.pcrust.push_back(pCrust);
        }
        file.close();
        return true;
    }
    return false;
}

bool Pizza::loadExtrasVector(Pizza& p)
{
    PizzaExtras pExtras;
    ifstream file;
    file.open("data/extras.dat", ios_base::binary);

    if(file.is_open())
    {
        file.seekg(0, file.end);
        int records = file.tellg() / sizeof(PizzaExtras);
        file.seekg(0, file.beg);

        for(int i = 0; i < records; i++)
        {
            file.read((char*)(&pExtras), sizeof(PizzaExtras));
            p.pextras.push_back(pExtras);
        }
        file.close();
        return true;
    }
    return false;
}

bool Pizza::loadMenuVector(Pizza& p)
{
    PizzaMenu pMenu;
    ifstream file;
    file.open("data/menu.dat", ios_base::binary);

    if(file.is_open())
    {
        file.seekg(0, file.end);
        int records = file.tellg() / sizeof(PizzaMenu);
        file.seekg(0, file.beg);

        for(int i = 0; i < records; i++)
        {
            file.read((char*)(&pMenu), sizeof(PizzaMenu));
            p.pmenu.push_back(pMenu);
        }
        file.close();
        return true;
    }
    return false;
}

bool Pizza::loadLocationsVector(Pizza& p)
{
    PizzaLocations pLocation;
    ifstream file;
    file.open("data/locations.dat", ios_base::binary);

    if(file.is_open())
    {
        file.seekg(0, file.end);
        int records = file.tellg() / sizeof(PizzaLocations);
        file.seekg(0, file.beg);

        for(int i = 0; i < records; i++)
        {
            file.read((char*)(&pLocation), sizeof(PizzaLocations));
            p.plocations.push_back(pLocation);
        }
        file.close();
        return true;
    }
    return false;
}

bool Pizza::loadToppingsVector(Pizza& p)
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

void Pizza::writeToppingsVector(PizzaToppings& wToppings)
{
    ofstream file;
    file.open("data/toppings.dat", ios_base::binary|ios_base::app);
    file.write((char*)(&wToppings), sizeof(PizzaToppings));
    file.close();
}

void Pizza::writeCrustVector(PizzaCrust& wCrust)
{
    ofstream file;
    file.open("data/crust.dat", ios_base::binary|ios_base::app);
    file.write((char*)(&wCrust), sizeof(PizzaCrust));
    file.close();
}

void Pizza::writeSizeVector(PizzaSize& wSize)
{
    ofstream file;
    file.open("data/size.dat", ios_base::binary|ios_base::app);
    file.write((char*)(&wSize), sizeof(PizzaSize));
    file.close();
}

void Pizza::writeExtrasVector(PizzaExtras& wExtras)
{
    ofstream file;
    file.open("data/extras.dat", ios_base::binary|ios_base::app);
    file.write((char*)(&wExtras), sizeof(PizzaExtras));
    file.close();
}

void Pizza::writeMenuVector(PizzaMenu& wMenu)
{
    ofstream file;
    file.open("data/menu.dat", ios_base::binary|ios_base::app);
    file.write((char*)(&wMenu), sizeof(PizzaMenu));
    file.close();
}

void Pizza::writeLocationsVector(PizzaLocations& wLocation)
{
    ofstream file;
    file.open("data/locations.dat", ios_base::binary|ios_base::app);
    file.write((char*)(&wLocation), sizeof(PizzaLocations));
    file.close();
}
