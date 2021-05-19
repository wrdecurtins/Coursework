%include "/usr/local/share/csc314/asm_io.inc"

; the file that stores the initial state
%define BOARD_FILE 'board.txt'
%define GAMEOVER_FILE 'lose.txt'

; how to represent everything
%define WALL_CHAR '#'
%define PLAYER_CHAR 'O'

; the size of the game screen in characters
%define HEIGHT 21
%define WIDTH 43

; the player starting position.
; top left is considered (0,0)
%define STARTX 21
%define STARTY 9

;These define the playerstate values R/P/S
%define ROCKSTATE 1
%define PAPERSTATE 2
%define SCISSORSTATE 3

;These define how many points the player gets for these actions
%define KILLSCORE 20
%define ITEMSCORE 20
%define INPUTSCORE 5

;These define how often enemies spawn and when they do in a cycle
%define ROCKSPAWNMODULUS 20
%define PAPERSPAWNMODULUS 40
%define SCISSORSPAWNMODULUS 60

;This defines the fastest enemies can spawn (lower is faster)
%define SPAWNRATEMAX 61

;This defines the starting spawn rate of enemies (higher is slower)
%define SPAWNRATESTART 180

;This defines how quickly the spawn rate increases (higher is faster)
%define SPAWNINCREASERATE 10

; these keys do things
%define EXITCHAR 'x'
%define UPCHAR 'w'
%define LEFTCHAR 'a'
%define DOWNCHAR 's'
%define RIGHTCHAR 'd'
%define ROCKCHAR 'j'
%define PAPERCHAR 'k'
%define SCISSORCHAR 'l'

;enemy character values
%define ENEMYROCKCHAR 'R'
%define ENEMYPAPERCHAR 'P'
%define ENEMYSCISSORCHAR 'S'

segment .data

	; used to fopen() the board file defined above
	board_file			db BOARD_FILE,0
	gameover_file		db GAMEOVER_FILE,0

	; used to change the terminal mode
	mode_r				db "r",0
	raw_mode_on_cmd		db "stty raw -echo",0
	raw_mode_off_cmd	db "stty -raw echo",0

	; called by system() to clear/refresh the screen
	clear_screen_cmd	db "clear",0

	; things the program will print
	help_str			db 13,10,"Controls: ", \
							UPCHAR,"=UP / ", \
							LEFTCHAR,"=LEFT / ", \
							DOWNCHAR,"=DOWN / ", \
							RIGHTCHAR,"=RIGHT / ", \
							EXITCHAR,"=EXIT", \
							13,10,0

	help_str2			db 13,10,"Change into: ", \
							ROCKCHAR, "=ROCK / ", \
							PAPERCHAR, "=PAPER / ", \
							SCISSORCHAR, "=SCISSORS /", \
							13,10,0

	current_score_str	db 13,10,"Current Score: %d ", \
							"Current State = %s " , \
							13,10,10,0
;							"game_over_flag: %d ", \
;							"Pseudo-time: %d ", \
;							"mod: %d ", \
;							"spawn rate: %d ", \


	; state strings for help bar
	rock_str			db	"ROCK",0
	paper_str			db	"PAPER",0
	scissor_str			db	"SCISSORS",0


segment .bss

	; this array stores the current rendered gameboard (HxW)
	board	resb	(HEIGHT * WIDTH)

	; these variables store the current player position
	xpos	resd	1
	ypos	resd	1

	; this variable stores the players current state R/P/S
	player_state	resd	1

	; this variable stores the players score
	player_score	resd	1

	; this variable will store the amount of render cycles, this will be used to help determine spawn times
	pseudo_time		resd	1

	; this variable controlls the spawn rate of enemies
	spawn_rate		resd	1

	; this flag is for if an enemy collides with the player and they lose the collision
	game_over_flag	resd	1

	; these are debuggers
	mod				resd    1

segment .text

	global	asm_main
	global  raw_mode_on
	global  raw_mode_off
	global  init_board
	global  render

	extern	system
	extern	putchar
	extern	getchar
	extern	printf
	extern	fopen
	extern	fread
	extern	fgetc
	extern	fclose

