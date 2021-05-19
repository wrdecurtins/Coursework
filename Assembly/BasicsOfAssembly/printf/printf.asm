


;%include "/usr/local/share/csc314/asm_io.inc"


segment .data

	str1		db		"Hello world",10,0
	str2		db		"str 3 is '%s', isn't that cool?",10,0
	str3		db		"woot woot",0
	str4		db		"%c is a char, but so is %%, %s again!",10,0

	str5		db		"%c %s %% %c %s %%",10,0

segment .bss


segment .text
	global  asm_main

asm_main:
	push	ebp
	mov		ebp, esp
	; ********** CODE STARTS HERE **********

	push	str1
	call	printf
	add		esp, 4

	push	str3
	push	str2
	call	printf
	add		esp, 8

	push	str3
	push	'A'
	push	str4
	call	printf
	add		esp, 8

;	push	str3
;	push	"M"
;	push	str3
;	push	"N"
;	push	str5
;	call	printf
;	add		esp, 20

	; *********** CODE ENDS HERE ***********
	mov		eax, 0
	mov		esp, ebp
	pop		ebp
	ret


printf:
	push	ebp
	mov		ebp, esp

	;local incrementing variable
	sub		esp, 8					;int i, j
	mov		DWORD[ebp - 4], 0		;i = 0
	mov		DWORD[ebp - 8], 1		;j = 0, j is a variable designed to help figure out how many parameters deep we need to go


	search_string_loop_top:
	mov		eax, DWORD[ebp + 8]		;read in the main string parameter
	mov		ecx, DWORD[ebp - 4]		;grab the incrementing variable
	cmp		BYTE[eax + ecx], 0		;check to see if we are at the end of the string
	je		search_string_loop_bot
	cmp		BYTE[eax + ecx], "%"	;check to see if we need to grab another parameter
	je		escape_character_handling

		mov		al, BYTE[eax + ecx]
		push	eax
		call	putchar
		add		esp, 4
		jmp		no_escape_character

		escape_character_handling:
		mov		edx, DWORD[ebp - 8] ;grab j as we will need it

		;this will handle the "%%" case
		cmp		BYTE[eax + ecx + 1], "%"
		je		percent_case

		;this will handle the "%c" case
		cmp		BYTE[eax + ecx + 1], "c"
		je		character_case
		jmp		string_case

		percent_case:
		mov		eax, "%"
		push	eax
		call	putchar
		add		esp, 4
		jmp		escape_character_done

		character_case:
		push	DWORD[ebp + 8 + 4 * edx] ; this grabs the parameter we need
		call	putchar
		add		esp, 4
		inc		DWORD[ebp - 8]			 ; this is so we grab the next parameter next time
		jmp		escape_character_done

		string_case:
		push	DWORD[ebp + 8 + 4 * edx]
		call	puts
		add		esp, 4
		inc		DWORD[ebp - 8]
		jmp		escape_character_done


		escape_character_done:
		inc		DWORD[ebp - 4]			; this is so we do not read the character after "%"

		no_escape_character:

	inc		DWORD[ebp - 4]
	jmp		search_string_loop_top
	search_string_loop_bot:

	mov		esp, ebp
	pop		ebp
	ret

putchar:
	push	ebp
	mov		ebp, esp

	mov		eax, 4
	mov		ebx, 1
	lea		ecx, [ebp + 8]
	mov		edx, 1
	int		0x80

	mov		esp, ebp
	pop		ebp
	ret

puts:
	push	ebp
	mov		ebp, esp

	sub		esp, 4
	mov		DWORD[ebp - 4], 0

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

;	push	10
;	call 	putchar
;	add		esp, 4

	mov		esp, ebp
	pop		ebp
	ret







