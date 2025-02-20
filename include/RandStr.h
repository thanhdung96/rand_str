#ifndef RANDSTR_H
#define RANDSTR_H

#include <string>
#include <map>
#include "TerminalParser.h"
using namespace std;

class RandStr
{
public:
    RandStr();
    virtual ~RandStr();

    std::string generateStr();
    void configWithParser(TerminalParser& parser);
    void prepare();

    unsigned int GetStrLength();
    void SetStrLength(unsigned int val);
    bool GetIsUppercase();
    void SetIsUppercase(bool val);
    bool GetDigit();
    void SetDigit(bool val);
    bool GetIsSpecialChar();
    void SetIsSspecialChar(bool val);

    unsigned int GetMaxDigit();
    void SetMaxDigit(unsigned int val);
    unsigned int GetMaxSpeciaChar();
    void SetMaxSpeciaChar(unsigned int val);
    unsigned int GetMaxUppercase();
    void SetMaxUpperCase(unsigned int val);

private:
    unsigned int m_strLength;
    bool m_uppercase;
    bool m_digit;
    bool m_specialChar;
    unsigned int m_maxDigit;
    unsigned int m_maxSpecialChar;
    unsigned int m_maxUppercase;

    std::map<char, char> m_availableChars;
};

#endif // RANDSTR_H
