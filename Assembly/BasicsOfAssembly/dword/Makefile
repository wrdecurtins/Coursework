NAME=dword

all: dword

clean:
	rm -rf dword dword.o

dword: dword.asm
	nasm -f elf -F dwarf -g dword.asm
	gcc -g -m32 -o dword dword.o /usr/local/share/csc314/driver.c /usr/local/share/csc314/asm_io.o
