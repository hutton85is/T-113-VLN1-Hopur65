#include <iostream>

#include "Umsjon.h"
#include "UmsjonUI.h"
#include "SalaUI.h"

using namespace std;

int main()
{
    Umsjon u;
    cout << u.p.ptoppings[0].toppings << endl;
    cout << u.p.ptoppings[1].price << endl;
    //u.enterToppings();
    return 0;


}
