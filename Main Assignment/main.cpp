#include <iostream>
#include <stdlib.h>

#include "UmsjonUI.h"
#include "SalaUI.h"
#include <stdlib.h>

using namespace std;

int mainMenu()
{
    int val;
    cout << "1 : Umsjon" << endl;
    cout << "2 : Sala" << endl;
    cout << "3 : Exit" << endl;
    cin >> val;
    return val;
}

int main()
{

    while(true)
    {
        int val = mainMenu();
        if (val == 1)
        {
            UmsjonUI u;
            u.main();
        }
        else if (val == 2)
        {
            SalaUI s;
            s.mainOrder();
        }
        else if (val == 3)
        {
            exit(0);
        }
        system("CLS");
    }

    return 0;
}
