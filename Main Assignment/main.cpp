#include <iostream>
#include <stdlib.h>

#include "UmsjonUI.h"
#include "SalaUI.h"
#include <stdlib.h>

using namespace std;

<<<<<<< HEAD
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


=======
int mainMenu()
{
    int val;
    cout << "1 : Umsjon" << endl;
    cout << "2 : Sala" << endl;
    cout << "3 : Exit" << endl;
    cin >> val;
    return val;
}

>>>>>>> master
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
