#include <iostream>

#include "Umsjon.h"

using namespace std;

int main()
{
    Umsjon u;

    Pizza p;
    p.loadFile(p);

    /*u.enterPizzaSize(p);

    u.enterCrust(p);*/

    u.enterToppings(p);



    return 0;
}
