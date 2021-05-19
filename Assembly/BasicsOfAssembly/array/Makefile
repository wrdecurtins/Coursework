NAME=array

all: array

clean:
	rm -rf array array.o

array: array.asm
	nasm -f elf -F dwarf -g array.asm
	gcc -g -m32 -o array array.o /usr/local/share/csc314/driver.c /usr/local/share/csc314/asm_io.o
