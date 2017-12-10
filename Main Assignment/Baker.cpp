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

void Baker::workOnOrder(unsigned int customersVecNumber)
{
    customersVec[customersVecNumber].inProgress = true;
    // H�R �ARF A� B�TA VI� A� SKRIFA � SKR� CUSTOMER ME� N�JU GILDI � WOKING ON ORDER
}

string Baker::getBakerLocation()
{
    return bakerLocation;
}

vector<Pizza> Baker::getOrderVec(unsigned int customersVecNumber)
{
    readWriteClass rw;
    client newClient;
    vector<Pizza> customerOrder;
    vector<PizzaHelper> pHelper;
    string fname = "order/";
    fname.append(customersVec[customersVecNumber].name);
    fname.append(".dat");
    const char* pathfile = fname.c_str();
    rw.loadCustomer(newClient, customerOrder, pHelper, pathfile);
    return customerOrder;
}

void Baker::setBakerLocation(char currentLocation[32])
{
    strcpy(bakerLocation, currentLocation);

    readWriteClass rw;
    vector<client> newCustomersVec;
    /*
    run through all orders to find which orders have same location as baker
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

        /*
        * Compare baker location with customer location and push them onto
        * customersVec if they have the same location
        */
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
            if(newClient.inProgress)
            {
                customersVecInProgress.push_back(newClient);
            }
        }
    }
    customersVec = newCustomersVec;
}

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

vector<client> Baker::getCustomersVecInProgress()
{
    return customersVecInProgress;
}
