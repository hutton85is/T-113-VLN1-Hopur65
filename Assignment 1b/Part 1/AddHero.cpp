#include "AddHero.h"

AddHero::AddHero()
{
    ifstream file;
    file.open("superhero.txt");
    while(true)
    {
        Superhero readHero;
        file >> readHero;
        if (file.eof())
        {
            break;
        }
        heroesVector.push_back(readHero);
    }
    file.close();
}

ostream& operator <<(ostream& outs, AddHero& hero)
{
    //outs << hero.heroesVector.size();
    for(unsigned int i = 0; i < hero.heroesVector.size(); i++)
    {
        hero.heroesVector[i].print(outs);
    }
    return outs;
}

void AddHero::write(Superhero& s)
{
    heroesVector.push_back(s);

    ofstream file;
    file.open("superhero.txt", ios_base::app);
    file << s;
    file.close();
}

AddHero::~AddHero()
{
    //dtor
}
