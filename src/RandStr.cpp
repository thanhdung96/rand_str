#include <fstream>
#include <sstream>
#include "RandStr.h"
#include "RandStrConstraints.h"
#include "MathHelper.h"
using namespace Constants;

RandStr::RandStr()
{
    m_strLength = StrLen::MIN_LEN;

    m_uppercase = false;
    m_maxUppercase = None;

    m_digit = false;
    m_maxDigit = None;

    m_specialChar = false;
    m_maxSpecialChar = None;
}

RandStr::~RandStr()
{
    m_availableChars.clear();
}

unsigned int RandStr::GetStrLength()
{
    return m_strLength;
}

void RandStr::SetStrLength(unsigned int val)
{
    m_strLength = clamp(StrLen::MAX_LEN, StrLen::MIN_LEN, val);
}

bool RandStr::GetIsUppercase()
{
    return m_uppercase;
}

void RandStr::SetIsUppercase(bool val)
{
    m_uppercase = val;
}

bool RandStr::GetDigit()
{
    return m_digit;
}

void RandStr::SetDigit(bool val)
{
    m_digit = val;
}

bool RandStr::GetIsSpecialChar()
{
    return m_specialChar;
}

void RandStr::SetIsSspecialChar(bool val)
{
    m_specialChar = val;
}

unsigned int RandStr::GetMaxDigit()
{
    return m_maxDigit;
}

void RandStr::SetMaxDigit(unsigned int val)
{
    m_maxDigit = clamp(SpecialCharsCount::MAX_COUNT, SpecialCharsCount::MIN_COUNT, val);
}

unsigned int RandStr::GetMaxSpeciaChar()
{
    return m_maxSpecialChar;
}

void RandStr::SetMaxSpeciaChar(unsigned int val)
{
    m_maxSpecialChar = clamp(SpecialCharsCount::MAX_COUNT, SpecialCharsCount::MIN_COUNT, val);
}

unsigned int RandStr::GetMaxUppercase()
{
    return m_maxUppercase;
}

void RandStr::SetMaxUpperCase(unsigned int val)
{
    m_maxUppercase = clamp(SpecialCharsCount::MAX_COUNT, SpecialCharsCount::MIN_COUNT, val);
}


void RandStr::prepare()
{
    m_availableChars.clear();

    // lowercases
    for (char c = 97; c <= 122; c += 1)
    {
        m_availableChars.insert(pair(c, c));
    }

    // uppercases
    if (m_uppercase)
    {
        for (char c = 65; c <= 90; c += 1)
        {
            m_availableChars.insert(pair(c, c));
        }
    }

    // digits
    if (m_digit)
    {
        for (char c = 48; c <= 57; c += 1)
        {
            m_availableChars.insert(pair(c, c));
        }
    }

    // special characters
    if (m_specialChar)
    {
        for (char c = 33; c <= 47; c += 1)
        {
            m_availableChars.insert(pair(c, c));
        }
        for (char c = 58; c <= 64; c += 1)
        {
            m_availableChars.insert(pair(c, c));
        }
        for (char c = 91; c <= 96; c += 1)
        {
            m_availableChars.insert(pair(c, c));
        }
        for (char c = 123; c <= 126; c += 1)
        {
            m_availableChars.insert(pair(c, c));
        }
    }

}

void RandStr::configWithParser(TerminalParser& parser)
{
    SetStrLength(parser.GetStrLen());

    SetIsUppercase(parser.GetRequiresUppercase());
    SetMaxUpperCase(parser.GetUppercaseCount());

    SetDigit(parser.GetRequiresDigit());
    SetMaxDigit(parser.GetDigitCount());

    SetIsSspecialChar(parser.GetRequiresSpecialChar());
    SetMaxSpeciaChar(parser.GetSpecialCharCount());
}

string RandStr::generateStr()
{
    stringstream strStream;
    ifstream ranDevStream(RandDev, ios::binary);
    unsigned currentLen = 0;

    while (currentLen < m_strLength)
    {
        char c;
        ranDevStream.read((char*) &c, CharSize);

        auto iter = m_availableChars.find(c);
        if (iter != m_availableChars.end())
        {
            strStream << c;
            currentLen += 1;
        }
    }

    return strStream.str();
}
