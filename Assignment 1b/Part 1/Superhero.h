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
        Superhero(string nafn, int aldur, char ofurkraftur);
        virtual ~Superhero();

        // Function to print to screen information about a superhero
        void print(ostream& outs);

        // Override the << operator to write in a single line,
        // separated by whitespace all attributes of a superhero
        friend ostream& operator <<(ostream &outs, Superhero& superhero);

        // Override the >> operator to read all attributes of a superhero
        friend istream& operator >>(istream &ins, Superhero& superhero);

    private:

        //Name of superhero
        string nafn;
        // Age of superhero
        int aldur;
        // Superpower of a superhero
        char ofurkraftur;
        // Return superhero powers as string
        string getPower();
};

#endif // SUPERHERO_H
