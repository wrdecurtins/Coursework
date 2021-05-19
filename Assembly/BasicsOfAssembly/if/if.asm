%include "/usr/local/share/csc314/asm_io.inc"


segment .data


segment .bss


segment .text
	global  asm_main

asm_main:
	push	ebp
	mov		ebp, esp
	; ********** CODE STARTS HERE **********

	call	read_int
	mov		esi, eax
	call	read_int
	cmp		esi, eax
	jle		else
		mov		eax, 1337
		call	print_int
		call	print_nl
		jmp end_if
	else:
		mov		eax, 99999
		call	print_int
		call	print_nl
	end_if:

	; *********** CODE ENDS HERE ***********
	mov		eax, 0
	mov		esp, ebp
	pop		ebp
	ret
