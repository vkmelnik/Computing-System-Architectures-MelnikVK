# makefile for perimeter.asm
task: main.c input.c inrnd.c output.c area.o
	gcc -g -o task main.c input.c inrnd.c output.c area.o -no-pie
area.o: area.asm
	nasm -f elf64 -g -F dwarf area.asm -l area.lst
