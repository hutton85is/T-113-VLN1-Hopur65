#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>

using namespace std;

class Pizza
{
    public:
        Pizza();
        virtual ~Pizza();

        vector <pair <char[32], int> > menuSize;
        vector <pair <char[32], int> > menuToppings;
        vector <pair <char[32], int> > menuCrust;
        vector <pair <char[32], int> > menuExtras;
        vector <pair <char[32], int> > menuPizzas;
        vector <pair <char[32], int> > menuLocation;

        bool loadFile();
        void writeFile(Pizza& p);
        void displayVector(vector <pair <char[32], int> >& vec);

    protected:

    private:
};

#endif // PIZZA_H
