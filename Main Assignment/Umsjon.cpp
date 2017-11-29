#include "Umsjon.h"

Umsjon::Umsjon()
{
}

Umsjon::~Umsjon()
{
    //dtor
}

void Umsjon::enterPizzaSize()
{
    Pizza p;
    pair <char[32], int> tempPair;
    cout << "enter pizza size" << endl;
    cin >> tempPair.first;
    cout << "enter prize of pizza" << endl;
    cin >> tempPair.second;
    p.menuSize.push_back(tempPair);
}

void Umsjon::print()
{
    cout << menuSize[0].first << endl;
    cout << menuSize[0].second << endl;
}
