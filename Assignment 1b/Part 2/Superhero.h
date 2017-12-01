#ifndef SUPERHERO_H
#define SUPERHERO_H

#include <iostream>
#include <string>

/*
* The class Superhero.h can create a new superhero, get its superpowers and read or write it self
*/

using namespace std;

class Superhero
{
    public:

        // Constructor for a null value superhero
        Superhero();

        // Constructor for a superhero with necessary information
        Superhero(int aldur, char ofurkraftur);

        virtual ~Superhero();

        // Function to print to screen information about a superhero
        void print(ostream& outs);

        // Name, age and superpower of a superhero
        char nafn[32];
        int aldur;
        char ofurkraftur;

        // Override the << operator to write in a single line,
        // separated by whitespace all attributes of a superhero
        friend ostream& operator <<(ostream &outs, Superhero& superhero);

        // Override the >> operator to read all attributes of a superhero
        friend istream& operator >>(istream &ins, Superhero& superhero);

    private:
        //char* nafn;

        string getPower();
};

#endif // SUPERHERO_H
