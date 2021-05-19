NAME=sorting

all: sorting

clean:
	rm -rf sorting sorting.o

sorting: sorting.asm
	nasm -f elf -F dwarf -g sorting.asm
	gcc -g -m32 -o sorting sorting.o /usr/local/share/csc314/driver.c /usr/local/share/csc314/asm_io.o
