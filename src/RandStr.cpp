#include <fstream>
#include <iostream>
#include <sstream>
#include "RandStr.h"
#include "RandStrConstraints.h"
using namespace Constants;

RandStr::RandStr()
{
    m_strLength = Constants::StrLen::MIN_LEN;
    m_uppercase = false;

    m_digit = false;
    m_minDigit = Constants::None;
    m_maxDigit = Constants::None;
    m_digitCount = Constants::None;

    m_specialChar = false;
    m_minSpecialChar = Constants::None;
    m_maxSpecialChar = Constants::None;
    m_specialCharCount = Constants::None;
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
    m_strLength = val;
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

unsigned int RandStr::GetMinDigit()
{
    return m_minDigit;
}

void RandStr::SetMinDigit(unsigned int val)
{
    m_minDigit = val;
}

unsigned int RandStr::GetMaxDigit()
{
    return m_maxDigit;
}

void RandStr::SetMaxDigit(unsigned int val)
{
    m_maxDigit = val;
}

unsigned int RandStr::GetMinSpeciaChar()
{
    return m_minSpecialChar;
}

void RandStr::SetMinSpeciaChar(unsigned int val)
{
    m_minSpecialChar = val;
}

unsigned int RandStr::GetMaxSpeciaChar()
{
    return m_maxSpecialChar;
}

void RandStr::SetMaxSpeciaChar(unsigned int val)
{
    m_maxSpecialChar = val;
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
