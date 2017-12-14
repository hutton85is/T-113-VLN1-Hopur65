#include "ErrorExceptionUI.h"

ErrorExceptionUI::ErrorExceptionUI()
{

}

void ErrorExceptionUI::displayErrorCount()
{
    int input;

    UIHelper uihelper;

    ErrorException err;

    uihelper.displayHeader();
    uihelper.displayBelowHeader("Villuskilabod");
    cout << endl;

    cout << err << endl << endl;
    cout << "Veldu videigandi numer til ad skoda nanar allar villur: ";
    cin >> input;

    if(input == 1)
    {
        system("CLS");
        uihelper.displayHeader();
        uihelper.displayBelowHeader("Villuskilabod");
        cout << endl;

        ErrorException er;
        vector <InputErrorException> inputErrorExceptionVec = err.getInputErrorExceptionVec();
        for(unsigned int i = 0; i < inputErrorExceptionVec.size(); i++)
        {
            cout << inputErrorExceptionVec[i] << endl;
        }
    }

}

void ErrorExceptionUI::mainUI(){

    displayErrorCount();
    system("pause");
}
