#include "Superhero.h"

Superhero::Superhero()
{
    nafn = "";
    aldur = 0;
    ofurkraftur = 'n';
}

Superhero::Superhero(string nafn, int aldur, char ofurkraftur)
{
    this->nafn = nafn;
    this->aldur = aldur;
    this->ofurkraftur = ofurkraftur;
}

Superhero::~Superhero()
{
    //dtor
}

ostream& operator <<(ostream &outs, Superhero& superhero)
{
    outs << superhero.nafn << " " << superhero.aldur << " " << superhero.ofurkraftur << endl;
    return outs;
}

istream& operator >>(istream &ins, Superhero& superhero)
{
    ins >> superhero.nafn >> superhero.aldur >> superhero.ofurkraftur;
    return ins;
}
