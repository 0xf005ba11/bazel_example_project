#include <ntifs.h>

#if defined(_AMD64_) || defined(_X86_)
extern "C" void GetCpuid(ULONG type, ULONG result[4]);

bool SupportsRdrand()
{
    const ULONG flag = 1 << 30;
    ULONG result[4];
    GetCpuid(1, result);
    return BooleanFlagOn(result[2], flag);
}
#endif

void Unload(PDRIVER_OBJECT)
{
}

#pragma code_seg("INIT")
extern "C" NTSTATUS NTAPI DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath)
{
    DriverObject->DriverUnload = Unload;

#ifdef _DEBUG
    DbgPrint("sys: do(0x%p), path(%wZ)"
#if defined(_AMD64_) || defined(_X86_)
             ", rdrand(%lu)"
#endif
             "\n",
             DriverObject, RegistryPath
#if defined(_AMD64_) || defined(_X86_)
             ,
             SupportsRdrand()
#endif
    );
#endif

    return STATUS_SUCCESS;
}