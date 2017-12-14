#include "ErrorExceptionUI.h"

ErrorExceptionUI::ErrorExceptionUI()
{

}

void ErrorExceptionUI::displayErrorCount()
{
    int input;

    ErrorException err;
    cout << err << endl;
    cout << "Veldu videigandi numer til ad skoda nanar allar villur: ";
    cin >> input;

    if(input == 1)
    {
        ErrorException er;
        vector <InputErrorException> inputErrorExceptionVec = err.getInputErrorExceptionVec();
        for(unsigned int i = 0; i < inputErrorExceptionVec.size(); i++)
        {
            cout << inputErrorExceptionVec[i] << endl;
        }
    }
}

void ErrorExceptionUI::mainUI()
{
    displayErrorCount();
    system("pause");
}