asm_main:
	enter	0,0
	pusha
	;***************CODE STARTS HERE***************************

	; These two lines give the player a starting state and initialize the score to zero
	mov		DWORD[player_state], ROCKSTATE
	mov		DWORD[player_score], 0
	mov		DWORD[spawn_rate], SPAWNRATESTART
	mov		DWORD[game_over_flag], 0

	; put the terminal in raw mode so the game works nicely
	call	raw_mode_on

	; read the game board file into the global variable
	call	init_board

	; set the player at the proper start position
	mov		DWORD [xpos], STARTX
	mov		DWORD [ypos], STARTY

	; the game happens in this loop
	; the steps are...
	;   1. render (draw) the current board
	;   2. get a character from the user
	;	3. store current xpos,ypos in esi,edi
	;	4. update xpos,ypos based on character from user
	;	5. check what's in the buffer (board) at new xpos,ypos
	;	6. if it's a wall, reset xpos,ypos to saved esi,edi
	;	7. otherwise, just continue! (xpos,ypos are ok)
	game_loop:

		; draw the game board
		call	render

		; get an action from the user
		call	getchar

		; enemy turn

		; store the current position
		; we will test if the new position is legal
		; if not, we will restore these
		mov		esi, [xpos]
		mov		edi, [ypos]

		; choose what to do
		cmp		eax, EXITCHAR
		je		game_loop_end
		cmp		eax, UPCHAR
		je 		move_up
		cmp		eax, LEFTCHAR
		je		move_left
		cmp		eax, DOWNCHAR
		je		move_down
		cmp		eax, RIGHTCHAR
		je		move_right

		cmp		eax, ROCKCHAR
		je		make_rock
		cmp		eax, PAPERCHAR
		je		make_paper
		cmp		eax, SCISSORCHAR
		je		make_scissor

		jmp		input_end			; or just do nothing

		; move the player according to the input character
		move_up:
			dec		DWORD [ypos]
			jmp		input_end
		move_left:
			dec		DWORD [xpos]
			jmp		input_end
		move_down:
			inc		DWORD [ypos]
			jmp		input_end
		move_right:
			inc		DWORD [xpos]
			jmp		input_end

		make_rock:
			mov		DWORD [player_state], ROCKSTATE
			jmp		input_end
		make_paper:
			mov		DWORD [player_state], PAPERSTATE
			jmp		input_end
		make_scissor:
			mov		DWORD [player_state], SCISSORSTATE
			jmp		input_end


		input_end:

		; (W * y) + x = pos

		; compare the current position to the wall character
		mov		eax, WIDTH
		mul		DWORD [ypos]
		add		eax, [xpos]
		lea		eax, [board + eax]

		;collison detection
		cmp		BYTE [eax], ENEMYROCKCHAR
		jne		paper_check
		cmp		DWORD [player_state], ROCKSTATE
		je		valid_move
		cmp		DWORD [player_state], PAPERSTATE
		je		kill_enemy
		cmp		DWORD [player_state], SCISSORSTATE
		je		game_loop_end

		paper_check:
		cmp		BYTE [eax], ENEMYPAPERCHAR
		jne		scissor_check
		cmp		DWORD [player_state], ROCKSTATE
		je		game_loop_end
		cmp		DWORD [player_state], PAPERSTATE
		je		valid_move
		cmp		DWORD [player_state], SCISSORSTATE
		je		kill_enemy

		scissor_check:
		cmp		BYTE [eax], ENEMYSCISSORCHAR
		jne		wall_check
		cmp		DWORD [player_state], ROCKSTATE
		je		kill_enemy
		cmp		DWORD [player_state], PAPERSTATE
		je		game_loop_end
		cmp		DWORD [player_state], SCISSORSTATE
		je		valid_move


		wall_check:
		cmp		BYTE [eax], WALL_CHAR
		jne		valid_move
			; opps, that was an invalid move, reset
			mov		DWORD [xpos], esi
			mov		DWORD [ypos], edi
			jmp		valid_move

		kill_enemy:
		mov		eax, WIDTH
		mul		DWORD [ypos]
		add		eax, [xpos]

		mov		BYTE[board + eax], " "
		add		DWORD[player_score], KILLSCORE
		jmp		valid_move

		valid_move:

		call	enemy_behavior

		; (W * y) + x = pos

		; compare the current position to the wall character
		mov		eax, WIDTH
		mul		DWORD [ypos]
		add		eax, [xpos]
		lea		eax, [board + eax]

		;collison detection
		cmp		BYTE [eax], ENEMYROCKCHAR
		jne		paper_check2
		cmp		DWORD [player_state], ROCKSTATE
		je		valid_move2
		cmp		DWORD [player_state], PAPERSTATE
		je		kill_enemy2
		cmp		DWORD [player_state], SCISSORSTATE
		je		game_loop_end

		paper_check2:
		cmp		BYTE [eax], ENEMYPAPERCHAR
		jne		scissor_check2
		cmp		DWORD [player_state], ROCKSTATE
		je		game_loop_end
		cmp		DWORD [player_state], PAPERSTATE
		je		valid_move2
		cmp		DWORD [player_state], SCISSORSTATE
		je		kill_enemy2

		scissor_check2:
		cmp		BYTE [eax], ENEMYSCISSORCHAR
		jne		valid_move2
		cmp		DWORD [player_state], ROCKSTATE
		je		kill_enemy2
		cmp		DWORD [player_state], PAPERSTATE
		je		game_loop_end
		cmp		DWORD [player_state], SCISSORSTATE
		je		valid_move2


		kill_enemy2:
		mov		eax, WIDTH
		mul		DWORD [ypos]
		add		eax, [xpos]

		mov		BYTE[board + eax], " "
		add		DWORD[player_score], KILLSCORE
		jmp		valid_move2

		valid_move2:

		cmp		DWORD[game_over_flag], 1
		je		game_loop_end


	jmp		game_loop
	game_loop_end:

	; restore old terminal functionality
	call raw_mode_off

	call print_game_over
	call render

	;***************CODE ENDS HERE*****************************
	popa
	mov		eax, 0
	leave
	ret

