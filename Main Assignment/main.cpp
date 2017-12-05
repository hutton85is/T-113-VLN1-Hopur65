#include <iostream>

#include "Umsjon.h"

using namespace std;

void front_page();

    char who_am_i;
    char S;
    char E;
    char B;

void front_page ()
{
    cout << "To sign in as a : " << endl;
    cout << "Supervisor choose S " << endl;
    cout << "Employee choose E " << endl;
    cout << "Baker choose B" << endl;
    cin >> who_am_i << endl;


}


int main()
{
    Umsjon u;
    u.enterToppings();
    cout << u.p.ptoppings[0].toppings << endl;
    return 0;
}
