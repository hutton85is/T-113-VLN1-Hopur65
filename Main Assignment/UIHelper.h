/**
* @brief A class that has some display helper functions
*
* Display helper functions are used throughout the program were constant display is needed
*/

#ifndef UIHELPER_H
#define UIHELPER_H

#include <iostream>

using namespace std;

class UIHelper
{
    public:

        UIHelper();

        void displayHeader();

        void displayBelowHeader(string message);

        void displayColumn(string col1, string col2);

        void displayCloseTable();
};

#endif // UIHELPER_H
