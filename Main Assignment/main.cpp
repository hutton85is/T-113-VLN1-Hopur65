/**
*    @brief The main class for pizza software
*/

#include "UmsjonUI.h"
#include "SalaUI.h"
#include "BakerUI.h"
#include "AfhendingUI.h"
#include "ErrorException.h"
#include "ErrorExceptionUI.h"

#include <iostream>
#include <stdlib.h>
#include <stdlib.h>
#include <climits>

using namespace std;

void mainMenu()
{
    cout << "                                                         " << endl;
    cout << " 1. Fyrir umsjon                                         " << endl;
    cout << " 2. Fyrir bakara                                         " << endl;
    cout << " 3. Fyrir afhendingu                                     " << endl;
    cout << " 4. Fyrir pontun                                         " << endl;
    cout << " 5. Fyrir villu meldingar                                " << endl;
    // B�TA VI� A� �A� S� H�GT A� VELJA P�NTUN TIL A� EY�A
    cout << " 6. Til ad haetta                                        " << endl;
    cout << "                                                         " << endl;

    int innskraning;
    cout << "Veldu her: ";

    cin >> innskraning ;

    try
    {
        if(!cin || innskraning > 6 || innskraning < 1)
        {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            throw InputErrorException("Invalid input in main: ");
        }
        if ( innskraning == 1)
        {
            system("CLS");
            UmsjonUI u;
            u.main();
        }
        else if ( innskraning == 2)
        {
            system("CLS");
            BakerUI b;
            b.main();
        }
        else if ( innskraning == 3)
        {
            system("CLS");
            AfhendingUI a;
            a.main();
        }
        else if ( innskraning == 4)
        {
            system("CLS");
            SalaUI s;
            s.mainOrder();
        }
        else if (innskraning == 5)
        {
            system("CLS");
            ErrorExceptionUI err;
            err.mainUI();
        }
        else if (innskraning == 6)
        {
            exit(0);
        }
    }
    catch(InputErrorException e)
    {
        ErrorException er;
        er.logInputErrorException(e);
        cout << e.getMessage() << endl;
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
        helperUI.displayBelowHeader("Til thess ad skra thig inn veldu: ");
        mainMenu();
    }

    return 0;
}
