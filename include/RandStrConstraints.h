#ifndef RANDSTR_CONSTRAINTS_H_INCLUDED
#define RANDSTR_CONSTRAINTS_H_INCLUDED

#include <string>

namespace Constants {
    const unsigned None = 0;
    const unsigned CharSize = sizeof(char);
    const std::string RandDev = "/dev/random";
    const std::string URandDev = "/dev/urandom";

    enum StrLen {
        MIN_LEN = 5,
        MAX_LEN = 60
    };

    enum SpecialCharsCount {
        MIN_COUNT = 1,
        MAX_COUNT = 5
    };
}

#endif // RANDSTR_CONSTRAINTS_H_INCLUDED
