    .syntax unified
    .thumb
    .text
    .align 2                // Align the function code to a 4-byte (2^n) word boundary.
    .thumb                  // Use THUMB-2 instrctions instead of ARM.
    .globl _syscall         // Make the function globally accessible.
    .thumb_func // Use THUMB-2 for the following function.

_syscall:
    #save_context
#if defined(__ARM_ARCH_7M__)
    push {r4-r11}
#elif defined(__ARM_ARCH_6M__)
    push {r4-r7}
    mov r4,r8
    mov r5,r9
    mov r6,r10
    mov r7,r11
    push {r4-r7}
#endif

    #actual SV Call
    isb
    svc 0

    #restore_context
#if defined(__ARM_ARCH_7M__)
    pop {r4-r11}
#elif defined(__ARM_ARCH_6M__)
    pop {r4-r7}
    mov r8,r4
    mov r9,r5
    mov r10,r6
    mov r11,r7
    pop {r4-r7}
#endif

    bx  lr      // Jump back to the caller.

