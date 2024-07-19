CC = gcc
CFLAGS = -Wall -Wextra -g

all : PROJET EXECUTION

PROJET:  main.o code.o
	$(CC) -o PROJET main.o code.o

fichier1.o: fichier1.c
	$(CC)  -c main.c

fichier2.o: fichier2.c
	$(CC)  -c code.c

EXECUTION :
	./PROJET

clean:
	rm -f PROJET *.o
