#include "ErrorUI.h"

ErrorUI::ErrorUI()
{

}

void ErrorUI::displayErrorCount()
{
    int input;
    Error er;

    cout << er << endl;
    cout << "Veldu videigandi numer til ad skoda nanar allar villur: ";
    cin >> input;

    if(input == 1)
    {
        Error er;
        vector <InputErrorException> inputErrorExceptionVec = er.getInputErrorExceptionVec();
        for(unsigned int i = 0; i < inputErrorExceptionVec.size(); i++)
        {
            cout << inputErrorExceptionVec[i] << endl;
        }
    }

}

void ErrorUI::mainUI(){

    displayErrorCount();
    system("pause");
}
