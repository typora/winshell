#ifndef _shell_execute_ex_h_
#define _shell_execute_ex_h_

#define NTDDI_VERSION NTDDI_VISTA
#define WIN_VER _WIN32_WINNT_LONGHORN
#define _WIN32_WINNT _WIN32_WINNT_LONGHORN

#include <shlobj.h>
#include <windows.h>
#include <string>

#pragma comment(lib, "shell32.lib")

void OpenAs(const wchar_t *file) {
    OPENASINFO info = {0};
    info.pcszFile = file;
    info.oaifInFlags = 0;

    SHOpenWithDialog(NULL, &info);
}

#endif