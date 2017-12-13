/**
* @brief User interface for viewing exception log
*
* A user can view count of exceptions and then choose to view a particular exception and its message
*/

#ifndef ERRORUI_H
#define ERRORUI_H

#include "Error.h"


class ErrorUI
{
    public:

        ErrorUI();

        void displayErrorCount();

        void mainUI();

    private:

};

#endif // ERRORUI_H
