#include <iostream>
#include "SystemCheck.h"
#include "RandStr.h"
#include "ErrorCode.h"
using namespace std;
using namespace Constants;

int main()
{
    SystemCheck sysCheck;
    sysCheck.doCheck();
    unsigned errorCheck = sysCheck.getError();

    if (errorCheck == ERROR_CODES::ErrorNone)
    {
        cout << "system ready" << endl;
    }
    else
    {
        cout << "system not ready" << endl;
        cout << errorCheck;
    }
    RandStr randString;
    randString.prepare();
    string str = randString.generateStr();
    cout << str << endl;

    return 0;
}
