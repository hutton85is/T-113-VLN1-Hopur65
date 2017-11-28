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
        vector<string> read();
        virtual ~AddHero();

    private:
};

#endif // ADDHERO_H
