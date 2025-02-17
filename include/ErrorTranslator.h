#ifndef ERROR_TRANSLATOR_H
#define ERROR_TRANSLATOR_H


class ErrorTranslator
{
public:
    ErrorTranslator();
    ErrorTranslator(unsigned val);
    virtual ~ErrorTranslator();

    unsigned GetCheckError();
    void SetCheckError(unsigned val);

protected:

private:
    unsigned m_checkError;
};

#endif // ERROR_TRANSLATOR_H
