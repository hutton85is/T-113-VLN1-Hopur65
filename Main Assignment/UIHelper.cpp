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
