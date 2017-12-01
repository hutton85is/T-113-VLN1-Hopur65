#ifndef ADDHERO_H
#define ADDHERO_H

#include <fstream>
#include <string>
#include <vector>

#include "Superhero.h"

using namespace std;

class AddHero
{
    public:
        /*
        * Constructor calls a function to load all heroes available from a file into a vector.
        * If there is an error loading superheroes from the file an error -1 is thrown
        */
        AddHero();

        /*
        * Write a new superhero from variable s into a file and store it in vector heroesVector
        */
        void write(Superhero& s);

        virtual ~AddHero();

        // Override the ostream << operator to write all heroes from vector 'heroesVector'
        friend ostream& operator <<(ostream& outs, AddHero& hero);

    private:
        // Vector containing all superheroes
        vector<Superhero> heroesVector;

        /*
        * Load file with a list of superheroes, and push them on a vector
        * Return true if the file exists, else return false
        */
        bool loadFile();

};

#endif // ADDHERO_H
