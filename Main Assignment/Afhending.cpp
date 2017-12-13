#include "Afhending.h"

Afhending::Afhending()
{
    ReadWriteClass rw;
    Client loadClient;
    rw.loadSpecificVector(customersVec, "order/customerlist.dat", loadClient);
}

vector<Client> Afhending::getCustomerVec()
{
    return customersVec;
}

vector<PizzaLocations> Afhending::getPizzaLocations()
{
    ReadWriteClass rw;
    PizzaLocations newPizzaLocation;
    vector<PizzaLocations> locationsVec;
    rw.loadSpecificVector(locationsVec, "data/locations.dat", newPizzaLocation);
    return locationsVec;
}

string Afhending::getAfhendingLocation()
{
    return afhendingLocation;
}

void Afhending::setAfhendingLocation(char currentLocation[32])
{
    strcpy(afhendingLocation, currentLocation);

    ReadWriteClass rw;
    vector<Client> newCustomersVec;

    // run through all orders to find which orders have same location as baker
    for (unsigned int i = 0; i < customersVec.size(); i++)
    {
        // change to compare an array of char
        vector<Pizza> newOrder;
        vector<PizzaHelper> newpHelper;
        Client newClient;
        string fname = "order/";
        fname.append(customersVec[i].name);
        fname.append(".dat");
        const char* pathfile = fname.c_str();
        rw.loadCustomer(newClient, newOrder, newpHelper, pathfile);

        // Compare baker location with customer location, and check if the orders are not finished,
        // and push them onto customersVec if they have the same location
        bool same = false;
        for (unsigned int k = 0; k < 32; k++)
        {
            if(newOrder[0].plocations[0].place[k] != afhendingLocation[k])
            {
                break;
            }
            if ((afhendingLocation[k] == '\0') && (newClient.finished))
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

vector<Pizza> Afhending::getOrderVec(unsigned int customersVecNumber)
{
    ReadWriteClass rw;
    Client newClient;
    vector<Pizza> customerOrder;
    vector<PizzaHelper> pHelper;
    string fname = "order/";
    fname.append(customersVec[customersVecNumber].name);
    fname.append(".dat");
    const char* pathfile = fname.c_str();
    rw.loadCustomer(newClient, customerOrder, pHelper, pathfile);
    return customerOrder;
}

void Afhending::deliverOrder(int customersVecNumber)
{
    int customersVecSize = customersVec.size();
    if(customersVecNumber < 0 || customersVecSize - 1 < customersVecNumber)
    {
        throw InputErrorException("Engin tilbuin pontun med thessu numeri");
    }

    customersVec[customersVecNumber].orderPaid = true;
    customersVec[customersVecNumber].orderDelivered = true;

    ReadWriteClass rw;
    string fname = "order/";
    fname.append(customersVec[customersVecNumber].name);
    fname.append(".dat");
    const char* oldpathfile = fname.c_str();

    // Load customer from file to rewrite him to folder delivered
    Client newClient;
    vector<Pizza> customerOrder;
    vector<PizzaHelper> pHelper;
    rw.loadCustomer(newClient, customerOrder, pHelper, oldpathfile);

    // Update newClient received from file
    newClient = customersVec[customersVecNumber];

    // Remove all contents of existing file in order-folder for moving to folder delivered
    rw.removeAllContentsOfFile(oldpathfile);

    // Erase customer from customersVec
    customersVec.erase(customersVec.begin() + customersVecNumber);

    // Load all contents of order/customerlist.dat to be updated
    Client loadClient;
    vector<Client> tempVec;
    rw.loadSpecificVector(tempVec, "order/customerlist.dat", loadClient);

    // Remove all contents of directory in order folder for update
    rw.removeAllContentsOfFile("order/customerlist.dat");

    // Remove customer who got delivered from tempVec
    for(unsigned int i = 0; i < tempVec.size(); i++)
    {
        if(strcmp(tempVec[i].name, newClient.name) == 0)
        {
            // customer found remove him
            tempVec.erase(tempVec.begin() + customersVecNumber);
            break;
        }
    }

    // Add all contents with customer delivered removed
    for(unsigned int i = 0; i < tempVec.size(); i++)
    {
        rw.writeClassToFile(tempVec[i], "order/customerlist.dat");
    }

    // Change path to folder delivered
    fname = "delivered/";
    fname.append(newClient.name);
    fname.append(".dat");
    const char* pathfile = fname.c_str();

    // Write customer to file directory in delivered folder
    rw.writeClassToFile(newClient, "delivered/customerlist.dat");
    // Write client class to file and path 'fname'
    rw.writeClassToFile(newClient, pathfile);

    for (unsigned int j = 0; j < newClient.orderCounter; j++)
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
}
