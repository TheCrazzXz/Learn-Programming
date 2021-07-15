section .data
	text1 db "Le flux d'exécution est dans _start", 0x0A
	text1_len equ $-text1
	text2 db "Le flux d'exécution est dans _autre_label", 0x0A
	text2_len equ $-text2
	text3 db "Le flux d'exécution est dans _encore_autre_label", 0x0A
	text3_len equ $-text3

section .text
	global _start

_exit: ; Pour quitter le programme
	mov rax, 60
	mov rdi, 0
	syscall

_encore_autre_label:
	mov rax, 1
	mov rdi, 1
	mov rsi, text3
	mov rdx, text3_len
	syscall
	jmp _exit

_autre_label:
	mov rax, 1
	mov rdi, 1
	mov rsi, text2
	mov rdx, text2_len
	syscall
	jmp _encore_autre_label

_start:
	mov rax, 1
	mov rdi, 1
	mov rsi, text1
	mov rdx, text1_len
	syscall
	jmp _autre_label