; === FUNCTION ===
enemy_behavior:

	push	ebp
	mov		ebp, esp

	; outside loop by height
	; i.e. for(c=0; c<height; c++)
	mov		DWORD [ebp-4], 0
	y_enemy_loop_start:
	cmp		DWORD [ebp-4], HEIGHT
	je		y_enemy_loop_end

		; inside loop by width
		; i.e. for(c=0; c<width; c++)
		mov		DWORD [ebp-8], 0
		x_enemy_loop_start:
		cmp		DWORD [ebp-8], WIDTH
		je 		x_enemy_loop_end

			mov		eax, WIDTH
			mul		DWORD [ebp-4]
			add		eax, DWORD[ebp-8]
			lea		eax, [board + eax]
			lea		edx, [eax]

			mov		ebx, DWORD[player_state]

			cmp		BYTE[eax], ENEMYROCKCHAR
			jne		no_rock_ai

				cmp		ebx,ROCKSTATE
				je		no_behavior
				cmp		ebx,PAPERSTATE
				je		retreat_ai_rock
				jmp		attack_ai_rock

			no_rock_ai:
			cmp		BYTE[eax], ENEMYPAPERCHAR
			jne		no_paper_ai

				cmp		ebx, PAPERSTATE
				je		no_behavior
				cmp		ebx, SCISSORSTATE
				je		retreat_ai_paper
				jmp		attack_ai_paper

			no_paper_ai:
			cmp		BYTE[eax], ENEMYSCISSORCHAR
			jne		no_behavior

				cmp		ebx, SCISSORSTATE
				je		no_behavior
				cmp		ebx, ROCKSTATE
				je		retreat_ai_scissor
				jmp		attack_ai_scissor


			retreat_ai_rock:
			mov		eax, DWORD[ebp-4]
			cmp		eax, DWORD[ypos]
			jl		retreat_up_rock
			retreat_up_fail_rock:
			mov		eax, DWORD[ebp-8]
			cmp		eax, DWORD[xpos]
			jl		retreat_left_rock
			retreat_left_fail_rock:
			jmp		retreat_down_rock
			retreat_down_fail_rock:
			jmp		retreat_right_rock
			retreat_right_fail_rock:
			jmp		no_behavior

				retreat_up_rock:
				mov		eax, WIDTH
				mov		ebx, DWORD[ebp-4]
				dec		ebx
				mul		ebx
				add		eax, DWORD[ebp-8]

				cmp		BYTE[board + eax], WALL_CHAR
				je		retreat_up_fail_rock
				cmp		BYTE[board + eax], ENEMYROCKCHAR
				je		retreat_up_fail_rock
				cmp		BYTE[board + eax], ENEMYPAPERCHAR
				je		retreat_up_fail_rock

				mov		BYTE[board + eax], ENEMYROCKCHAR

				mov		eax, WIDTH
				mul		DWORD [ebp-4]
				add		eax, DWORD[ebp-8]
				mov		BYTE[board + eax], " "

				jmp		no_behavior

				retreat_left_rock:
				mov		eax, WIDTH
				mov		ebx, DWORD[ebp-8]
				dec		ebx
				mul		DWORD[ebp-4]
				add		eax, ebx

				cmp		BYTE[board + eax], WALL_CHAR
				je		retreat_left_fail_rock
				cmp		BYTE[board + eax], ENEMYROCKCHAR
				je		retreat_left_fail_rock
				cmp		BYTE[board + eax], ENEMYPAPERCHAR
				je		retreat_left_fail_rock

				mov		BYTE[board + eax], ENEMYROCKCHAR

				mov		eax, WIDTH
				mul		DWORD [ebp-4]
				add		eax, DWORD[ebp-8]
				mov		BYTE[board + eax], " "

				jmp		no_behavior


				retreat_down_rock:
				mov		eax, WIDTH
				mov		ebx, DWORD[ebp-4]
				inc		ebx
				mul		ebx
				add		eax, DWORD[ebp-8]

				cmp		BYTE[board + eax], WALL_CHAR
				je		retreat_down_fail_rock
				cmp		BYTE[board + eax], ENEMYROCKCHAR
				je		retreat_down_fail_rock
				cmp		BYTE[board + eax], ENEMYPAPERCHAR
				je		retreat_down_fail_rock

				mov		BYTE[board + eax], ENEMYROCKCHAR

				mov		eax, WIDTH
				mul		DWORD [ebp-4]
				add		eax, DWORD[ebp-8]
				mov		BYTE[board + eax], " "

				inc		DWORD [ebp-4]
				jmp		no_behavior

				retreat_right_rock:
				mov		eax, WIDTH
				mov		ebx, DWORD[ebp-8]
				inc		ebx
				mul		DWORD[ebp-4]
				add		eax, ebx

				cmp		BYTE[board + eax], WALL_CHAR
				je		retreat_right_fail_rock
				cmp		BYTE[board + eax], ENEMYROCKCHAR
				je		retreat_right_fail_rock
				cmp		BYTE[board + eax], ENEMYPAPERCHAR
				je		retreat_right_fail_rock

				mov		BYTE[board + eax], ENEMYROCKCHAR

				mov		eax, WIDTH
				mul		DWORD [ebp-4]
				add		eax, DWORD[ebp-8]
				mov		BYTE[board + eax], " "

				inc		DWORD [ebp-8]
				jmp		no_behavior


			attack_ai_rock:
			mov		eax, DWORD[ebp-4]
			cmp		eax, DWORD[ypos]
			jg		attack_up_rock
			attack_up_fail_rock:
			mov		eax, DWORD[ebp-8]
			cmp		eax, DWORD[xpos]
			jg		attack_left_rock
			attack_left_fail_rock:
			mov		edx, 0
			mov		eax, DWORD[pseudo_time]
			mov		ebx, 2
			div		ebx
			cmp		edx, 0
			je		attack_right_rock
			attack_right_fail_rock:
			jmp		attack_down_rock
			attack_down_fail_rock:
			jmp		no_behavior

				attack_up_rock:
				mov		eax, WIDTH
				mov		ebx, DWORD[ebp-4]
				dec		ebx
				mul		ebx
				add		eax, DWORD[ebp-8]

				cmp		BYTE[board + eax], WALL_CHAR
				je		attack_up_fail_rock
				cmp		BYTE[board + eax], ENEMYROCKCHAR
				je		attack_up_fail_rock
				cmp		BYTE[board + eax], ENEMYPAPERCHAR
				je		attack_up_fail_rock
				cmp		BYTE[board + eax], " "
				je		no_collision_rock_attack_up
				mov		DWORD[game_over_flag], 1

				no_collision_rock_attack_up:

				mov		BYTE[board + eax], ENEMYROCKCHAR

				mov		eax, WIDTH
				mul		DWORD [ebp-4]
				add		eax, DWORD[ebp-8]
				mov		BYTE[board + eax], " "

				jmp		no_behavior

				attack_left_rock:
				mov		eax, WIDTH
				mov		ebx, DWORD[ebp-8]
				dec		ebx
				mul		DWORD[ebp-4]
				add		eax, ebx

				cmp		BYTE[board + eax], WALL_CHAR
				je		attack_left_fail_rock
				cmp		BYTE[board + eax], ENEMYROCKCHAR
				je		attack_left_fail_rock
				cmp		BYTE[board + eax], ENEMYPAPERCHAR
				je		attack_left_fail_rock
				cmp		BYTE[board + eax], " "
				je		no_collision_rock_attack_left
				mov		DWORD[game_over_flag], 1

				no_collision_rock_attack_left:

				mov		BYTE[board + eax], ENEMYROCKCHAR

				mov		eax, WIDTH
				mul		DWORD [ebp-4]
				add		eax, DWORD[ebp-8]
				mov		BYTE[board + eax], " "

				jmp		no_behavior


				attack_down_rock:
				mov		eax, WIDTH
				mov		ebx, DWORD[ebp-4]
				inc		ebx
				mul		ebx
				add		eax, DWORD[ebp-8]

				cmp		BYTE[board + eax], WALL_CHAR
				je		attack_down_fail_rock
				cmp		BYTE[board + eax], ENEMYROCKCHAR
				je		attack_down_fail_rock
				cmp		BYTE[board + eax], ENEMYPAPERCHAR
				je		attack_down_fail_rock
				cmp		BYTE[board + eax], " "
				je		no_collision_rock_attack_down
				mov		DWORD[game_over_flag], 1

				no_collision_rock_attack_down:

				mov		BYTE[board + eax], ENEMYROCKCHAR

				mov		eax, WIDTH
				mul		DWORD [ebp-4]
				add		eax, DWORD[ebp-8]
				mov		BYTE[board + eax], " "

				inc		DWORD [ebp-4]
				jmp		no_behavior

				attack_right_rock:
				mov		eax, WIDTH
				mov		ebx, DWORD[ebp-8]
				inc		ebx
				mul		DWORD[ebp-4]
				add		eax, ebx

				cmp		BYTE[board + eax], WALL_CHAR
				je		attack_right_fail_rock
				cmp		BYTE[board + eax], ENEMYROCKCHAR
				je		attack_right_fail_rock
				cmp		BYTE[board + eax], ENEMYPAPERCHAR
				je		attack_right_fail_rock
				cmp		BYTE[board + eax], " "
				je		no_collision_rock_attack_right
				mov		DWORD[game_over_flag], 1

				no_collision_rock_attack_right:

				mov		BYTE[board + eax], ENEMYROCKCHAR

				mov		eax, WIDTH
				mul		DWORD [ebp-4]
				add		eax, DWORD[ebp-8]
				mov		BYTE[board + eax], " "

				inc		DWORD [ebp-8]
				jmp		no_behavior



                        retreat_ai_paper:
                        mov             eax, DWORD[ebp-4]
                        cmp             eax, DWORD[ypos]
                        jl              retreat_up_paper
                        retreat_up_fail_paper:
                        mov             eax, DWORD[ebp-8]
                        cmp             eax, DWORD[xpos]
                        jl              retreat_left_paper
                        retreat_left_fail_paper:
                        jmp             retreat_down_paper
                        retreat_down_fail_paper:
                        jmp             retreat_right_paper
                        retreat_right_fail_paper:
                        jmp             no_behavior

                                retreat_up_paper:
                                mov             eax, WIDTH
                                mov             ebx, DWORD[ebp-4]
                                dec             ebx
                                mul             ebx
                                add             eax, DWORD[ebp-8]

                                cmp             BYTE[board + eax], WALL_CHAR
                                je              retreat_up_fail_paper
                                cmp             BYTE[board + eax], ENEMYPAPERCHAR
                                je              retreat_up_fail_paper
                                cmp             BYTE[board + eax], ENEMYSCISSORCHAR
                                je              retreat_up_fail_paper

                                mov             BYTE[board + eax], ENEMYPAPERCHAR

                                mov             eax, WIDTH
                                mul             DWORD [ebp-4]
                                add             eax, DWORD[ebp-8]
                                mov             BYTE[board + eax], " "

                                jmp             no_behavior

                                retreat_left_paper:
                                mov             eax, WIDTH
                                mov             ebx, DWORD[ebp-8]
                                dec             ebx
                                mul             DWORD[ebp-4]
                                add             eax, ebx

                                cmp             BYTE[board + eax], WALL_CHAR
                                je              retreat_left_fail_paper
                                cmp             BYTE[board + eax], ENEMYPAPERCHAR
                                je              retreat_left_fail_paper
                                cmp             BYTE[board + eax], ENEMYSCISSORCHAR
                                je              retreat_left_fail_paper

                                mov             BYTE[board + eax], ENEMYPAPERCHAR

                                mov             eax, WIDTH
                                mul             DWORD [ebp-4]
                                add             eax, DWORD[ebp-8]
                                mov             BYTE[board + eax], " "

                                jmp             no_behavior


                                retreat_down_paper:
                                mov             eax, WIDTH
                                mov             ebx, DWORD[ebp-4]
                                inc             ebx
                                mul             ebx
                                add             eax, DWORD[ebp-8]

                                cmp             BYTE[board + eax], WALL_CHAR
                                je              retreat_down_fail_paper
                                cmp             BYTE[board + eax], ENEMYPAPERCHAR
                                je              retreat_down_fail_paper
                                cmp             BYTE[board + eax], ENEMYSCISSORCHAR
                                je              retreat_down_fail_paper

                                mov             BYTE[board + eax], ENEMYPAPERCHAR

                                mov             eax, WIDTH
                                mul             DWORD [ebp-4]
                                add             eax, DWORD[ebp-8]
                                mov             BYTE[board + eax], " "

                                inc             DWORD [ebp-4]
                                jmp             no_behavior

                                retreat_right_paper:
                                mov             eax, WIDTH
                                mov             ebx, DWORD[ebp-8]
                                inc             ebx
                                mul             DWORD[ebp-4]
                                add             eax, ebx

                                cmp             BYTE[board + eax], WALL_CHAR
                                je              retreat_right_fail_paper
                                cmp             BYTE[board + eax], ENEMYPAPERCHAR
                                je              retreat_right_fail_paper
                                cmp             BYTE[board + eax], ENEMYSCISSORCHAR
                                je              retreat_right_fail_paper

                                mov             BYTE[board + eax], ENEMYPAPERCHAR

                                mov             eax, WIDTH
                                mul             DWORD [ebp-4]
                                add             eax, DWORD[ebp-8]
                                mov             BYTE[board + eax], " "

                                inc             DWORD [ebp-8]
                                jmp             no_behavior


                        attack_ai_paper:
                        mov             eax, DWORD[ebp-4]
                        cmp             eax, DWORD[ypos]
                        jg              attack_up_paper
                        attack_up_fail_paper:
                        mov             eax, DWORD[ebp-8]
                        cmp             eax, DWORD[xpos]
                        jg              attack_left_paper
                        attack_left_fail_paper:
                        mov             edx, 0
                        mov             eax, DWORD[pseudo_time]
                        mov             ebx, 2
                        div             ebx
                        cmp             edx, 0
                        je              attack_right_paper
                        attack_right_fail_paper:
                        jmp             attack_down_paper
                        attack_down_fail_paper:
                        jmp             no_behavior

                                attack_up_paper:
                                mov             eax, WIDTH
                                mov             ebx, DWORD[ebp-4]
                                dec             ebx
                                mul             ebx
                                add             eax, DWORD[ebp-8]

                                cmp             BYTE[board + eax], WALL_CHAR
                                je              attack_up_fail_paper
                                cmp             BYTE[board + eax], ENEMYPAPERCHAR
                                je              attack_up_fail_paper
                                cmp             BYTE[board + eax], ENEMYSCISSORCHAR
                                je              attack_up_fail_paper
                                cmp             BYTE[board + eax], PLAYER_CHAR
                                jne             no_collision_paper_attack_up
                                mov             DWORD[game_over_flag], 1

                                no_collision_paper_attack_up:

                                mov             BYTE[board + eax], ENEMYPAPERCHAR

                                mov             eax, WIDTH
                                mul             DWORD [ebp-4]
                                add             eax, DWORD[ebp-8]
                                mov             BYTE[board + eax], " "

                                jmp             no_behavior

                                attack_left_paper:
                                mov             eax, WIDTH
                                mov             ebx, DWORD[ebp-8]
                                dec             ebx
                                mul             DWORD[ebp-4]
                                add             eax, ebx

                                cmp             BYTE[board + eax], WALL_CHAR
                                je              attack_left_fail_paper
                                cmp             BYTE[board + eax], ENEMYPAPERCHAR
                                je              attack_left_fail_paper
                                cmp             BYTE[board + eax], ENEMYSCISSORCHAR
                                je              attack_left_fail_paper
                                cmp             BYTE[board + eax], PLAYER_CHAR
                                jne             no_collision_paper_attack_left
                                mov             DWORD[game_over_flag], 1

                                no_collision_paper_attack_left:

                                mov             BYTE[board + eax], ENEMYPAPERCHAR

                                mov             eax, WIDTH
                                mul             DWORD [ebp-4]
                                add             eax, DWORD[ebp-8]
                                mov             BYTE[board + eax], " "

                                jmp             no_behavior


                                attack_down_paper:
                                mov             eax, WIDTH
                                mov             ebx, DWORD[ebp-4]
                                inc             ebx
                                mul             ebx
                                add             eax, DWORD[ebp-8]

                                cmp             BYTE[board + eax], WALL_CHAR
                                je              attack_down_fail_paper
                                cmp             BYTE[board + eax], ENEMYPAPERCHAR
                                je              attack_down_fail_paper
                                cmp             BYTE[board + eax], ENEMYSCISSORCHAR
                                je              attack_down_fail_paper
                                cmp             BYTE[board + eax], PLAYER_CHAR
                                jne             no_collision_paper_attack_down
                                mov             DWORD[game_over_flag], 1

                                no_collision_paper_attack_down:

                                mov             BYTE[board + eax], ENEMYPAPERCHAR

                                mov             eax, WIDTH
                                mul             DWORD [ebp-4]
                                add             eax, DWORD[ebp-8]
                                mov             BYTE[board + eax], " "

                                inc             DWORD [ebp-4]
                                jmp             no_behavior

                                attack_right_paper:
                                mov             eax, WIDTH
                                mov             ebx, DWORD[ebp-8]
                                inc             ebx
                                mul             DWORD[ebp-4]
                                add             eax, ebx

                                cmp             BYTE[board + eax], WALL_CHAR
                                je              attack_right_fail_paper
                                cmp             BYTE[board + eax], ENEMYPAPERCHAR
                                je              attack_right_fail_paper
                                cmp             BYTE[board + eax], ENEMYSCISSORCHAR
                                je              attack_right_fail_paper
                                cmp             BYTE[board + eax], PLAYER_CHAR
                                jne             no_collision_paper_attack_right
                                mov             DWORD[game_over_flag], 1

                                no_collision_paper_attack_right:

                                mov             BYTE[board + eax], ENEMYPAPERCHAR

                                mov             eax, WIDTH
                                mul             DWORD [ebp-4]
                                add             eax, DWORD[ebp-8]
                                mov             BYTE[board + eax], " "

                                inc             DWORD [ebp-8]
                                jmp             no_behavior






                        retreat_ai_scissor:
                        mov             eax, DWORD[ebp-4]
                        cmp             eax, DWORD[ypos]
                        jl              retreat_up_scissor
                        retreat_up_fail_scissor:
                        mov             eax, DWORD[ebp-8]
                        cmp             eax, DWORD[xpos]
                        jl              retreat_left_scissor
                        retreat_left_fail_scissor:
                        jmp             retreat_down_scissor
                        retreat_down_fail_scissor:
                        jmp             retreat_right_scissor
                        retreat_right_fail_scissor:
                        jmp             no_behavior

                                retreat_up_scissor:
                                mov             eax, WIDTH
                                mov             ebx, DWORD[ebp-4]
                                dec             ebx
                                mul             ebx
                                add             eax, DWORD[ebp-8]

                                cmp             BYTE[board + eax], WALL_CHAR
                                je              retreat_up_fail_scissor
                                cmp             BYTE[board + eax], ENEMYSCISSORCHAR
                                je              retreat_up_fail_scissor
                                cmp             BYTE[board + eax], ENEMYROCKCHAR
                                je              retreat_up_fail_scissor

                                mov             BYTE[board + eax], ENEMYSCISSORCHAR

                                mov             eax, WIDTH
                                mul             DWORD [ebp-4]
                                add             eax, DWORD[ebp-8]
                                mov             BYTE[board + eax], " "

                                jmp             no_behavior

                                retreat_left_scissor:
                                mov             eax, WIDTH
                                mov             ebx, DWORD[ebp-8]
                                dec             ebx
                                mul             DWORD[ebp-4]
                                add             eax, ebx

                                cmp             BYTE[board + eax], WALL_CHAR
                                je              retreat_left_fail_scissor
                                cmp             BYTE[board + eax], ENEMYSCISSORCHAR
                                je              retreat_left_fail_scissor
                                cmp             BYTE[board + eax], ENEMYROCKCHAR
                                je              retreat_left_fail_scissor

                                mov             BYTE[board + eax], ENEMYSCISSORCHAR

                                mov             eax, WIDTH
                                mul             DWORD [ebp-4]
                                add             eax, DWORD[ebp-8]
                                mov             BYTE[board + eax], " "

                                jmp             no_behavior


                                retreat_down_scissor:
                                mov             eax, WIDTH
                                mov             ebx, DWORD[ebp-4]
                                inc             ebx
                                mul             ebx
                                add             eax, DWORD[ebp-8]

                                cmp             BYTE[board + eax], WALL_CHAR
                                je              retreat_down_fail_scissor
                                cmp             BYTE[board + eax], ENEMYSCISSORCHAR
                                je              retreat_down_fail_scissor
                                cmp             BYTE[board + eax], ENEMYSCISSORCHAR
                                je              retreat_down_fail_scissor

                                mov             BYTE[board + eax], ENEMYSCISSORCHAR

                                mov             eax, WIDTH
                                mul             DWORD [ebp-4]
                                add             eax, DWORD[ebp-8]
                                mov             BYTE[board + eax], " "

                                inc             DWORD [ebp-4]
                                jmp             no_behavior

                                retreat_right_scissor:
                                mov             eax, WIDTH
                                mov             ebx, DWORD[ebp-8]
                                inc             ebx
                                mul             DWORD[ebp-4]
                                add             eax, ebx

                                cmp             BYTE[board + eax], WALL_CHAR
                                je              retreat_right_fail_scissor
                                cmp             BYTE[board + eax], ENEMYSCISSORCHAR
                                je              retreat_right_fail_scissor
                                cmp             BYTE[board + eax], ENEMYROCKCHAR
                                je              retreat_right_fail_scissor

                                mov             BYTE[board + eax], ENEMYSCISSORCHAR

                                mov             eax, WIDTH
                                mul             DWORD [ebp-4]
                                add             eax, DWORD[ebp-8]
                                mov             BYTE[board + eax], " "

                                inc             DWORD [ebp-8]
                                jmp             no_behavior


                        attack_ai_scissor:
                        mov             eax, DWORD[ebp-4]
                        cmp             eax, DWORD[ypos]
                        jg              attack_up_scissor
                        attack_up_fail_scissor:
                        mov             eax, DWORD[ebp-8]
                        cmp             eax, DWORD[xpos]
                        jg              attack_left_scissor
                        attack_left_fail_scissor:
                        mov             edx, 0
                        mov             eax, DWORD[pseudo_time]
                        mov             ebx, 2
                        div             ebx
                        cmp             edx, 0
                        je              attack_right_scissor
                        attack_right_fail_scissor:
                        jmp             attack_down_scissor
                        attack_down_fail_scissor:
                        jmp             no_behavior

                                attack_up_scissor:
                                mov             eax, WIDTH
                                mov             ebx, DWORD[ebp-4]
                                dec             ebx
                                mul             ebx
                                add             eax, DWORD[ebp-8]

                                cmp             BYTE[board + eax], WALL_CHAR
                                je              attack_up_fail_scissor
                                cmp             BYTE[board + eax], ENEMYSCISSORCHAR
                                je              attack_up_fail_scissor
                                cmp             BYTE[board + eax], ENEMYROCKCHAR
                                je              attack_up_fail_scissor
                                cmp             BYTE[board + eax], PLAYER_CHAR
                                jne             no_collision_scissor_attack_up
                                mov             DWORD[game_over_flag], 1

                                no_collision_scissor_attack_up:

                                mov             BYTE[board + eax], ENEMYSCISSORCHAR

                                mov             eax, WIDTH
                                mul             DWORD [ebp-4]
                                add             eax, DWORD[ebp-8]
                                mov             BYTE[board + eax], " "

                                jmp             no_behavior

                                attack_left_scissor:
                                mov             eax, WIDTH
                                mov             ebx, DWORD[ebp-8]
                                dec             ebx
                                mul             DWORD[ebp-4]
                                add             eax, ebx

                                cmp             BYTE[board + eax], WALL_CHAR
                                je              attack_left_fail_scissor
                                cmp             BYTE[board + eax], ENEMYSCISSORCHAR
                                je              attack_left_fail_scissor
                                cmp             BYTE[board + eax], ENEMYROCKCHAR
                                je              attack_left_fail_scissor
                                cmp             BYTE[board + eax], PLAYER_CHAR
                                jne             no_collision_scissor_attack_left
                                mov             DWORD[game_over_flag], 1

                                no_collision_scissor_attack_left:

                                mov             BYTE[board + eax], ENEMYSCISSORCHAR

                                mov             eax, WIDTH
                                mul             DWORD [ebp-4]
                                add             eax, DWORD[ebp-8]
                                mov             BYTE[board + eax], " "

                                jmp             no_behavior


                                attack_down_scissor:
                                mov             eax, WIDTH
                                mov             ebx, DWORD[ebp-4]
                                inc             ebx
                                mul             ebx
                                add             eax, DWORD[ebp-8]

                                cmp             BYTE[board + eax], WALL_CHAR
                                je              attack_down_fail_scissor
                                cmp             BYTE[board + eax], ENEMYSCISSORCHAR
                                je              attack_down_fail_scissor
                                cmp             BYTE[board + eax], ENEMYROCKCHAR
                                je              attack_down_fail_scissor
                                cmp             BYTE[board + eax], PLAYER_CHAR
                                jne             no_collision_scissor_attack_down
                                mov             DWORD[game_over_flag], 1

                                no_collision_scissor_attack_down:

                                mov             BYTE[board + eax], ENEMYSCISSORCHAR

                                mov             eax, WIDTH
                                mul             DWORD [ebp-4]
                                add             eax, DWORD[ebp-8]
                                mov             BYTE[board + eax], " "

                                inc             DWORD [ebp-4]
                                jmp             no_behavior

                                attack_right_scissor:
                                mov             eax, WIDTH
                                mov             ebx, DWORD[ebp-8]
                                inc             ebx
                                mul             DWORD[ebp-4]
                                add             eax, ebx

                                cmp             BYTE[board + eax], WALL_CHAR
                                je              attack_right_fail_scissor
                                cmp             BYTE[board + eax], ENEMYSCISSORCHAR
                                je              attack_right_fail_scissor
                                cmp             BYTE[board + eax], ENEMYROCKCHAR
                                je              attack_right_fail_scissor
                                cmp             BYTE[board + eax], PLAYER_CHAR
                                jne             no_collision_scissor_attack_right
                                mov             DWORD[game_over_flag], 1

                                no_collision_scissor_attack_right:

                                mov             BYTE[board + eax], ENEMYSCISSORCHAR

                                mov             eax, WIDTH
                                mul             DWORD [ebp-4]
                                add             eax, DWORD[ebp-8]
                                mov             BYTE[board + eax], " "

                                inc             DWORD [ebp-8]
                                jmp             no_behavior


			no_behavior:

		inc		DWORD [ebp-8]
		jmp		x_enemy_loop_start
		x_enemy_loop_end:


	inc		DWORD [ebp-4]
	jmp		y_enemy_loop_start
	y_enemy_loop_end:





	mov		esp, ebp
	pop		ebp
	ret



