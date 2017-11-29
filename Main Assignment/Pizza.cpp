#include "Pizza.h"

Pizza::Pizza()
{
}

Pizza::~Pizza()
{
    //dtor
}

void Pizza::displayVector(vector <pair <char[32], int> >& vec)
{
    cout << "elements in vector: " << vec.size() << endl;
    for(unsigned int i = 0; i < vec.size(); i++)
    {
        cout << "i: " << i << endl;
        cout << vec[i].first << " : " << vec[i].second << endl;
    }
}

Pizza& Pizza::loadFile(Pizza& p)
{
    ifstream file;
    file.open("pizza.dat", ios_base::binary);
    if(file.is_open())
    {
        file.seekg(0, file.end); // put the "cursor" at the end of the file
        int length = file.tellg(); // find the position of the cursor
        file.seekg(0, file.beg);
        if (length != 0)
        {
            file.read((char*) (&p), sizeof(Pizza));
        }
        file.close();
        return p;
    }
    return p;
}

void Pizza::writeFile(Pizza& p)
{
    ofstream file;
    file.open("pizza.dat", ios_base::app|ios_base::binary);
    file.write((char*)(&p), sizeof(Pizza));
    file.close();
}
