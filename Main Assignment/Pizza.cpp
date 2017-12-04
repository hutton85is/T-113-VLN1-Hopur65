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
    const char* fname = "data/crust.dat";
    PizzaCrust cr;
    loadSpecificVector<PizzaCrust>(p.pcrust, fname, cr);

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

template <typename pizzaClass>
bool Pizza::loadSpecificVector(vector<pizzaClass>& loadVector, const char* fileName, pizzaClass& pClass)
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

template <typename pizzaClass>
void Pizza::writeSpecificClassToFile(pizzaClass& classToWrite, const char* fname)
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

/*Afhverju þarf þetta að vera, það er aldrei kallað í þetta fall en það
* kemur reference villa þegar reynt er að kalla í writeClassToFile
* fallið ef þetta er ekki*/
void Pizza::loaderDummy()
{
    PizzaToppings newToppings;
    PizzaCrust newCrust;
    PizzaMenu newMenu;
    PizzaExtras newExtras;
    PizzaLocations newLocations;
    PizzaSize newSize;

    const char* fname = "s";
    writeSpecificClassToFile<PizzaCrust>(newCrust, fname);
    writeSpecificClassToFile<PizzaToppings>(newToppings, fname);
    writeSpecificClassToFile<PizzaSize>(newSize, fname);
    writeSpecificClassToFile<PizzaMenu>(newMenu, fname);
    writeSpecificClassToFile<PizzaLocations>(newLocations, fname);
    writeSpecificClassToFile<PizzaExtras>(newExtras, fname);
}
