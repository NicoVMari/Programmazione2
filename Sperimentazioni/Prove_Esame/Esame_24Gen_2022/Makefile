esame : esame main.o liste.o
	gcc -o esame main.o liste.o -Wall -Wextra -Wconversion
main.o : main.c esame.h
	gcc -c main.c -Wall -Wextra -Wconversion
liste.o : liste.c esame.h
	gcc -c liste.c -Wall -Wextra -Wconversion