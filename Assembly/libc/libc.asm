;%include "/usr/local/share/csc314/asm_io.inc"


segment .data

	mystr			db		"DAKOTACON!!!",10,0

segment .bss


segment .text
	global  asm_main
;	extern	getchar
;	extern 	puts

asm_main:
	push	ebp
	mov		ebp, esp
	; ********** CODE STARTS HERE **********

	push	mystr
	call	puts
	add		esp, 4



	call	getchar

	push	eax

;	push	'Z'
	call	putchar
	add		esp, 4

	; *********** CODE ENDS HERE ***********
	mov		eax, 0
	mov		esp, ebp
	pop		ebp
	ret

putchar:
	push	ebp
	mov		ebp, esp

	mov		eax, 4			;SYS_write
	mov		ebx, 1			;STDOUT
	lea		ecx, [ebp + 8]	;pointer to data
	mov		edx, 1			;length
	int 	0x80

	mov		esp, ebp
	pop		ebp
	ret

getchar:
	push	ebp
	mov		ebp, esp

	sub		esp, 4

	mov		eax, 3			;SYS_read
	mov		ebx, 0			;STDIN
	lea		ecx, [ebp - 4] 	;tmp variable
	mov		edx, 1
	int 	0x80

	mov		al, BYTE [ebp - 4]

	mov		esp, ebp
	pop 	ebp
	ret


puts:
	push	ebp
	mov		ebp, esp

	sub		esp, 4					;int i
	mov		DWORD[ebp - 4], 0		;i = 0

	top_of_loop:
	mov		eax, DWORD[ebp + 8]
	mov		ecx, DWORD[ebp - 4]
	cmp		BYTE[eax + ecx], 0
	je		end_of_loop

		mov		al, BYTE[eax + ecx]
		push	eax
		call	putchar
		add		esp, 4

	inc		DWORD[ebp - 4]
	jmp		top_of_loop
	end_of_loop:

	push	10
	call	putchar
	add		esp, 4

	mov		esp, ebp
	pop		ebp
	ret