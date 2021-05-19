%include "/usr/local/share/csc314/asm_io.inc"


segment .data


segment .bss


segment .text
	global  asm_main

asm_main:
	push	ebp
	mov		ebp, esp
	; ********** CODE STARTS HERE **********

	mov 	eax, 9
	top_for_loop:
	cmp 	eax, 99
	jge		end_for_loop
		call	print_int
		add		eax, 2
	jmp 	top_for_loop
	end_for_loop:

	; *********** CODE ENDS HERE ***********
	mov		eax, 0
	mov		esp, ebp
	pop		ebp
	ret
