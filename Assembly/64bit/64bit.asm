
segment .data

	fmtString	db		"Hello %s %d %d %d %d %d %d",10,0
	nameString  db		"William",0

segment .bss


segment .text
	global  main
	extern	printf

main:
	push	rbp
	mov		rbp, rsp
	; ********** CODE STARTS HERE **********

	; printf(fmtString, nameString)

	mov		rdi, fmtString
	mov		rsi, nameString
	mov		rdx, 10
	mov		rcx, 20
	mov		r8, 30
	mov		r9, 40
	push 	60
	push	50
	call	printf
	add		rsp, 16

	; *********** CODE ENDS HERE ***********
	mov		rax, 0
	mov		rsp, rbp
	pop		rbp
	ret
