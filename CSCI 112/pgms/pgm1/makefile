prints.o: prints.c
	gcc -c -Wall prints.c

main.o: main.c
	gcc -c -Wall main.c

pgm1: prints.o main.o
	gcc -o pgm1 -lm prints.o main.o
