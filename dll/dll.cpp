#include "lib/lib.h"

#ifdef COMPILER_MSVC
#include <Windows.h>

#include "WppTrace.h"
#include "dll.tmh.h"

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD reason, LPVOID reserved)
{
    UNREFERENCED_PARAMETER(hInstance);
    UNREFERENCED_PARAMETER(reserved);
    
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
    {
        WPP_INIT_TRACING( L"dll" );
        SYS_TRACE(TRACE_LEVEL_INFORMATION, TRACE_DLL, L"dll load");
        OutputDebugStringW(L"dll");
        break;
    }
    
    case DLL_PROCESS_DETACH:
    {
        SYS_TRACE(TRACE_LEVEL_INFORMATION, TRACE_DLL, L"dll unload");
        WPP_CLEANUP();
        break;
    }

    default:
        break;
    }

    return TRUE;
}
#endif