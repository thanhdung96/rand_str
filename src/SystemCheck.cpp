#include "SystemCheck.h"
#include "RandStrConstraints.h"
#include "ErrorCode.h"
#include <filesystem>
#include <iostream>
using namespace std;
using namespace Constants;

SystemCheck::SystemCheck()
{
    m_error = ERROR_CODES::ErrorNone;
    m_RandDevPath = RandDev;
    m_URandDevPath = URandDev;
}

SystemCheck::~SystemCheck()
{
    //dtor
}

void SystemCheck::doCheck()
{
    m_error |= checkOs();
    m_error |= checkRandDev();
    m_error |= checkPermissionRandDev();
    m_error |= checkPermissionRandDev();
}
unsigned SystemCheck::getError()
{
    return m_error;
}

unsigned SystemCheck::checkOs()
{
#ifdef _WIN32
    return ERROR_CODES::NotLinux;
#endif

    return ERROR_CODES::ErrorNone;
}

unsigned SystemCheck::checkRandDev()
{
    return exists(m_RandDevPath) ? 0 : ERROR_CODES::DevRandNotFound;
}

unsigned SystemCheck::checkPermissionRandDev()
{
    perms randDevPermissions = status(m_RandDevPath).permissions();

    return perms::none == (randDevPermissions & perms::others_read) ? ERROR_CODES::DevRandCannotRead : ERROR_CODES::ErrorNone;
}

unsigned SystemCheck::checkUrandDev()
{
    return exists(m_URandDevPath) ? 0 : ERROR_CODES::DevURandNotFound;
}

unsigned SystemCheck::checkPermissionUrandDev()
{
    perms uRandDevPermissions = status(m_URandDevPath).permissions();

    return perms::none == (uRandDevPermissions & perms::others_read) ? ERROR_CODES::DevURandCannotRead : ERROR_CODES::ErrorNone;
}
