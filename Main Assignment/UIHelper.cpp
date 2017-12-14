#include "UIHelper.h"

UIHelper::UIHelper()
{

}

void UIHelper::displayHeader()
{
    cout << "---------------------------------------------------------" << endl;
    cout << "               Velkomin/nn a Pizzastadinn!               " << endl;
    cout << "---------------------------------------------------------" << endl;
}


void UIHelper::displayBelowHeader(string message)
{
    cout << " " << message << endl;
}

void UIHelper::displayColumn(string col1, string col2)
{
    cout << "--------------------------------" << endl;
    cout << " " << col1 << " | " << col2 << endl;
    cout << "--------------------------------" << endl;
}

void UIHelper::displayCloseTable()
{
    cout << "--------------------------------" << endl;
}
