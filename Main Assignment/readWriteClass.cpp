#include "ReadWriteClass.h"

ReadWriteClass::ReadWriteClass()
{
<<<<<<< HEAD

=======

}

ReadWriteClass::~ReadWriteClass()
{

>>>>>>> f926114eaccea4974aa372e72f4890ab6b25fabd
}

void ReadWriteClass::loadAllVectors(Pizza& p)
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

bool ReadWriteClass::loadCustomer(Client& customer, vector<Pizza>& order, vector<PizzaHelper>& pHelper, const char* fname)
{
    ifstream file;
    file.open(fname, ios_base::binary|ios_base::app);

    if(file.is_open())
    {
        // load customer from file
        file.read((char*)(&customer), sizeof(Client));

        for(unsigned int j = 0; j < customer.orderCounter; j++)
        {
            // Load helper class for storing how many items are in the order
            PizzaHelper newPizzaHelper;
            file.read((char*)(&newPizzaHelper), sizeof(PizzaHelper));
            pHelper.push_back(newPizzaHelper);

            //Add empty pizza order to fill in
            Pizza newPizza;
            order.push_back(newPizza);

            // load all toppings if there are any
            if (pHelper[j].toppingsCounter)
            {
                for(unsigned int i = 0; i < pHelper[j].toppingsCounter; i++)
                {
                    PizzaToppings newtoppings;
                    file.read((char*)(&newtoppings), sizeof(PizzaToppings));

                    order[j].ptoppings.push_back(newtoppings);
                }
            }

            // load pizzasize class if there is one
            if(pHelper[j].sizeCounter)
            {
                for(unsigned int i = 0; i < pHelper[j].sizeCounter; i++)
                {
                    PizzaSize newPizzaSize;
                    file.read((char*)(&newPizzaSize), sizeof(PizzaSize));

                    order[j].psize.push_back(newPizzaSize);
                }
            }

            // load PizzaCrust class if there is one
            if(pHelper[j].crustCounter)
            {
                for(unsigned int i = 0; i < pHelper[j].crustCounter; i++)
                {
                    PizzaCrust newPizzaCrust;
                    file.read((char*)(&newPizzaCrust), sizeof(PizzaCrust));
                    order[j].pcrust.push_back(newPizzaCrust);
                }
            }

            // load all extras if there are some
            if(pHelper[j].extrasCounter)
            {
                for(unsigned int i = 0; i < pHelper[j].extrasCounter; i++)
                {
                    PizzaExtras newExtras;
                    file.read((char*)(&newExtras), sizeof(PizzaExtras));
                    order[j].pextras.push_back(newExtras);
                }
            }


            // load all menu pizzas if there are some
            if(pHelper[j].menuCounter)
            {
                for(unsigned int i = 0; i < pHelper[j].menuCounter; i++)
                {
                    PizzaMenu newMenu;
                    file.read((char*)(&newMenu), sizeof(PizzaMenu));
                    order[j].pmenu.push_back(newMenu);
                }
            }

            // load PizzaLocations class if there is one
            if(pHelper[j].locationCounter)
            {
                for(unsigned int i = 0; i < pHelper[j].locationCounter; i++)
                {
                    PizzaLocations newLocations;
                    file.read((char*)(&newLocations), sizeof(PizzaLocations));
                    order[j].plocations.push_back(newLocations);
                }
            }
        }
        file.close();
        return true;
    }
    return false;
}

void ReadWriteClass::removeAllContentsOfFile(const char* fname)
{
    ofstream file;
    file.open(fname);
    file.close();
}

template <class pizzaClass>
bool ReadWriteClass::loadSpecificVector(vector<pizzaClass>& loadVector, const char* fileName, pizzaClass& pClass)
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

void ReadWriteClass::dummyLoader()
{
    PizzaToppings newToppings;
    PizzaCrust newCrust;
    PizzaMenu newMenu;
    PizzaExtras newExtras;
    PizzaLocations newLocations;
    PizzaSize newSize;
    Client newClient;
    PizzaHelper newPizzaHelper;
    InputErrorException newInputErrorException;

    const char* fname = "s";
    writeClassToFile<PizzaCrust>(newCrust, fname);
    writeClassToFile<PizzaToppings>(newToppings, fname);
    writeClassToFile<PizzaSize>(newSize, fname);
    writeClassToFile<PizzaMenu>(newMenu, fname);
    writeClassToFile<PizzaLocations>(newLocations, fname);
    writeClassToFile<PizzaExtras>(newExtras, fname);
    writeClassToFile<Client>(newClient, fname);
    writeClassToFile<InputErrorException>(newInputErrorException, fname);
    vector<Client> loadVector;
    loadSpecificVector<Client>(loadVector, fname, newClient);
    writeClassToFile<PizzaHelper>(newPizzaHelper, fname);
    vector<InputErrorException> newInputErrorExceptionVec;
    loadSpecificVector<InputErrorException>(newInputErrorExceptionVec, fname, newInputErrorException);
}

template <class pizzaClass>
void ReadWriteClass::writeClassToFile(pizzaClass& classToWrite, const char* fname)
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
