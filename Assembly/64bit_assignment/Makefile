NAME=64bit_assignment

all: 64bit_assignment

clean:
	rm -rf 64bit_assignment 64bit_assignment.o

64bit_assignment: 64bit_assignment.asm
	nasm -f elf64 -F dwarf -g 64bit_assignment.asm
	gcc -g -m64 -o 64bit_assignment 64bit_assignment.o -static
