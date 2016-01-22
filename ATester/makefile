projet:monomes.o polynomes.o main.o
	gcc monomes.o polynomes.o main.o -o projet -lm

monomes.o: header.h monomes.h monomes.c
	gcc -c -Wall monomes.c
	
polynomes.o: header.h monomes.h polynomes.h polynomes.c
	gcc -c -Wall polynomes.c

main.o: header.h monomes.h polynomes.h main.c
	gcc -c -Wall main.c
