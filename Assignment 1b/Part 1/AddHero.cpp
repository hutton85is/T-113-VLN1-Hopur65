#include "AddHero.h"

AddHero::AddHero()
{
    //ctor
}

void AddHero::write(istream& ins)
{
    ofstream file;
    file.open("superhero.txt", ios_base::app);
    ins >> file;
    file.close;
}

AddHero::~AddHero()
{
    //dtor
}
