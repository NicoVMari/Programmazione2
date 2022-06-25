esame : liste.o main.o
	gcc -o esame liste.o main.o -Wall -Wconversion -Wextra
main.o : main.c esame.h
	gcc -c main.c esame.h -Wall -Wconversion -Wextra
liste.o :liste.c esame.h
	gcc -c liste.c esame.h -Wall -Wconversion -Wextra