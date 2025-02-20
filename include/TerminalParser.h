#ifndef TERMINAL_PARSER_H
#define TERMINAL_PARSER_H


class TerminalParser
{
public:
    TerminalParser();
    virtual ~TerminalParser();

    void parse(int argc, char* argv[]);

    unsigned int GetStrLen();
    unsigned GetDigitCount();
    bool GetRequiresDigit();
    unsigned GetSpecialCharCount();
    bool GetRequiresSpecialChar();
    unsigned GetUppercaseCount();
    bool GetRequiresUppercase();

private:
    unsigned int m_strLen;
    unsigned m_digitCount;
    unsigned m_specialCharCount;
    unsigned m_uppercaseCount;
};

#endif // TERMINAL_PARSER_H
