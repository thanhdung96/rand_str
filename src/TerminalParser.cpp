#include "TerminalParser.h"
#include "RandStrConstraints.h"
#include "TerminalConstants.h"

TerminalParser::TerminalParser()
{
    m_strLen = Constants::StrLen::MIN_LEN;
    m_digitCount = Constants::None;
    m_specialCharCount = Constants::None;
    m_uppercaseCount = Constants::None;
}

TerminalParser::~TerminalParser()
{
    //dtor
}

unsigned int TerminalParser::GetStrLen()
{
    return m_strLen;
}

unsigned TerminalParser::GetDigitCount()
{
    return m_digitCount;
}

bool TerminalParser::GetRequiresDigit()
{
    return m_digitCount > Constants::None;
}

unsigned TerminalParser::GetSpecialCharCount()
{
    return m_specialCharCount;
}

bool TerminalParser::GetRequiresSpecialChar()
{
    return m_specialCharCount > Constants::None;
}

unsigned TerminalParser::GetUppercaseCount()
{
    return m_uppercaseCount;
}

bool TerminalParser::GetRequiresUppercase()
{
    return m_uppercaseCount > Constants::None;
}

void TerminalParser::parse(int argc, char* argv[])
{
    for(int argI = 1; argI < argc; argI += 2)
    {
        if (argv[argI] == Constants::Terminal::LEN_ARG)
        {
            m_strLen = std::stoi(argv[argI + 1]);
        }
        else if (argv[argI] == Constants::Terminal::UPPERCASE_ARG)
        {
            m_uppercaseCount = std::stoi(argv[argI + 1]);
        }
        else if(argv[argI] == Constants::Terminal::DIGIT_ARG)
        {
            m_digitCount = std::stoi(argv[argI + 1]);
        }
        else if (argv[argI] == Constants::Terminal::SPECIAL_CHAR_ARG)
        {
            m_specialCharCount = std::stoi(argv[argI + 1]);
        }
    }
}
