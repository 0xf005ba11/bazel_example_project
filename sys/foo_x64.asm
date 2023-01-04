include ksamd64.inc

PUBLIC GetCpuid

_TEXT SEGMENT

; silly example. use __cpuid intrinsic in real code

; void GetCpuid(DWORD type, DWORD result[4])
NESTED_ENTRY GetCpuid, _TEXT

        rex_push_reg rbx
    END_PROLOGUE

        mov eax, ecx
        mov r8, rdx
        xor ecx, ecx
        cpuid
        mov [r8 +  0], eax
        mov [r8 +  4], ebx
        mov [r8 +  8], ecx
        mov [r8 + 12], edx
        pop rbx
        ret
NESTED_END GetCpuid, _TEXT

_TEXT ENDS

END