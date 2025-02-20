#include "ErrorTranslator.h"
#include "ErrorCode.h"

ErrorTranslator::ErrorTranslator()
{
    m_checkError = Constants::ERROR_CODES::ErrorNone;
}

ErrorTranslator::ErrorTranslator(unsigned val)
{
    m_checkError = val;
}

ErrorTranslator::~ErrorTranslator()
{
    //dtor
}
