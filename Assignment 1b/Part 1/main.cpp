#include <iostream>
#include <fstream>
#include "Superhero.h"

using namespace std;

int main()
{
    char choose;
    do{
        cout << "Enter what you wish to do:" << endl;
        cout << "Press 'c' to create a hero" << endl;
        cout << "Press 'd' to display a list of all heroes" << endl;
        cout << "Press 'q' to quit" << endl;
        cin >> choose;

        switch(choose){
        case 'c':
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
            s.addHero(s);
            break;

//        case 'd':
//            //cout << s << endl;
//            break;
//
//        case 'w':
//            ofstream file;
//            file.open("superhero.txt", ios_base::app);
//            file << s;
//            file.close();
//            break;

        }

    }while(choose != 'q');
    return 0;
}
