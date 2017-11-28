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
        void print();
        virtual ~AddHero();
        friend ostream& operator <<(ostream& outs, AddHero& hero);
        vector<Superhero> heroesVector;

    private:

};

#endif // ADDHERO_H
