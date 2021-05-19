%include "/usr/local/share/csc314/asm_io.inc"


segment .data
;	coolvar		dd		1,3,5,7,8,9,11,13,15,17,19
;	str1		dd		"hello world",10,0
	coolvar		dd		0,0,0,0,0,0,0,0,0,0
segment .bss


segment .text
	global  asm_main

asm_main:
	push	ebp
	mov		ebp, esp
	; ********** CODE STARTS HERE **********

;	mov 	ecx, 0
;	top_loop:
;	cmp 	ecx, 10
;	jge		bottom_loop

;		mov 	eax, dword [coolvar + ecx * 4 ]
;		call	print_int
;		call	print_nl

;	inc		ecx
;	jmp		top_loop
;
;	bottom_loop:

	mov		ecx, 0
	read_top:
	cmp		ecx, 10
	jge		read_bottom

		call 	read_int
		mov		dword[coolvar+ecx*4], eax

	inc		ecx
	jmp		read_top
	read_bottom:


	mov 	ecx, 9
	top_loop:
	cmp 	ecx, -1
	je		bottom_loop

		mov 	eax, dword [coolvar + ecx * 4 ]
		call	print_int
		call	print_nl

	dec		ecx
	jmp		top_loop

	bottom_loop:

;	mov 	eax, str1
;	call	print_string

	; *********** CODE ENDS HERE ***********
	mov		eax, 0
	mov		esp, ebp
	pop		ebp
	ret
