#include "MathHelper.h"

unsigned clamp(unsigned upper, unsigned lower, unsigned value)
{
    if (value > upper)
    {
        return upper;
    }

    return value < lower ? lower : value;
}

float safeDivison(float dividend, float divisor)
{
    if (divisor == 0)
    {
        return 0;
    }

    return dividend / divisor;
}
