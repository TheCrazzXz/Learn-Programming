section .data
	text1 db "Yes !", 0x0A 
	text2 db "Nope !", 0x0A

section .text
	global _start

	_exit:
		mov rax, 60
		mov rdi, 0
		syscall

	_yes:
		mov rax, 1
		mov rdi, 1
		mov rsi, text1
		mov rdx, 6
		syscall
		jmp _exit

	_no:
		mov rax, 1
		mov rdi, 1
		mov rsi, text2
		mov rdx, 7
		syscall
		jmp _exit

	_start:
		mov rax, 6
		mov rbx, rax
		cmp rbx, 6
		je _yes
		jne _no
