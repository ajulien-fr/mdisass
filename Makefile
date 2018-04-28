all:
	gcc -DDEBUG -g *.c insn/*.c -Wall -o mdisass
