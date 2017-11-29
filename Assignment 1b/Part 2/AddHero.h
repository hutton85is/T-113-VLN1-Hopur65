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
        AddHero();
        void write(Superhero& s);
        virtual ~AddHero();
        friend ostream& operator <<(ostream& outs, AddHero& hero);

    private:
        vector<Superhero> heroesVector;
        void print();
        bool loadFile();

};

#endif // ADDHERO_H
