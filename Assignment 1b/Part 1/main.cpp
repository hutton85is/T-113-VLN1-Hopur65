#include <iostream>
#include <fstream>
#include <string>
#include "Superhero.h"
#include "AddHero.h"

using namespace std;

int main()
{
    AddHero add;
    char choose;
    do{
        cout << "Enter what you wish to do:" << endl;
        cout << "Press 'c' to create a hero" << endl;
        cout << "Press 'd' to display a list of all heroes" << endl;
        cout << "Press 'q' to quit" << endl;
        cin >> choose;

        if (choose == 'c' || choose == 'C')
        {
            string nafn = "";
            int aldur = 0;
            char ofurkraftur = 'n';

            cout << "Enter name of superhero: " << endl;
            cin >> nafn;
            cout << "Enter age of superhero: " << endl;
            cin >> aldur;
            cout << "Enter special ability of superhero, flying, giant, hacker, none" << endl;
            cin >> ofurkraftur;

            Superhero s(nafn, aldur, ofurkraftur);
            add.write(s);
        }
        else if(choose == 'd' || choose == 'D')
        {
            cout << add << endl;
        }

    }while(choose != 'q');
    return 0;
}
