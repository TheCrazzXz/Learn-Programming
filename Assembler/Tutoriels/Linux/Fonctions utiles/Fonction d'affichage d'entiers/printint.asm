section .bss
    digitSpace resb 100
    digitSpacePos resb 8
 
section .text
    global _start
; Exemple 
_start:
 
    mov rax, 256
    call _print_int ; Va afficher "256"
 
    mov rax, 60
    mov rdi, 0
    syscall
 
 
; _print_int : Function to print a number (64 bits)
; input : rax -> number to print

_print_int:
    mov rcx, digitSpace
    mov rbx, 10
    mov [rcx], rbx
    inc rcx
    mov [digitSpacePos], rcx
 
	.print_int_Loop:
	    mov rdx, 0
	    mov rbx, 10
	    div rbx
	    push rax
	    add rdx, 48
	 
	    mov rcx, [digitSpacePos]
	    mov [rcx], dl
	    inc rcx
	    mov [digitSpacePos], rcx
	    
	    pop rax
	    cmp rax, 0
	    jne .print_int_Loop
 
	.print_int_Loop2:
	    mov rcx, [digitSpacePos]
	 
	    mov rax, 1
	    mov rdi, 1
	    mov rsi, rcx
	    mov rdx, 1
	    syscall
	 
	    mov rcx, [digitSpacePos]
	    dec rcx
	    mov [digitSpacePos], rcx
	 
	    cmp rcx, digitSpace
	    jge .print_int_Loop2
	 
	    ret