; === FUNCTION ===
spawncheck:

	push	ebp
	mov		ebp, esp

	cmp		DWORD[spawn_rate], SPAWNRATEMAX
	jge		not_max
	mov		DWORD[spawn_rate], SPAWNRATEMAX

	not_max:

	mov		edx, 0
	mov		eax, DWORD[pseudo_time]
	mov		ebx, DWORD[spawn_rate]
	div		ebx

	mov		DWORD[mod], edx

	; (W * y) + x = pos

;	mov		eax, WIDTH
;	mul		DWORD [ypos]
;	add		eax, [xpos]
;	lea		eax, [board + eax]


	cmp		edx, ROCKSPAWNMODULUS
	jne		no_rock_spawn
	mov		BYTE[board + WIDTH * 2 + 8], ENEMYROCKCHAR
	mov		BYTE[board + WIDTH * 5 + 3], ENEMYROCKCHAR
	mov		BYTE[board + WIDTH * 5 + 39], ENEMYROCKCHAR
	mov		BYTE[board + WIDTH * 18 + 8], ENEMYROCKCHAR
	sub		DWORD[spawn_rate], SPAWNINCREASERATE
	no_rock_spawn:

	cmp		edx, PAPERSPAWNMODULUS
	jne		no_paper_spawn
	mov		BYTE[board + WIDTH * 2 + 21], ENEMYPAPERCHAR
	mov		BYTE[board + WIDTH * 10 + 3], ENEMYPAPERCHAR
	mov		BYTE[board + WIDTH * 10 + 39], ENEMYPAPERCHAR
	mov		BYTE[board + WIDTH * 18 + 21], ENEMYPAPERCHAR
	sub		DWORD[spawn_rate], SPAWNINCREASERATE
	no_paper_spawn:

	cmp		edx, SCISSORSPAWNMODULUS
	jne		no_scissor_spawn
	mov		BYTE[board + WIDTH * 2 + 34], ENEMYSCISSORCHAR
	mov		BYTE[board + WIDTH * 15 + 3], ENEMYSCISSORCHAR
	mov		BYTE[board + WIDTH * 15 + 39], ENEMYSCISSORCHAR
	mov		BYTE[board + WIDTH * 18 + 34], ENEMYSCISSORCHAR
	sub		DWORD[spawn_rate], SPAWNINCREASERATE
	no_scissor_spawn:



	mov		esp, ebp
	pop		ebp
	ret




