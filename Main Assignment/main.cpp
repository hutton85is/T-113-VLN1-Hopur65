#include <iostream>

#include "UmsjonUI.h"
#include "SalaUI.h"

using namespace std;

int mainMenu()
{
    int val;
    cout << "1 : Umsjon" << endl;
    cout << "2 : Sala" << endl;
    cin >> val;
    return val;
}

int main()
{
    UmsjonUI u;
    SalaUI a;

    while(true)
    {
        int val = mainMenu();
        if (val == 1)
        {
            u.main();
        }
        if (val == 2)
        {
            a.mainOrder();
        }
    }

    return 0;
}
