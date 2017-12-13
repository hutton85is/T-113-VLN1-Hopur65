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
<<<<<<< HEAD

        readWriteClass();
=======
        ReadWriteClass();
        virtual ~ReadWriteClass();
>>>>>>> f926114eaccea4974aa372e72f4890ab6b25fabd

        template <class pizzaClass>

        void writeClassToFile(pizzaClass& classToWrite, const char* fname);

        /**
        * @brief Function to load vectors containing all available items for sale, and locations of pizza places
        *
        */
        void loadAllVectors(Pizza& p);

        void removeAllContentsOfFile(const char* fname);

<<<<<<< HEAD
        bool loadCustomer(client& customer, vector<Pizza>& order, vector<PizzaHelper>& pHelper, const char* fname);
=======
        // load Pizza order with a specific customer
        bool loadCustomer(Client& customer, vector<Pizza>& order, vector<PizzaHelper>& pHelper, const char* fname);
>>>>>>> f926114eaccea4974aa372e72f4890ab6b25fabd

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
