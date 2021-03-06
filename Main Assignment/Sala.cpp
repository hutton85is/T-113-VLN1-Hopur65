#include "Sala.h"

Sala::Sala()
{
    ReadWriteClass rw;
    rw.loadAllVectors(lager);
}

vector<Pizza> Sala::getOrder()
{
    return order;
}

vector<PizzaCrust> Sala::getLagerpcrust()
{
    return lager.pcrust;
}

vector<PizzaExtras> Sala::getLagerpextras()
{
    return lager.pextras;
}

vector<PizzaLocations> Sala::getLagerplocations()
{
    return lager.plocations;
}

vector<PizzaMenu> Sala::getLagerpMenu()
{
    return lager.pmenu;
}

vector<PizzaSize> Sala::getLagerpsize()
{
    return lager.psize;
}

vector<PizzaToppings> Sala::getLagerptoppings()
{
    return lager.ptoppings;
}

Client Sala::getClient()
{
    return newCustomer;
}

void Sala::enterPizzaSize(unsigned int input)
{
    if (input < lager.psize.size() && 0 <= input)
    {
        // Only allow a single choice of pizzasize with each order
        // if vector is empty push item on the vector else change first item
        if (order[newCustomer.orderCounter-1].psize.empty())
        {
            order[newCustomer.orderCounter-1].psize.push_back(lager.psize[input]);
        }
        else
        {
            order[newCustomer.orderCounter-1].psize[0] = lager.psize[input];
        }

        // If there is a pizza from the menu, change the price of pizza size
        if(!order[newCustomer.orderCounter-1].pmenu.empty())
        {
            order[newCustomer.orderCounter-1].psize[0].price =
            order[newCustomer.orderCounter-1].psize[0].price * order[newCustomer.orderCounter-1].pmenu[0].price;
        }

        pHelper[newCustomer.orderCounter-1].sizeCounter = 1;
    }
    else
    {
        throw InputErrorException("Innslattarvilla a pizzustaerd");
    }
}

void Sala::enterCrust(unsigned int input)
{
    if (input < lager.pcrust.size() && 0 <= input)
    {
        // Only allow a single choice of pizza crust with each order
        // if vector is empty push item on the vector else change first item
        if(order[newCustomer.orderCounter-1].pcrust.empty())
        {
            order[newCustomer.orderCounter-1].pcrust.push_back(lager.pcrust[input]);
        }
        else
        {
            order[newCustomer.orderCounter-1].pcrust[0] = lager.pcrust[input];
        }

        pHelper[newCustomer.orderCounter-1].crustCounter = 1;
    }
    else
    {
        throw InputErrorException("Innslattarvilla a pizzubotni");
    }
}

void Sala::enterToppings(unsigned int input)
{
    if (input < lager.ptoppings.size() && 0 <= input)
    {
        order[newCustomer.orderCounter-1].ptoppings.push_back(lager.ptoppings[input]);

        pHelper[newCustomer.orderCounter-1].toppingsCounter++;
    }
    else
    {
        throw InputErrorException("Innslattarvilla a aleggi");
    }
}

void Sala::enterMenu(unsigned int input)
{
    if (input < lager.pmenu.size() && 0 <= input)
    {
        // Only allow a single choice of pizza from menu with each order
        // if vector is empty push item on the vector else change first item
        if(order[newCustomer.orderCounter-1].pmenu.empty())
        {
            order[newCustomer.orderCounter-1].pmenu.push_back(lager.pmenu[input]);
        }
        else
        {
            order[newCustomer.orderCounter-1].pmenu[0] = lager.pmenu[input];
        }

        // if pizza size has been chosen change its pizza price
        if(!order[newCustomer.orderCounter-1].psize.empty())
        {
            order[newCustomer.orderCounter-1].psize[0].price =
            order[newCustomer.orderCounter-1].psize[0].price * order[newCustomer.orderCounter-1].pmenu[0].price;
        }

        pHelper[newCustomer.orderCounter-1].menuCounter = 1;
    }
    else
    {
        throw InputErrorException("Innslattarvilla a matsedli");
    }
}

