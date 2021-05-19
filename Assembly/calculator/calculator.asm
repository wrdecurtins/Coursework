%include "/usr/local/share/csc314/asm_io.inc"


segment .data


segment .bss


segment .text
	global  asm_main

asm_main:
	push	ebp
	mov		ebp, esp
	; ********** CODE STARTS HERE **********


	;Get first integer from user
	call	read_int
	mov 	ebx, eax

	;Get operator from the user
	call	read_char
	call	read_char
	mov		edx, eax

	;Get second integer from user
	call	read_int
	mov		ecx, eax

	;Print an equals sign
	mov 	eax, "="
	call	print_char
	call	print_nl

	;check to see if operation is addition
	cmp		edx, "+"
	je		addition

	;check to see if operation is subtraction
	cmp		edx, "-"
	je		subtraction

	;check to see if operation is multiplication
	cmp		edx, "*"
	je		multiplication

	;check to see if operation is division
	cmp		edx, "/"
	je		division

	;check to see if operation is modulus
	cmp		edx, "%"
	je		modulus

	;check to see if operation is exponent
	cmp		edx, "^"
	je		exponent

	;This section does the work for addition and prints the solution
	addition:
	add		ebx, ecx
	mov		eax, ebx
	call	print_int
	call	print_nl
	jmp		exit

	;This section does the work for subtraction and prints the solution
	subtraction:
	sub		ebx, ecx
	mov		eax, ebx
	call	print_int
	call	print_nl
	jmp		exit

	;This section does the work for multiplication and prints the solution
	multiplication:
	mov		eax, ebx
	imul	ecx
	call	print_int
	call	print_nl
	jmp		exit

	;This section does the work for division and prints the solution
	division:
	mov		eax, ebx
	mov		edx, 0
	idiv	ecx
	call	print_int
	call	print_nl
	jmp		exit

	;This section does the work for modulus and prints the solution
	modulus:
	mov		eax, ebx
	mov		edx, 0
	idiv	ecx
	mov		eax, edx
	call	print_int
	call	print_nl
	jmp		exit

	;This section does the work for exponent and prints the solution
	exponent:
	mov		edx, 0
	mov		eax, ebx

	;This loop runs through and multiplies as many times as necessary
	top_exp_loop:
	cmp		ecx, 1
	je		bottom_exp_loop
		imul	ebx
		dec		ecx
		jmp		top_exp_loop
	bottom_exp_loop:

	call	print_int
	call	print_nl
	jmp		exit

	exit:


	; *********** CODE ENDS HERE ***********
	mov		eax, 0
	mov		esp, ebp
	pop		ebp
	ret
