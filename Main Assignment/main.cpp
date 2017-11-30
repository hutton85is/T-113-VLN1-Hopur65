#include <iostream>

#include "Umsjon.h"

using namespace std;

int main()
{
    Umsjon u;
    u.enterToppings();
    cout << u.p.ptoppings[0].toppings << endl;
    return 0;
}