; === FUNCTION ===
print_game_over:

        push    ebp
        mov     ebp, esp

        ; FILE* and loop counter
        ; ebp-4, ebp-8
        sub             esp, 8

        ; open the file
        push    mode_r
        push    gameover_file
        call    fopen
        add     esp, 8
        mov     DWORD [ebp-4], eax

        ; read the file data into the global buffer
        ; line-by-line so we can ignore the newline characters
        mov             DWORD [ebp-8], 0
        go_read_loop:
        cmp             DWORD [ebp-8], HEIGHT
        je              go_read_loop_end

                ; find the offset (WIDTH * counter)
                mov             eax, WIDTH
                mul             DWORD [ebp-8]
                lea             ebx, [board + eax]

                ; read the bytes into the buffer
                push    DWORD [ebp-4]
                push    WIDTH
                push    1
                push    ebx
                call    fread
                add             esp, 16

                ; slurp up the newline
                push    DWORD [ebp-4]
                call    fgetc
                add             esp, 4

        inc             DWORD [ebp-8]
        jmp             go_read_loop
        go_read_loop_end:

        ; close the open file handle
        push    DWORD [ebp-4]
        call    fclose
        add             esp, 4

        mov             esp, ebp
        pop             ebp
        ret


; === FUNCTION ===
raw_mode_on:

	push	ebp
	mov		ebp, esp

	push	raw_mode_on_cmd
	call	system
	add		esp, 4

	mov		esp, ebp
	pop		ebp
	ret

