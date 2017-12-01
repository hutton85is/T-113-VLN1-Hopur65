#include "Superhero.h"

Superhero::Superhero()
{
    nafn[0] = '0';
    aldur = 0;
    ofurkraftur = 'n';
}

Superhero::Superhero(int aldur, char ofurkraftur)
{
    this->aldur = aldur;
    this->ofurkraftur = ofurkraftur;
}

Superhero::~Superhero()
{
    //dtor
}

string Superhero::getPower()
{
    if(ofurkraftur == 'f' || ofurkraftur == 'F')
    {
        return "Flying";
    }
    else if(ofurkraftur == 'g' || ofurkraftur == 'G')
    {
        return "Giant";
    }
    else if(ofurkraftur == 'h' || ofurkraftur == 'H')
    {
        return "Hacker";
    }
    else if(ofurkraftur == 'n' || ofurkraftur == 'N')
    {
        return "None";
    }

    return "";
}

void Superhero::print(ostream& outs)
{
    outs << nafn << " (" << aldur << "): " << getPower() << endl;
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
