#include "AddHero.h"

AddHero::AddHero()
{
    if(!loadFile())
    {
        throw -1;
    }
}

bool AddHero::loadFile()
{
    ifstream file;
    file.open("superhero.dat", ios::binary);
    if(file.is_open())
    {
        file.seekg(0, ios::end); // put the "cursor" at the end of the file
        int length = file.tellg(); // find the position of the cursor, which tells the size of the file
        if (length != 0)
        {
            Superhero readHero;
            int records = file.tellg() / sizeof(Superhero); //find how many entries are in the file
            file.seekg(0, file.beg); // Go back with the cursor to beginning of a file for reading
            for(int i = 0; i < records; i++)
            {
                file.read((char*) (&readHero), sizeof(Superhero));
                // push hero read from file at the back of the vector
                heroesVector.push_back(readHero);
            }

            file.close();
        }
        return true;
    }
    return false;
}

ostream& operator <<(ostream& outs, AddHero& hero)
{
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
    file.open("superhero.dat", ios_base::app|ios_base::binary);
    file.write((char*)(&s), sizeof(Superhero));
    file.close();
}

AddHero::~AddHero()
{
    //dtor
}
