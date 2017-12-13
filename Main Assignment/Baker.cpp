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
    // Update customersVec to in progress
    for(unsigned int i = 0; i < customersVec.size(); i++)
    {
        if(strcmp(customersVec[i].name, customersVecDueProgress[customersVecNumber].name) == 0)
        {
            // customer found set inprogress status
            customersVec[i].inProgress = true;
            break;
        }
    }

    // Set status as inProgress of customer
    customersVecDueProgress[customersVecNumber].inProgress = true;
    // Move customer on to vector in progress
    customersVecInProgress.push_back(customersVecDueProgress[customersVecNumber]);

    // Load customer from file to rewrite him changing status on working on pizza order
    readWriteClass rw;
    client newClient;
    vector<Pizza> customerOrder;
    vector<PizzaHelper> pHelper;
    string fname = "order/";
    fname.append(customersVecDueProgress[customersVecNumber].name);
    fname.append(".dat");
    const char* pathfile = fname.c_str();
    rw.loadCustomer(newClient, customerOrder, pHelper, pathfile);

    // Remove all contents of exisisting file, for update
    rw.removeAllContentsOfFile(pathfile);

    // Rewrite customer to file
    // Write client class to file and path 'fname'
    rw.writeClassToFile(customersVecDueProgress[customersVecNumber], pathfile);

    for (unsigned int j = 0; j < customersVecDueProgress[customersVecNumber].orderCounter; j++)
    {
        // Write helper class for storing how many items are in the order
        rw.writeClassToFile(pHelper[j], pathfile);

        // Write pizzatoppings class to file and path 'fname'
        for (unsigned int i = 0; i < pHelper[j].toppingsCounter; i++)
        {
            rw.writeClassToFile(customerOrder[j].ptoppings[i], pathfile);
        }

        // Write pizzasize class to file and path 'fname'
        for (unsigned int i = 0; i < pHelper[j].sizeCounter; i++)
        {
            rw.writeClassToFile(customerOrder[j].psize[i], pathfile);
        }

        // Write pizzacrust class to file and path 'fname'
        for (unsigned int i = 0; i < pHelper[j].crustCounter; i++)
        {
            rw.writeClassToFile(customerOrder[j].pcrust[i], pathfile);
        }

        // Write pizzaextras class to file and path 'fname'
        for (unsigned int i = 0; i < pHelper[j].extrasCounter; i++)
        {
            rw.writeClassToFile(customerOrder[j].pextras[i], pathfile);
        }

        // Write pizzamenu class to file and path 'fname'
        for (unsigned int i = 0; i < pHelper[j].menuCounter; i++)
        {
            rw.writeClassToFile(customerOrder[j].pmenu[i], pathfile);
        }

        // Write pizzalocations class to file and path 'fname'
        for (unsigned int i = 0; i < pHelper[j].locationCounter; i++)
        {
            rw.writeClassToFile(customerOrder[j].plocations[i], pathfile);
        }
    }
    // Erase the element after pushing it on another vector and writing it to file with in progress status
    customersVecDueProgress.erase(customersVecDueProgress.begin() + customersVecNumber);
}

