#include "ErrorTranslator.h"
#include "ErrorCode.h"
using namespace Constants;

ErrorTranslator::ErrorTranslator()
{
    m_checkError = ERROR_CODES::ErrorNone;
}

ErrorTranslator::ErrorTranslator(unsigned val)
{
    m_checkError = val;
}

ErrorTranslator::~ErrorTranslator()
{
    //dtor
}
