#ifndef SUPERHERO_H
#define SUPERHERO_H

#include <iostream>
#include <string>

using namespace std;

class Superhero
{
    public:
        Superhero();
        Superhero(string nafn, int aldur, char ofurkraftur);
        virtual ~Superhero();

        friend ostream& operator <<(ostream &outs, Superhero& superhero);
        friend istream& operator >>(istream &ins, Superhero& superhero);

    private:
        string nafn;
        int aldur;
        char ofurkraftur;
};

#endif // SUPERHERO_H
