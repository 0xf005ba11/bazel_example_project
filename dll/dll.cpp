#include "lib/lib.h"

#ifdef COMPILER_MSVC
#include "WppTrace.h"
#include "dll.tmh.h"

#include <Windows.h>

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD reason, LPVOID reserved)
{
    UNREFERENCED_PARAMETER(hInstance);
    UNREFERENCED_PARAMETER(reserved);

    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
    {
        OutputDebugStringW(L"dll");
        break;
    }

    default:
        break;
    }

    return TRUE;
}
#endif