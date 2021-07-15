section .bss
    name resb 16
 
section .text
    global _start

_start:
    call _getStr

    mov rdi, name
    mov rdx, 16
    call _print
 
    mov rax, 60
    mov rdi, 0
    syscall
 
_getStr:
    mov rax, 0
    mov rdi, 0
    mov rsi, name
    mov rdx, 16
    syscall
    ret

_print:
    ;rsi -> buffer ; rdx -> len
    mov rax, 1
    mov rdi, 1
    syscall
    ret