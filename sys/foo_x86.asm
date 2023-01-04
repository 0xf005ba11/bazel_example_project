.686P
.MODEL FLAT, STDCALL

_TEXT SEGMENT

; silly example. use __cpuid intrinsic in real code

; void GetCpuid(DWORD type, DWORD result[4])
GetCpuid PROC near, idtype:DWORD, result:DWORD
    push ebx
    push edi

    mov eax, idtype
    mov edi, result
    xor ecx, ecx
    cpuid
    mov [edi +  0], eax
    mov [edi +  4], ebx
    mov [edi +  8], ecx
    mov [edi + 12], edx

    pop edi
    pop ebx
    ret 8
GetCpuid ENDP

_TEXT ENDS

END