void Baker::finishOrder(unsigned int customersVecNumber)
{
    // Update customersVec as finished
    for(unsigned int i = 0; i < customersVec.size(); i++)
    {
        if(strcmp(customersVec[i].name, customersVecInProgress[customersVecNumber].name) == 0)
        {
            // customer found erase it from customersVec
            customersVec.erase(customersVec.begin() + customersVecNumber);
            break;
        }
    }

    // Set status of customer as finished
    customersVecInProgress[customersVecNumber].finished = true;

    // Load customer from file to rewrite him changing status to finished on order
    readWriteClass rw;
    client newClient;
    vector<Pizza> customerOrder;
    vector<PizzaHelper> pHelper;
    string fname = "order/";
    fname.append(customersVecInProgress[customersVecNumber].name);
    fname.append(".dat");
    const char* pathfile = fname.c_str();
    rw.loadCustomer(newClient, customerOrder, pHelper, pathfile);

    // Remove all contents of existing file, for update
    rw.removeAllContentsOfFile(pathfile);

    // Rewrite customer to file
    // Write client class to file and path 'fname'
    rw.writeClassToFile(customersVecInProgress[customersVecNumber], pathfile);

    for (unsigned int j = 0; j < customersVecInProgress[customersVecNumber].orderCounter; j++)
    {
        // Write helper class for storing how many items are in the order
        rw.writeClassToFile(pHelper[j], pathfile);

        // Write pizzatoppings class to file and path 'fname'
        for (unsigned int i = 0; i < pHelper[j].toppingsCounter; i++)
        {
            rw.writeClassToFile(customerOrder[j].ptoppings[i], pathfile);
        }

        // Write pizzasize class to file and path 'fname'
        for (unsigned int i = 0; i < pHelper[j].sizeCounter; i++)
        {
            rw.writeClassToFile(customerOrder[j].psize[i], pathfile);
        }

        // Write pizzacrust class to file and path 'fname'
        for (unsigned int i = 0; i < pHelper[j].crustCounter; i++)
        {
            rw.writeClassToFile(customerOrder[j].pcrust[i], pathfile);
        }

        // Write pizzaextras class to file and path 'fname'
        for (unsigned int i = 0; i < pHelper[j].extrasCounter; i++)
        {
            rw.writeClassToFile(customerOrder[j].pextras[i], pathfile);
        }

        // Write pizzamenu class to file and path 'fname'
        for (unsigned int i = 0; i < pHelper[j].menuCounter; i++)
        {
            rw.writeClassToFile(customerOrder[j].pmenu[i], pathfile);
        }

        // Write pizzalocations class to file and path 'fname'
        for (unsigned int i = 0; i < pHelper[j].locationCounter; i++)
        {
            rw.writeClassToFile(customerOrder[j].plocations[i], pathfile);
        }
    }
    // Erase the element after pushing it on another vector and writing it to file with in progress status
    customersVecInProgress.erase(customersVecInProgress.begin() + customersVecNumber);
}

string Baker::getBakerLocation()
{
    return bakerLocation;
}

vector<Pizza> Baker::getCustomersOrderDueProgress(unsigned int customerNumber)
{
    readWriteClass rw;
    client newClient;
    vector<Pizza> customerOrder;
    vector<PizzaHelper> pHelper;
    string fname = "order/";
    fname.append(customersVecDueProgress[customerNumber].name);
    fname.append(".dat");
    const char* pathfile = fname.c_str();
    rw.loadCustomer(newClient, customerOrder, pHelper, pathfile);
    return customerOrder;
}

vector<Pizza> Baker::getCustomersOrderInProgress(unsigned int customerNumber)
{
    readWriteClass rw;
    client newClient;
    vector<Pizza> customerOrder;
    vector<PizzaHelper> pHelper;
    string fname = "order/";
    fname.append(customersVecInProgress[customerNumber].name);
    fname.append(".dat");
    const char* pathfile = fname.c_str();
    rw.loadCustomer(newClient, customerOrder, pHelper, pathfile);
    return customerOrder;
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
    * run through all orders to find which orders have same location as baker
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
        cout << i << " i " << endl;
        rw.loadCustomer(newClient, newOrder, newpHelper, pathfile);

        /*
        * Compare baker location with customer location, and check if the orders are not finished,
        * and push them onto customersVec if they have the same location
        */
        bool same = false;
        for (unsigned int k = 0; k < 32; k++)
        {
            if(newOrder[0].plocations[0].place[k] != bakerLocation[k])
            {
                break;
            }
            if ((bakerLocation[k] == '\0') && (!newClient.finished))
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
            else
            {
                customersVecDueProgress.push_back(newClient);
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

vector<client> Baker::getCustomersVecDueProgress()
{
    return customersVecDueProgress;
}
