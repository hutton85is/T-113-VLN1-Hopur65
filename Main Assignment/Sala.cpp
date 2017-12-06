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

vector<PizzaCrust> Sala::getOrderpcrust()
{
    return order.pcrust;
}

vector<PizzaExtras> Sala::getOrderpextras()
{
    return order.pextras;
}

vector<PizzaLocations> Sala::getOrderplocations()
{
    return order.plocations;
}

vector<PizzaMenu> Sala::getOrderpMenu()
{
    return order.pmenu;
}

vector<PizzaSize> Sala::getOrderpsize()
{
    return order.psize;
}

vector<PizzaToppings> Sala::getOrderptoppings()
{
    return order.ptoppings;
}

bool Sala::enterPizzaSize(unsigned int input)
{
    if (input < sizeof(lager.psize) && 0 <= input)
    {
        order.psize.push_back(lager.psize[input]);

        newCustomer.sizeCounter++;

        return true;
    }

    return false;
}

bool Sala::enterCrust(unsigned int input)
{
    if (input < sizeof(lager.pcrust) && 0 <= input)
    {
        order.pcrust.push_back(lager.pcrust[input]);

        newCustomer.crustCounter++;

        return true;
    }

    return false;
}

bool Sala::enterToppings(unsigned int input)
{
    if (input < sizeof(lager.ptoppings) && 0 <= input)
    {
        order.ptoppings.push_back(lager.ptoppings[input]);

        newCustomer.toppingsCounter++;

        return true;
    }

    return false;
}

bool Sala::enterMenu(unsigned int input)
{
    if (input < sizeof(lager.pmenu) && 0 <= input)
    {
        order.pmenu.push_back(lager.pmenu[input]);

        newCustomer.menuCounter++;

        return true;
    }

    return false;
}

bool Sala::enterExtras(unsigned int input)
{
    if (input < sizeof(lager.pextras) && 0 <= input)
    {
        order.pextras.push_back(lager.pextras[input]);

        newCustomer.extrasCounter++;

        return true;
    }

    return false;
}

bool Sala::enterLocation(unsigned int input)
{
    if (input < sizeof(lager.plocations) && 0 <= input)
    {
        order.plocations.push_back(lager.plocations[input]);

        newCustomer.locationCounter++;

        return true;
    }

    return false;
}

void Sala::getCustomer(const char* fname)
{
    readWriteClass rw;
    // Load customer into variable newCustomer and his order into variable order,
    // fname contains the path and filename for his order
    rw.loadCustomer(order, newCustomer, fname);
}

bool Sala::createOrder(string name, string address, int number)
{
    //Assign name, address and addressnumber for newCustomer
    strncpy(newCustomer.name, name.c_str(), sizeof(newCustomer.name) - 1);
    strncpy(newCustomer.address, address.c_str(), sizeof(newCustomer.address) - 1);
    newCustomer.addressNumber = number;

    // create a path with file name in variable tempname and enter it to variable fname
    string tempname = "order/" + name + ".dat";
    const char* fname = tempname.c_str();

    readWriteClass rw;
    // Write client class to file and path 'fname'
    rw.writeClassToFile(newCustomer, fname);

    // Write pizzatoppings class to file and path 'fname'
    for (unsigned int i = 0; i < newCustomer.toppingsCounter; i++)
    {
        rw.writeClassToFile(order.ptoppings[i], fname);
    }

    // Write pizzasize class to file and path 'fname'
    if (newCustomer.sizeCounter)
    {
        rw.writeClassToFile(order.psize[0], fname);
    }

    // Write pizzacrust class to file and path 'fname'
    if (newCustomer.crustCounter)
    {
        rw.writeClassToFile(order.pcrust[0], fname);
    }

    // Write pizzaextras class to file and path 'fname'
    for (unsigned int i = 0; i < newCustomer.extrasCounter; i++)
    {
        rw.writeClassToFile(order.pextras[i], fname);
    }

    // Write pizzamenu class to file and path 'fname'
    for (unsigned int i = 0; i < newCustomer.orderCounter; i++)
    {
        rw.writeClassToFile(order.pmenu[i], fname);
    }

    // Write pizzalocations class to file and path 'fname'
    if (newCustomer.locationCounter)
    {
        rw.writeClassToFile(order.plocations[0], fname);
    }

    return true;
}

ostream& operator <<(ostream& outs, Sala& s)
{
    outs << s.newCustomer.name << cout;
    outs << s.newCustomer.address << " " << s.newCustomer.addressNumber << endl;
    outs << "----ORDER----" << endl;
    return outs;
}
