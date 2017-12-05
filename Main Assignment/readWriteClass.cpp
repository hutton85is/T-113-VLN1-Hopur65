#include "readWriteClass.h"

readWriteClass::readWriteClass()
{
    //ctor
}

readWriteClass::~readWriteClass()
{
    //dtor
}

void readWriteClass::loadAllVectors(Pizza& p)
{
    const char* fname = "data/crust.dat";
    PizzaCrust cr;
    loadSpecificVector(p.pcrust, fname, cr);

    fname = "data/extra.dat";
    PizzaExtras ex;
    loadSpecificVector<PizzaExtras>(p.pextras, fname, ex);

    fname = "data/locations.dat";
    PizzaLocations lc;
    loadSpecificVector<PizzaLocations>(p.plocations, fname, lc);

    fname = "data/size.dat";
    PizzaSize sz;
    loadSpecificVector<PizzaSize>(p.psize, fname, sz);

    fname = "data/toppings.dat";
    PizzaToppings top;
    loadSpecificVector<PizzaToppings>(p.ptoppings, fname, top);

    fname = "data/menu.dat";
    PizzaMenu menu;
    loadSpecificVector<PizzaMenu>(p.pmenu, fname, menu);
}

bool readWriteClass::loadCustomer(Pizza& order, client& customer, const char* fname)
{
    ifstream file;
    file.open(fname, ios_base::binary|ios_base::app);

    if(file.is_open())
    {
        // load client class
        file.read((char*)(&customer), sizeof(client));

        // load all toppings
        for(unsigned int i = 0; i < customer.toppingsCounter; i++)
        {
            PizzaToppings newtoppings;
            file.read((char*)(&newtoppings), sizeof(PizzaToppings));
            order.ptoppings.push_back(newtoppings);
        }

        // load pizzasize class
        PizzaSize newPizzaSize;
        file.read((char*)(&newPizzaSize), sizeof(PizzaSize));
        order.psize.push_back(newPizzaSize);

        // load PizzaCrust class
        PizzaCrust newPizzaCrust;
        file.read((char*)(&newPizzaCrust), sizeof(PizzaCrust));
        order.pcrust.push_back(newPizzaCrust);

        // load all extras
        for(unsigned int i = 0; i < customer.extrasCounter; i++)
        {
            PizzaExtras newExtras;
            file.read((char*)(&newExtras), sizeof(PizzaExtras));
            order.pextras.push_back(newExtras);
        }

        // load all menu
        for(unsigned int i = 0; i < customer.menuCounter; i++)
        {
            PizzaMenu newMenu;
            file.read((char*)(&newMenu), sizeof(PizzaMenu));
            order.pmenu.push_back(newMenu);
        }

        // load PizzaLocations class
        PizzaLocations newLocations;
        file.read((char*)(&newLocations), sizeof(PizzaLocations));
        order.plocations.push_back(newLocations);

        file.close();
        return true;
    }
    return false;
}

template <class pizzaClass>
bool readWriteClass::loadSpecificVector(vector<pizzaClass>& loadVector, const char* fileName, pizzaClass& pClass)
{
    ifstream file;
    file.open(fileName, ios_base::binary);

    if(file.is_open())
    {
        file.seekg(0, file.end);
        int records = file.tellg() / sizeof(pizzaClass);
        file.seekg(0, file.beg);

        for(int i = 0; i < records; i++)
        {
            file.read((char*)(&pClass), sizeof(pizzaClass));
            loadVector.push_back(pClass);
        }
        file.close();
        return true;
    }
    return false;
}

void readWriteClass::dummyLoader()
{
    PizzaToppings newToppings;
    PizzaCrust newCrust;
    PizzaMenu newMenu;
    PizzaExtras newExtras;
    PizzaLocations newLocations;
    PizzaSize newSize;
    client newClient;

    const char* fname = "s";
    writeClassToFile<PizzaCrust>(newCrust, fname);
    writeClassToFile<PizzaToppings>(newToppings, fname);
    writeClassToFile<PizzaSize>(newSize, fname);
    writeClassToFile<PizzaMenu>(newMenu, fname);
    writeClassToFile<PizzaLocations>(newLocations, fname);
    writeClassToFile<PizzaExtras>(newExtras, fname);
    writeClassToFile<client>(newClient, fname);
}

template <class pizzaClass>
void readWriteClass::writeClassToFile(pizzaClass& classToWrite, const char* fname)
{
    ofstream file;
    file.open(fname, ios_base::binary|ios_base::app);
    if(!file.is_open())
    {
        ifstream createfile;
        createfile.open(fname, ios_base::binary);
        createfile.close();
        file.open(fname, ios_base::binary|ios_base::app);
    }
    file.write((char*) (&classToWrite), sizeof(pizzaClass));
    file.close();
}
