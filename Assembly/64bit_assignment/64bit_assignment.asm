segment .data

  fmt_scan  db          "%d",0
  fmt_print_largest db          "Largest: %d",10,0
  fmt_print_smallest db			"Smallest: %d",10,0
  fmt_print_sum		db			"Sum: %d",10,0

segment .bss

  arr       resd        10

segment .text
  global  main
  extern  scanf
  extern  printf

main:
  push  rbp
  mov       rbp, rsp
  ; ********** CODE STARTS HERE **********

  mov       r15, 0
  top_scan_loop:
  cmp       r15, 10
  jge       end_scan_loop

        mov     rdi, fmt_scan
        lea     rsi, [arr + r15 * 4]
        call    scanf

  inc       r15
  jmp       top_scan_loop
  end_scan_loop:

  mov       r14, 0
  loop1_top:
  cmp       r14, 10
  jge       loop1_end

        mov     r15, 0
        loop2_top:
        cmp     r15, 10
        jge     loop2_end

            mov         r12d, DWORD[arr + r14 * 4]
            mov         r13d, DWORD[arr + r15 * 4]
            cmp         r12d, r13d
            jle         end_if
                mov       DWORD[arr + r14 * 4], r13d
                mov       DWORD[arr + r15 * 4], r12d
            end_if:

        inc     r15
        jmp     loop2_top
        loop2_end:

  inc       r14
  jmp       loop1_top
  loop1_end:

  mov       r15, 0
  mov		r14, 0
  top_sum_loop:
  cmp       r15, 10
  jge       end_sum_loop

		add		r14, [arr + r15 * 4]

  inc       r15
  jmp       top_sum_loop
  end_sum_loop:

	mov		rdi, fmt_print_largest
	mov		rsi, [arr]
	call	printf

	mov		rdi, fmt_print_smallest
	mov		rsi, [arr + 9 * 4]
	call	printf

	mov		rdi, fmt_print_sum
	mov		rsi, r14
	call	printf


  ; *********** CODE ENDS HERE ***********
  mov       rax, 0
  mov       rsp, rbp
  pop       rbp
  ret
