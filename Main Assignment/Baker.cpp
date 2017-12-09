#include "Baker.h"

Baker::Baker()
{
    readWriteClass rw;
    client loadClient;
    rw.loadSpecificVector(customersVec, "order/customerlist.dat", loadClient);
}

Baker::~Baker()
{
    //dtor
}

void Baker::setBakerLocation(char currentLocation[32])
{
    strcpy(bakerLocation, currentLocation);
    // B�ta vi� h�rna a� breyta customersvec mi�a� vi� bakerlocation
    readWriteClass rw;
    vector<client> newCustomersVec;
    /*
    run through all orders to find which ones are the same as
    */
    for (unsigned int i = 0; i < customersVec.size(); i++)
    {
        // change to compare an array of char
        vector<Pizza> newOrder;
        vector<PizzaHelper> newpHelper;
        client newClient;
        string fname = "order/";
        fname.append(customersVec[i].name);
        fname.append(".dat");
        const char* pathfile = fname.c_str();
        rw.loadCustomer(newClient, newOrder, newpHelper, pathfile);

        bool same = false;
        for (unsigned int k = 0; k < 32; k++)
        {
            if(newOrder[0].plocations[0].place[k] != bakerLocation[k])
            {
                break;
            }
            if (bakerLocation[k] == '\0')
            {
                same = true;
                break;
            }
        }

        if (same)
        {
            newCustomersVec.push_back(newClient);
        }
    }
    customersVec = newCustomersVec;
}
/*
void Baker::getCustomerOrder(unsigned int customerNumber)
{
    readWriteClass rw;

    unsigned int vecSize = customersVec.size();
    for(unsigned int i = 0; i < vecSize; i++)
    {
        client vecClient;
        string fname = "order/";
        fname.append(customersVec[i].name);
        fname.append(".dat");
        const char* pathfile = fname.c_str();
        rw.loadCustomer(vecClient, order, pHelper, pathfile);
    }
}
*/
vector<PizzaLocations> Baker::getPizzaLocations()
{
    readWriteClass rw;
    PizzaLocations newPizzaLocation;
    vector<PizzaLocations> locationsVec;
    rw.loadSpecificVector(locationsVec, "data/locations.dat", newPizzaLocation);
    return locationsVec;
}

vector<client> Baker::getCustomerVec()
{
    return customersVec;
}
