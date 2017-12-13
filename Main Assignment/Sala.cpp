#include "Sala.h"

Sala::Sala()
{
    readWriteClass rw;
    rw.loadAllVectors(lager);
}

Sala::~Sala()
{
    //dtor
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

bool Sala::enterPizzaSize(unsigned int input)
{
    if (input < lager.psize.size() && 0 <= input)
    {
        // Only allow a single choice of pizzasize with each order
        // if vector is empty push item on the vector else change first item
        if (order[newCustomer.currentPizza-1].psize.empty())
        {
            order[newCustomer.currentPizza-1].psize.push_back(lager.psize[input]);
        }
        else
        {
            order[newCustomer.currentPizza-1].psize[0] = lager.psize[input];
        }

        pHelper[newCustomer.currentPizza-1].sizeCounter = 1;

        return true;

    }
    else
    {
        throw InputErrorException("Invalid input on pizzasize");
    }

    return false;
}

bool Sala::enterCrust(unsigned int input)
{
    if (input < lager.pcrust.size() && 0 <= input)
    {
        // Only allow a single choice of pizza crust with each order
        // if vector is empty push item on the vector else change first item
        if(order[newCustomer.currentPizza-1].pcrust.empty())
        {
            order[newCustomer.currentPizza-1].pcrust.push_back(lager.pcrust[input]);
        }
        else
        {
            order[newCustomer.currentPizza-1].pcrust[0] = lager.pcrust[input];
        }

        pHelper[newCustomer.currentPizza-1].crustCounter = 1;

        return true;
    }
    else
    {
        throw InputErrorException("Invalid input, out of range");
    }

    return false;
}

bool Sala::enterToppings(unsigned int input)
{
    if (input < lager.ptoppings.size() && 0 <= input)
    {
        order[newCustomer.currentPizza-1].ptoppings.push_back(lager.ptoppings[input]);

        pHelper[newCustomer.currentPizza-1].toppingsCounter++;

        return true;
    }
    else
    {
        throw InputErrorException("Invalid input, out of range");
    }

    return false;
}

bool Sala::enterMenu(unsigned int input)
{
    if (input < lager.pmenu.size() && 0 <= input)
    {
        // Only allow a single choice of pizza from menu with each order
        // if vector is empty push item on the vector else change first item
        if(order[newCustomer.currentPizza-1].pmenu.empty())
        {
            order[newCustomer.currentPizza-1].pmenu.push_back(lager.pmenu[input]);
        }
        else
        {
            order[newCustomer.currentPizza-1].pmenu[0] = lager.pmenu[input];
        }

        pHelper[newCustomer.currentPizza-1].menuCounter = 1;

        return true;
    }
    else
    {
        throw InputErrorException("Invalid input, out of range");
    }

    return false;
}

bool Sala::enterExtras(unsigned int input)
{
    if (input < lager.pextras.size() && 0 <= input)
    {
        order[newCustomer.currentPizza-1].pextras.push_back(lager.pextras[input]);

        pHelper[newCustomer.currentPizza-1].extrasCounter++;

        return true;
    }
    else
    {
        throw InputErrorException("Invalid input, out of range");
    }

    return false;
}

bool Sala::enterLocation(unsigned int input)
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

        return true;
    }
    else
    {
        throw InputErrorException("Invalid input, out of range");
    }

    return false;
}

void Sala::newPizza()
{
    /* ONLY USE THIS IF WE WANT TO BE ABLE TO CHANGE AN ORDER
    // if the count of orders is equal to the current pizza being edited, increase both
    if (newCustomer.orderCounter == newCustomer.currentPizza)
    {
        newCustomer.currentPizza++;
        newCustomer.orderCounter++;
        // Insert a new pizza class onto client vector<Pizza>
        Pizza newPizzaOrder;
        newCustomer.order.push_back(newPizzaOrder);
        // Insert a new Pizza helper class
        PizzaHelper newPizzaHelper;
        newCustomer.pHelper.push_back(newPizzaHelper);
    }
    // if the count of orders is greater then count of current pizza, a pizza is being edited and do not increase order counter
    else if(newCustomer.currentPizza < newCustomer.orderCounter)
    {
        newCustomer.currentPizza++;
    }
    // This should never be, if it does set equal to each other
    else
    {
        newCustomer.currentPizza = newCustomer.orderCounter;
    }*/
    newCustomer.currentPizza++;
    newCustomer.orderCounter++;

    // Insert a new pizza class onto client vector<Pizza>
    Pizza newPizzaOrder;
    order.push_back(newPizzaOrder);

    // Insert a new Pizza helper class
    PizzaHelper newPizzaHelper;
    pHelper.push_back(newPizzaHelper);
}

client Sala::getCustomerOrdersVector()
{
    return newCustomer;
}

void Sala::createOrder(string name, string address, int number, bool paid, bool delivery, string comment)
{
    // Assign name, address and addressnumber for newCustomer
    strncpy(newCustomer.name, name.c_str(), sizeof(newCustomer.name) - 1);
    strncpy(newCustomer.address, address.c_str(), sizeof(newCustomer.address) - 1);
    newCustomer.addressNumber = number;
    newCustomer.orderPaid = paid;
    newCustomer.deliverOrder = delivery;
    strncpy(newCustomer.comment, comment.c_str(), sizeof(newCustomer.comment) -1);

    // create a path with file name in variable tempname and enter it to variable fname
    string tempname = "order/" + name + ".dat";
    const char* fname = tempname.c_str();

    readWriteClass rw;
    // Add customer to order directory, containing all open orders
    rw.writeClassToFile(newCustomer, "order/customerlist.dat");
    // Write client class to file and path 'fname'
    rw.writeClassToFile(newCustomer, fname);

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

ostream& operator <<(ostream& outs, Sala& s)
{

    return outs;
}
