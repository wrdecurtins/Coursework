NAME=for

all: for

clean:
	rm -rf for for.o

for: for.asm
	nasm -f elf -F dwarf -g for.asm
	gcc -g -m32 -o for for.o /usr/local/share/csc314/driver.c /usr/local/share/csc314/asm_io.o
