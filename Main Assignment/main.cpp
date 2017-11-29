#include <iostream>

#include "Umsjon.h"

using namespace std;

int main()
{
    Umsjon u;

    Pizza p;
    u.enterPizzaSize();
    u.print();

    u.enterCrust();

    Umsjon e;
    e.enterToppings();


    return 0;
}
