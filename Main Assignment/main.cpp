#include <iostream>
#include <stdlib.h>

#include "UmsjonUI.h"
#include "SalaUI.h"
#include "BakerUI.h"
#include "ErrorUI.h"
#include <stdlib.h>
#include <ctime>

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
    cout << " 4. Til ad skoda villumeldingar                          " << endl;
    cout << " 5. Til ad haetta                                        " << endl;

    // BÆTA VIÐ AÐ ÞAÐ SÉ HÆGT AÐ VELJA PÖNTUN TIL AÐ EYÐA

    char innskraning;
    cout << "Veldu her: ";
    cin >> innskraning ;

    if ( innskraning == '1') {
        system("CLS");
        UmsjonUI u;
        u.main();
    }
    else if ( innskraning == '2') {
        system("CLS");
        BakerUI b;
        b.main();
    }
    else if ( innskraning == '3') {
        system("CLS");
        SalaUI s;
        s.mainOrder();
    }
    else if (innskraning == '4')
    {   system("CLS");
        ErrorUI e;
        e.mainUI();

    }
    else if (innskraning == '5')
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
