#include <iostream>
#include "SystemCheck.h"
#include "RandStr.h"
#include "ErrorCode.h"
#include "TerminalParser.h"
using namespace std;

int main(int argc, char* argv[])
{
    TerminalParser parser;
    parser.parse(argc, argv);

    SystemCheck sysCheck;
    sysCheck.doCheck();
    unsigned errorCheck = sysCheck.getError();
    if (errorCheck != Constants::ERROR_CODES::ErrorNone)
    {
        cout << "system not ready" << endl;
        cout << errorCheck;

        return 1;
    }

    RandStr randString;
    randString.configWithParser(parser);
    randString.prepare();
    cout << randString.generateStr() << endl;

    return 0;
}
