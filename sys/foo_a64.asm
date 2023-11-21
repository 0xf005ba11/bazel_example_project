; "ksarm64.h" is currently missing from the EWDK, so many useful macros are missing (e.g. TEXTAREA).
; It can be copied from the WDK to the EWDK as a possible solution:
;   * ksarm64.h
;   * kxarm64.h
;   * kxarm64unw.h
; // #include "ksarm64.h"

    ; TEXTAREA
    AREA    |.text|,ALIGN=4,CODE,READONLY
    EXPORT Foo1234

Foo1234 PROC

    mov x0, #0x1234
    ret

    ENDP
    END
