#include <iostream>
#include <fstream>
#include <string>
#include "Superhero.h"
#include "AddHero.h"

using namespace std;


/*
* Display main menu for user with available options
* and retrieve user input as character.
* Return the choice from user.
*/
char mainMenu()
{
    char choose;
    cout << "Enter what you wish to do:" << endl;
    cout << "Press 'c' to create a hero" << endl;
    cout << "Press 'd' to display a list of all heroes" << endl;
    cout << "Press 'q' to quit" << endl;
    cin >> choose;

    return choose;
}

/*
* Function to retrieve name, age and special
* ability for the new hero to be created.
* Return class 'Superhero' of a new superhero created.
*/
Superhero newSuperhero()
{
    // Initialize all attributes of a superhero
    string nafn = "";
    int aldur = 0;
    char ofurkraftur = 'n';

    cout << "Enter name of superhero: " << endl;
    cin >> nafn;
    cout << "Enter age of superhero: " << endl;
    cin >> aldur;
    cout << "Enter special ability of superhero, flying, giant, hacker, none" << endl;
    cin >> ofurkraftur;

    // Create the new superhero with its attributes
    Superhero s(nafn, aldur, ofurkraftur);

    return s;
}

int main()
{
    // Run the program, if any error's are thrown they will be caught and program will be terminated
    try
    {
        // Create an instance of AddHero which loads all stored heroes from a txt file
        AddHero add;

        char choose;

        // Loop through menu while user still wants to add or display heroes
        do
        {
            choose = mainMenu();

            if (choose == 'c' || choose == 'C')
            {
                Superhero s = newSuperhero();
                add.write(s);
            }
            else if(choose == 'd' || choose == 'D')
            {
                cout << add << endl;
            }
        }while(choose != 'q');
    }

    // If an error is caught it is displayed here and the program is terminated
    catch(int e)
    {
        cout << "There is no file to read, error: " << e << endl;
        return 0;
    }

    return 0;
}
