NAME=if

all: if

clean:
	rm -rf if if.o

if: if.asm
	nasm -f elf -F dwarf -g if.asm
	gcc -g -m32 -o if if.o /usr/local/share/csc314/driver.c /usr/local/share/csc314/asm_io.o