; === FUNCTION ===
raw_mode_off:

	push	ebp
	mov		ebp, esp

	push	raw_mode_off_cmd
	call	system
	add		esp, 4

	mov		esp, ebp
	pop		ebp
	ret

; === FUNCTION ===
init_board:

	push	ebp
	mov		ebp, esp

	; FILE* and loop counter
	; ebp-4, ebp-8
	sub		esp, 8

	; open the file
	push	mode_r
	push	board_file
	call	fopen
	add		esp, 8
	mov		DWORD [ebp-4], eax

	; read the file data into the global buffer
	; line-by-line so we can ignore the newline characters
	mov		DWORD [ebp-8], 0
	read_loop:
	cmp		DWORD [ebp-8], HEIGHT
	je		read_loop_end

		; find the offset (WIDTH * counter)
		mov		eax, WIDTH
		mul		DWORD [ebp-8]
		lea		ebx, [board + eax]

		; read the bytes into the buffer
		push	DWORD [ebp-4]
		push	WIDTH
		push	1
		push	ebx
		call	fread
		add		esp, 16

		; slurp up the newline
		push	DWORD [ebp-4]
		call	fgetc
		add		esp, 4

	inc		DWORD [ebp-8]
	jmp		read_loop
	read_loop_end:

	; close the open file handle
	push	DWORD [ebp-4]
	call	fclose
	add		esp, 4

	mov		esp, ebp
	pop		ebp
	ret

