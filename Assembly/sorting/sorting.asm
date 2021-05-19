%include "/usr/local/share/csc314/asm_io.inc"


segment .data

		sortarray		dd		0,0,0,0,0,0,0,0,0,0

segment .bss


segment .text
	global  asm_main

asm_main:
	push	ebp
	mov		ebp, esp
	; ********** CODE STARTS HERE **********

	;This is a for loop that populates the array with 10 user inputed integers
	mov 	ecx, 0
	fillArrayTOP:
		call	read_int
		mov		DWORD [sortarray + 4 * ecx], eax
	inc		ecx
	cmp 	ecx, 10
	jge 	fillArrayBOT
	jmp		fillArrayTOP
	fillArrayBOT:


	;This is the logic for sorting the new array
	mov		edx, 9
	sorterTOP:
	cmp		edx, 0
	je		sorterBOT

	mov		ecx, 0
	bubbleSortTOP:
		mov		eax, DWORD[sortarray + 4 * ecx]
		mov		ebx, DWORD[sortarray + 4 * (ecx + 1)]

		cmp		eax, ebx
		jge		flip
		jmp		nextpair

		flip:
			mov		DWORD[sortarray + 4 * ecx],ebx
			mov		DWORD[sortarray + 4 * (ecx + 1)],eax

	nextpair:
	inc		ecx
	cmp		ecx, edx
	jge		bubbleSortBOT
	jmp		bubbleSortTOP
	bubbleSortBOT:
	dec		edx
	jmp		sorterTOP
	sorterBOT:

	;extra new line for easier reading
	call	print_nl


	;This for loop prints out the sorted array
	mov 	ecx, 0
	printArrayTOP:
		mov		eax, DWORD [sortarray + 4 * ecx]
		call	print_int
		call	print_nl
	inc		ecx
	cmp 	ecx, 10
	jge 	printArrayBOT
	jmp		printArrayTOP
	printArrayBOT:



	; *********** CODE ENDS HERE ***********
	mov		eax, 0
	mov		esp, ebp
	pop		ebp
	ret
