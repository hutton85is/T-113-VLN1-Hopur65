#include <iostream>
#include <stdlib.h>

#include "UmsjonUI.h"
#include "SalaUI.h"
#include "BakerUI.h"
#include <stdlib.h>

using namespace std;

void mainMenu()
{
    cout << "---------------------------------------------------------" << endl;
    cout << "               Velkomin/nn a Pizzastadinn!               " << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "    Til thess ad skra thig inn veldu :                   " << endl;
    cout << "                                                         " << endl;
    cout << " 1. Fyrir umsjon                                         " << endl;
    cout << " 2. Fyrir bakara                                         " << endl;
    cout << " 3. Fyrir pontun                                         " << endl;
    cout << " 4. Til ad haetta                                        " << endl;
    cout << "                                                         " << endl;

    char innskraning;
    cin >> innskraning ;

    if ( innskraning == '1') {
        UmsjonUI u;
        u.main();
    }
    else if ( innskraning == '2') {
        BakerUI b;
        b.main();
    }
    else if ( innskraning == '3') {
        SalaUI s;
        s.mainOrder();
    }
    else if (innskraning == '4')
    {
        exit(0);
    }

    system("CLS");
}

int main()
{

    while(true)
    {
        mainMenu();
    }

    return 0;
}
