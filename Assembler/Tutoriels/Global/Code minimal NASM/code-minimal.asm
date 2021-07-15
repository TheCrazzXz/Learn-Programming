section .data
	; La pile du programme (stack) où vont les variables

section .text ; La section exécutable (le code)
	global _start ; La fonction _start sera donc le point d'entrée du programme
	
	_start: ; On définit _start
		; Le code de la fonction principale va ici