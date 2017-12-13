/**
 * @brief Data class that writes/reads/removes classes from files
 *
 */


#ifndef READWRITECLASS_H
#define READWRITECLASS_H

#include "Pizza.h"
#include "Client.h"
#include "Sala.h"
#include "PizzaHelper.h"
#include <string.h>
#include "InputErrorException.h"


class ReadWriteClass
{
    public:

        ReadWriteClass();

        template <class pizzaClass>

        void writeClassToFile(pizzaClass& classToWrite, const char* fname);

        /**
        * @brief Function to load vectors containing all available items for sale, and locations of pizza places
        *
        */
        void loadAllVectors(Pizza& p);

        void removeAllContentsOfFile(const char* fname);

        bool loadCustomer(Client& customer, vector<Pizza>& order, vector<PizzaHelper>& pHelper, const char* fname);

        /**
        * @brief load a vector from file
        *
        */
        template <class pizzaClass>
        bool loadSpecificVector(vector<pizzaClass>& loadVector, const char* fileName, pizzaClass& pClass);

    private:

        /**
        * @brief Dummy loader needed for template classes
        *
        * This dummy loader is needed or other classes dont recognize functions in readWriteClass.h and get 'undefined reference error'
        */
        void dummyLoader();
};

#endif // READWRITECLASS_H
