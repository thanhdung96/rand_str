#ifndef ERRORCODE_H_INCLUDED
#define ERRORCODE_H_INCLUDED

namespace Constants
{
    enum ERROR_CODES
    {
        ErrorNone = 0,
        NotLinux = 1,
        DevRandNotFound = 2,
        DevRandCannotRead = 4,
        DevURandNotFound = 32,
        DevURandCannotRead = 64,
    };
}

#endif // ERRORCODE_H_INCLUDED
