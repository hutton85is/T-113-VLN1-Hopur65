#include <iostream>

#include "Umsjon.h"

using namespace std;

int main()
{
    Umsjon u;

    Pizza p;
    p.loadFile(p);

<<<<<<< HEAD
    /*u.enterPizzaSize(p);

    u.enterCrust(p);*/

    u.enterToppings(p);
=======
    u.enterPizzaSize();

    u.enterCrust();

    u.enterToppings();
    p.displayVector(p.menuToppings);
>>>>>>> 4a7b04e06fbda19f1424a0b7ce4cfdf655d02a0e



    return 0;
}
