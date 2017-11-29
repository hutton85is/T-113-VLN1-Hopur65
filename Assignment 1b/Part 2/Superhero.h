#ifndef SUPERHERO_H
#define SUPERHERO_H

#include <iostream>
#include <string>

using namespace std;

class Superhero
{
    public:
        Superhero();
        Superhero(/*char nafn[32], */int aldur, char ofurkraftur);
        virtual ~Superhero();

        void print(ostream& outs);

        char nafn[32];
        int aldur;
        char ofurkraftur;

        friend ostream& operator <<(ostream &outs, Superhero& superhero);
        friend istream& operator >>(istream &ins, Superhero& superhero);

    private:
        //char* nafn;

        string getPower();
};

#endif // SUPERHERO_H
