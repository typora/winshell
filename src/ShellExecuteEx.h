#ifndef _shell_execute_ex_h_
#define _shell_execute_ex_h_

#include <windows.h>
#include <shellapi.h>
#pragma comment(lib, "shell32.lib")

BOOL RunShellExecuteEx(const char *verb, const char *file) {
    SHELLEXECUTEINFO sei = { sizeof(sei) };
    sei.fMask = SEE_MASK_FLAG_DDEWAIT;
    sei.nShow = SW_SHOWNORMAL; // added 27 Nov
    sei.lpVerb = verb;
    sei.lpFile = file;
    return ShellExecuteEx(&sei);
}


#endif