#include "AddHero.h"

AddHero::AddHero()
{
    //ctor
}

void AddHero::write(Superhero& s)
{
    ofstream file;
    file.open("superhero.txt", ios_base::app);
    file << s;
    file.close();
}

vector<string> AddHero::read()
{
    vector<string> fileVector;
    string line;
    ifstream file;
    file.open("superhero.txt");
    while(!file.eof())
    {
        getline(file, line);
        fileVector.push_back(line);
    }

    return fileVector;
}

AddHero::~AddHero()
{
    //dtor
}
