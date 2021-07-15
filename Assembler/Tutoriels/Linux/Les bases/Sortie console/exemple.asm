section .data
	text db "Hello, World", 0x0A ; On déclare la variable text à "Hello world" concaténé avec 0x0A (10) qui représente '\n' (fin de ligne)

section .text
	global _start
_start:
	; Afficher `text`
	mov rax, 1 ; ID : sys_write (1)
	mov rdi, 1 ; Argument 1 : stdout (1)
	mov rsi, text ; Argument 2 : <buffer (adresse)>
	mov rdx, 14 ; car "Hello, World", 0x0A comporte 14 caractères
	syscall

	; Quitter le programme
	mov rax, 60
	mov rdi, 0
	syscall