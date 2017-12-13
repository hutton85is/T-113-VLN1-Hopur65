/**
*    @file The main class for pizza software
*/

#include <iostream>
#include <stdlib.h>


#include "UmsjonUI.h"
#include "SalaUI.h"
#include "BakerUI.h"
#include <stdlib.h>
#include "AfhendingUI.h"
#include "Error.h"
#include <climits>

using namespace std;

void mainMenu()
{
    cout << "    Til thess ad skra thig inn veldu :                   " << endl;
    cout << "                                                         " << endl;
    cout << " 1. Fyrir umsjon                                         " << endl;
    cout << " 2. Fyrir bakara                                         " << endl;
    cout << " 3. Fyrir afhendingu                                     " << endl;
    cout << " 4. Fyrir pontun                                         " << endl;
    // BÆTA VIÐ AÐ ÞAÐ SÉ HÆGT AÐ VELJA PÖNTUN TIL AÐ EYÐA
    cout << " 5. Til ad haetta                                        " << endl;
    cout << "                                                         " << endl;

    unsigned int innskraning;
    cout << "Veldu her: ";
    cin >> innskraning ;

    try{
        if(!cin || innskraning > 5)
        {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            throw InputErrorException("Invalid input in main: ");
        }
        if ( innskraning == 1){
            system("CLS");
            UmsjonUI u;
            u.main();
        }
        else if ( innskraning == 2) {
            system("CLS");
            BakerUI b;
            b.main();
        }
        else if ( innskraning == 3) {
            system("CLS");
            AfhendingUI a;
            a.main();
        }
        else if ( innskraning == 4) {
            system("CLS");
            SalaUI s;
            s.mainOrder();
        }
        else if (innskraning == 5)
        {
            exit(0);
        }
    }
    catch(InputErrorException e)
        {
            Error er;
            er.logInputErrorException(e, "Exceptions/InputErrorException.dat");
            e.getMessage();
            system("pause");
        }
    system("CLS");
}

int main()
{
    UIHelper helperUI;

    while(true)
    {
        helperUI.displayHeader();
        mainMenu();
    }

    return 0;
}
