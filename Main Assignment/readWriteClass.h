#ifndef READWRITECLASS_H
#define READWRITECLASS_H

#include "Pizza.h"
#include "Client.h"
#include "Sala.h"
#include "PizzaHelper.h"
#include <string.h>
#include "InputErrorException.h"

/*
*
*/

class ReadWriteClass
{
    public:
        ReadWriteClass();
        virtual ~ReadWriteClass();

        /*
        * Function that writes a template class to binary file under filename
        * and path under variable 'fname'. If the file does not exist, it is created.
        */
        template <class pizzaClass>
        void writeClassToFile(pizzaClass& classToWrite, const char* fname);

        // Function that loads all vectors from database containing all items available for sale and stores them in Pizza class 'p'
        void loadAllVectors(Pizza& p);

        // Function that removes all contents of a file
        void removeAllContentsOfFile(const char* fname);

        // load Pizza order with a specific customer
        bool loadCustomer(Client& customer, vector<Pizza>& order, vector<PizzaHelper>& pHelper, const char* fname);

        /*
        * boolean function that loads a vector from a specific file storing a template class
        * loadvector is the template vector to be loaded from file
        * fileName is a variable containing the path and filename to the class to load
        * pClass is a variable containing the template class to be loaded from a file
        */
        template <class pizzaClass>
        bool loadSpecificVector(vector<pizzaClass>& loadVector, const char* fileName, pizzaClass& pClass);

    private:

        // This is a dummy loader that if I dont include I cant use writeClassToFile function
        void dummyLoader();
};

#endif // READWRITECLASS_H
