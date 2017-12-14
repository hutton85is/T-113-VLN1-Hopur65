/**
* @brief User interface for viewing exception log
*
* A user can view count of exceptions and then choose to view a particular exception and its message
*/


#ifndef ERROREXCEPTIONUI_H
#define ERROREXCEPTIONUI_H

#include "ErrorException.h"

class ErrorExceptionUI
{
    public:

        ErrorExceptionUI();

        void displayErrorCount();

        void mainUI();

};

#endif // ERROREXCEPTIONUI_H
