#include "Baker.h"

Baker::Baker()
{
}

Baker::~Baker()
{
    //dtor
}

void Baker::setBakerLocation(char currentLocation[32])
{
    strcpy(bakerLocation, currentLocation);
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

vector<Pizza> Baker::getOrderVec()
{
    return order;
}

vector<PizzaHelper> Baker::getpHelperVec()
{
    return pHelper;
}
