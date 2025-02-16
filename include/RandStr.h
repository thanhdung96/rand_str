#ifndef RANDSTR_H
#define RANDSTR_H


class RandStr
{
    public:
        static const unsigned MIN_STR_LENGTH = 5;
        static const unsigned MAX_STR_LENGTH = 60;

        RandStr();
        virtual ~RandStr();

        unsigned int GetStrLength();
        void SetStrLength(unsigned int val);
        bool GetIsUppercase();
        void SetIsUppercase(bool val);
        bool GetDigit();
        void SetDigit(bool val);
        bool GetIsSpecialChar();
        void SetIsSspecialChar(bool val);
        unsigned int GetMinDigit();
        void SetmMinDigit(unsigned int val);
        unsigned int GetMinSpeciaChar()
        void SetmNinSpeciaChar(unsigned int val);

    private:
        unsigned int m_strLength;
        bool m_uppercase;
        bool m_digit;
        bool m_specialChar;
        unsigned int m_minDigit;
        unsigned int m_minSpeciaChar;
};

#endif // RANDSTR_H
