NAME=dowhile

all: dowhile

clean:
	rm -rf dowhile dowhile.o

dowhile: dowhile.asm
	nasm -f elf -F dwarf -g dowhile.asm
	gcc -g -m32 -o dowhile dowhile.o /usr/local/share/csc314/driver.c /usr/local/share/csc314/asm_io.o