void Sala::enterExtras(unsigned int input)
{
    if (input < lager.pextras.size() && 0 <= input)
    {
        order[newCustomer.orderCounter-1].pextras.push_back(lager.pextras[input]);

        pHelper[newCustomer.orderCounter-1].extrasCounter++;
    }
    else
    {
        throw InputErrorException("Innslattarvilla a medlaeti");
    }
}

void Sala::enterLocation(unsigned int input)
{
    if (input < lager.plocations.size() && 0 <= input)
    {
        // Only allow a single choice of location and always enter it on order 1
        // if vector is empty push item on the vector else change first item
        if(order[0].plocations.empty())
        {
            order[0].plocations.push_back(lager.plocations[input]);
        }
        else
        {
            order[0].plocations[0] = lager.plocations[input];
        }

        pHelper[0].locationCounter = 1;
    }
    else
    {
        throw InputErrorException("Innslattarvilla a stadsetningu");
    }
}

void Sala::newPizza()
{
    newCustomer.orderCounter++;

    Pizza newPizzaOrder;
    order.push_back(newPizzaOrder);

    PizzaHelper newPizzaHelper;
    pHelper.push_back(newPizzaHelper);
}

Client Sala::getCustomerOrdersVector()
{
    return newCustomer;
}

void Sala::createOrder(string name, string address, int number, bool paid, bool delivery, string comment)
{
    strncpy(newCustomer.name, name.c_str(), sizeof(newCustomer.name) - 1);
    strncpy(newCustomer.address, address.c_str(), sizeof(newCustomer.address) - 1);
    newCustomer.addressNumber = number;
    newCustomer.orderPaid = paid;
    newCustomer.deliverOrder = delivery;
    strncpy(newCustomer.comment, comment.c_str(), sizeof(newCustomer.comment) -1);

    calculateSumOfOrder();

    string tempname = "order/" + name + ".dat";
    const char* fname = tempname.c_str();

    ReadWriteClass rw;
    // Add customer to order directory, containing all open orders
    rw.writeClassToFile(newCustomer, "order/customerlist.dat");
    // Write client class to file and path 'fname'
    rw.writeClassToFile(newCustomer, fname);

    // Add all classes on order to file 'fname' according to counter variables stored in pHelper
    for (unsigned int j = 0; j < newCustomer.orderCounter; j++)
    {
        // Write helper class for storing how many items are in the order
        rw.writeClassToFile(pHelper[j], fname);

        // Write pizzatoppings class to file and path 'fname'
        for (unsigned int i = 0; i < pHelper[j].toppingsCounter; i++)
        {
            rw.writeClassToFile(order[j].ptoppings[i], fname);
        }

        // Write pizzasize class to file and path 'fname'
        for (unsigned int i = 0; i < pHelper[j].sizeCounter; i++)
        {
            rw.writeClassToFile(order[j].psize[i], fname);
        }

        // Write pizzacrust class to file and path 'fname'
        for (unsigned int i = 0; i < pHelper[j].crustCounter; i++)
        {
            rw.writeClassToFile(order[j].pcrust[i], fname);
        }

        // Write pizzaextras class to file and path 'fname'
        for (unsigned int i = 0; i < pHelper[j].extrasCounter; i++)
        {
            rw.writeClassToFile(order[j].pextras[i], fname);
        }

        // Write pizzamenu class to file and path 'fname'
        for (unsigned int i = 0; i < pHelper[j].menuCounter; i++)
        {
            rw.writeClassToFile(order[j].pmenu[i], fname);
        }

        // Write pizzalocations class to file and path 'fname'
        for (unsigned int i = 0; i < pHelper[j].locationCounter; i++)
        {
            rw.writeClassToFile(order[j].plocations[i], fname);
        }
    }
}

void Sala::calculateSumOfOrder()
{
    int sum = 0;

    for(unsigned int i = 0; i < order.size(); i++)
    {
        sum += order[i].calculateSumOfOrder();
    }
    newCustomer.sumOfOrder = sum;
}

ostream& operator <<(ostream& outs, Sala& s)
{
    vector<Pizza> order = s.getOrder();

    for(unsigned int i = 0; i < order.size(); i++)
    {
        cout << "    Pizza " << i + 1 << "." << endl;
        outs << order[i];
    }
    return outs;
}
