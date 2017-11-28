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

void Superhero::addHero(Superhero s)
{
    AddHero add;
    istream& ins;
    ins >> s;
    add.write(ins);
}

ostream& operator <<(ostream &outs, Superhero& superhero)
{
    outs << superhero.nafn << " " << superhero.aldur << ": " << superhero.ofurkraftur << endl;
    return outs;
}

istream& operator >>(istream &ins, Superhero& superhero)
{
    ins >> superhero.nafn >> superhero.aldur >> superhero.ofurkraftur;
    return ins;
}
