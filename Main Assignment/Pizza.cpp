#include "Pizza.h"

Pizza::Pizza()
{
    if(!loadFile())
    {
        throw -1;
    }
}

Pizza::~Pizza()
{
    //dtor
}

void Pizza::displayVector(vector <pair <char[32], int> >& vec)
{
    for(unsigned int i = 0; i < vec.size(); i++)
    {
        cout << vec[i].first << " : " << vec[i].second << endl;
    }
}

bool Pizza::loadFile()
{
    ifstream file;
    file.open("pizza.dat", ios::binary);
    if(file.is_open())
    {
        file.seekg(0, ios::end); // put the "cursor" at the end of the file
        int length = file.tellg(); // find the position of the cursor
        if (length != 0)
        {
            Pizza readPizza;
            file.read((char*) (&readPizza), sizeof(Pizza));
            file.close();
        }
        return true;
    }
    return false;
}

void Pizza::writeFile(Pizza& p)
{
    ofstream file;
    file.open("pizza.dat", ios_base::app|ios_base::binary);
    file.write((char*)(&p), sizeof(Pizza));
    file.close();
}
