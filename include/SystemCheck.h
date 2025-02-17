#ifndef SYSTEMCHECK_H
#define SYSTEMCHECK_H

#include <string>
#include <filesystem>
using namespace std;
using namespace std::filesystem;

class SystemCheck
{
public:
    SystemCheck();
    virtual ~SystemCheck();

    void doCheck();
    unsigned getError();

private:
    unsigned m_error;
    filesystem::path m_RandDevPath;
    filesystem::path m_URandDevPath;

    unsigned checkOs();
    unsigned checkRandDev();
    unsigned checkPermissionRandDev();
    unsigned checkUrandDev();
    unsigned checkPermissionUrandDev();
};

#endif // SYSTEMCHECK_H