; === FUNCTION ===
render:

	push	ebp
	mov		ebp, esp

	; two ints, for two loop counters
	; ebp-4, ebp-8
	sub		esp, 8

	inc		DWORD[pseudo_time]

	call	spawncheck

	; clear the screen
	push	clear_screen_cmd
	call	system
	add		esp, 4

	; print the help information
	push	help_str
	call	printf
	add		esp, 4

	push	help_str2
	call	printf
	add		esp, 4

;	push	DWORD[game_over_flag]

	; print the second help string
	mov		eax, DWORD[player_state]
	cmp		eax, ROCKSTATE
	je		rockhelpstr
	cmp		eax, PAPERSTATE
	je		paperhelpstr
	cmp		eax, SCISSORSTATE
	je		scissorhelpstr

	rockhelpstr:
	push	rock_str
	jmp		continuehelpstr2
	paperhelpstr:
	push	paper_str
	jmp		continuehelpstr2
	scissorhelpstr:
	push	scissor_str
	jmp		continuehelpstr2

	continuehelpstr2:

	; print the score string
;	push    DWORD[spawn_rate]
;	push	DWORD[mod]
;	push	DWORD[pseudo_time]
	push	DWORD[player_score]
	push	current_score_str
	call	printf
	add		esp, 8

	; outside loop by height
	; i.e. for(c=0; c<height; c++)
	mov		DWORD [ebp-4], 0
	y_loop_start:
	cmp		DWORD [ebp-4], HEIGHT
	je		y_loop_end

		; inside loop by width
		; i.e. for(c=0; c<width; c++)
		mov		DWORD [ebp-8], 0
		x_loop_start:
		cmp		DWORD [ebp-8], WIDTH
		je 		x_loop_end

			; check if (xpos,ypos)=(x,y)
			mov		eax, [xpos]
			cmp		eax, DWORD [ebp-8]
			jne		print_board
			mov		eax, [ypos]
			cmp		eax, DWORD [ebp-4]
			jne		print_board
				; if both were equal, print the player
				push	PLAYER_CHAR
				jmp		print_end
			print_board:
				; otherwise print whatever's in the buffer
				mov		eax, [ebp-4]
				mov		ebx, WIDTH
				mul		ebx
				add		eax, [ebp-8]
				mov		ebx, 0
				mov		bl, BYTE [board + eax]
				push	ebx
			print_end:
			call	putchar
			add		esp, 4

		inc		DWORD [ebp-8]
		jmp		x_loop_start
		x_loop_end:

		; write a carriage return (necessary when in raw mode)
		push	0x0d
		call 	putchar
		add		esp, 4

		; write a newline
		push	0x0a
		call	putchar
		add		esp, 4

	inc		DWORD [ebp-4]
	jmp		y_loop_start
	y_loop_end:

	mov		esp, ebp
	pop		ebp
	ret
