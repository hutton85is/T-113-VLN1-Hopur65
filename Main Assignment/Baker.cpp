#include "Baker.h"

Baker::Baker(const char* fname)
{
    readWriteClass rw;
    client newCustomer;
    rw.loadCustomer(newCustomer, order, pHelper, fname);
    customersVec.push_back(newCustomer);
}

Baker::~Baker()
{
    //dtor
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
