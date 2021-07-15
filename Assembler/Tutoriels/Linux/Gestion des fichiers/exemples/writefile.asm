
;Flags
O_RDONLY    equ 0
O_WRONLY    equ 1
O_RDWR      equ 2
 
O_CREAT     equ 64
O_EXCL      equ 128
O_NOCTTY    equ 256
O_TRUNC     equ 512
O_APPEND    equ 1024
O_NONBLOCK  equ 2048
O_NDELAY    equ 2048
O_DSYNC     equ 4096
O_ASYNC     equ 8192
O_DIRECT    equ 16384
O_DIRECTORY equ 65536
O_NOFOLLOW  equ 131072
O_NOATIME   equ 262144
O_CLOEXEC   equ 524288
O_SYNC      equ 1052672
O_PATH      equ 2097152
O_TMPFILE   equ 4259840
 
O_LARGEFILE equ 0

section .data
	filename db "file.txt", 0
	filecontent db "I like assembly"
	filecontent_len equ $-filecontent
section .text
	global _start
	_start:
		; Ouvrir dans le fichier :
		mov rax, 2 ; sys_open
		mov rdi, filename ; Le nom du fichier où écrire qui doit être null terminated (Il doit y'avoir un null byte à la fin de celui-ci )
		mov rsi, O_APPEND+O_WRONLY ; On veut créer le fichier et seulement écrire dedans
		mov rdx, 0644o ; La permission en octal du fichier à créer
		syscall

		push rax ; On sauvegarde le File descriptor contenu dans rax sur le haut de la pile

		; Ecrire dans le fichier :
		mov rdi, rax ; Le file descriptor retourné avec sys_open 
		mov rax, 1 ; sys_write
		mov rsi, filecontent ; Quoi mettre dans ce fichier
		mov rdx, filecontent_len ; La longueur de la chaîne à mettre dans le fichier
		syscall

		; Fermer le fichier :
		mov rax, 3 ; sys_close
		pop rdi ; On récupère le File Descriptor qui était sur le haut de pile
		syscall

		; Quitter le programme
		mov rax, 60
		mov rdi, 0
		syscall