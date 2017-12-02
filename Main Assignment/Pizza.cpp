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
}

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

template <typename pizzaClass, typename filename>
void Pizza::writeClassToFile(pizzaClass& classToWrite, filename fname)
{
    ofstream file;
    string name(fname.begin(), fname.end());
    file.open(fname, ios_base::binary|ios_base::app);
    if(!file.is_open())
    {
        ifstream createFile;
        createFile.open(fname, ios_base::binary);
        createFile.close();
        file.open(fname, ios_base::binary|ios_base::app);
    }
    file.write((char*)(&classToWrite), sizeof(pizzaClass));
    file.close();
}
/*
void Pizza::writeToppingsVector(PizzaToppings& wToppings)
{
    ofstream file;
    file.open("data/toppings.dat", ios_base::binary|ios_base::app);
    if(!file.is_open())
    {
        ifstream createFile;
        createFile.open("data/toppings.dat", ios_base::binary);
        createFile.close();
        file.open("data/toppings.dat", ios_base::binary|ios_base::app);
    }
    file.write((char*)(&wToppings), sizeof(PizzaToppings));
    file.close();
}

void Pizza::writeCrustVector(PizzaCrust& wCrust)
{
    ofstream file;
    file.open("data/crust.dat", ios_base::binary|ios_base::app);
    if(!file.is_open())
    {
        ifstream createFile;
        createFile.open("data/crust.dat", ios_base::binary);
        createFile.close();
        file.open("data/crust.dat", ios_base::binary|ios_base::app);
    }
    file.write((char*)(&wCrust), sizeof(PizzaCrust));
    file.close();
}

void Pizza::writeSizeVector(PizzaSize& wSize)
{
    ofstream file;
    file.open("data/size.dat", ios_base::binary|ios_base::app);
    if(!file.is_open())
    {
        ifstream createFile;
        createFile.open("data/size.dat", ios_base::binary);
        createFile.close();
        file.open("data/size.dat", ios_base::binary|ios_base::app);
    }
    file.write((char*)(&wSize), sizeof(PizzaSize));
    file.close();
}

void Pizza::writeExtrasVector(PizzaExtras& wExtras)
{
    ofstream file;
    file.open("data/extras.dat", ios_base::binary|ios_base::app);
    if(!file.is_open())
    {
        ifstream createFile;
        createFile.open("data/extras.dat", ios_base::binary);
        createFile.close();
        file.open("data/extras.dat", ios_base::binary|ios_base::app);
    }
    file.write((char*)(&wExtras), sizeof(PizzaExtras));
    file.close();
}

void Pizza::writeMenuVector(PizzaMenu& wMenu)
{
    ofstream file;
    file.open("data/menu.dat", ios_base::binary|ios_base::app);
    if(!file.is_open())
    {
        ifstream createFile;
        createFile.open("data/menu.dat", ios_base::binary);
        createFile.close();
        file.open("data/menu.dat", ios_base::binary|ios_base::app);
    }
    file.write((char*)(&wMenu), sizeof(PizzaMenu));
    file.close();
}

void Pizza::writeLocationsVector(PizzaLocations& wLocation)
{
    ofstream file;
    file.open("data/locations.dat", ios_base::binary|ios_base::app);
    if(!file.is_open())
    {
        ifstream createFile;
        createFile.open("data/locations.dat", ios_base::binary);
        createFile.close();
        file.open("data/locations.dat", ios_base::binary|ios_base::app);
    }
    file.write((char*)(&wLocation), sizeof(PizzaLocations));
    file.close();
}
*/
