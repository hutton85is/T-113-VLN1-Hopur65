#ifndef READWRITECLASS_H
#define READWRITECLASS_H

#include "Pizza.h"

/*
*
*/

class readWriteClass
{
    public:
        readWriteClass();
        virtual ~readWriteClass();

        /*
        * Function that writes a template class to binary file under filename
        * and path under variable 'fname'. If the file does not exist, it is created.
        */
        template <typename pizzaClass>
        void writeClassToFile(pizzaClass& classToWrite, const char* fname);

        // Function that loads all vectors from database containing all items available for sale and stores them in Pizza class 'p'
        void loadAllVectors(Pizza& p);

    private:
        /*
        * boolean function that loads a vector from a specific file storing a template class
        * loadvector is the template vector to be loaded from file
        * fileName is a variable containing the path and filename to the class to load
        * pClass is a variable containing the template class to be loaded from a file
        */
        template <typename pizzaClass>
        bool loadSpecificVector(vector<pizzaClass>& loadVector, const char* fileName, pizzaClass& pClass);

        // This is a dummy loader that if I dont include I cant use writeClassToFile function
        void dummyLoader();
};

#endif // READWRITECLASS_H
