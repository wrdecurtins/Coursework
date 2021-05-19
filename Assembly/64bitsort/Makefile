NAME=64bitsort

all: 64bitsort

clean:
	rm -rf 64bitsort 64bitsort.o

64bitsort: 64bitsort.asm
	nasm -f elf64 -F dwarf -g 64bitsort.asm
	gcc -g -m64 -o 64bitsort 64bitsort.o -static
