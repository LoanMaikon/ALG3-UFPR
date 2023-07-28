CFLAGS = -Wall -std=c99 -g
LDFLAGS = -lm
CC = gcc
objects = myavl.o arvore.o myavl
     
myavl: myavl.o arvore.o
	$(CC) -o myavl myavl.o arvore.o $(LDFLAGS)

myavl.o: myavl.c
	$(CC) -c $(CFLAGS) myavl.c
	
arvore.o: arvore.c
	$(CC) -c $(CFLAGS) arvore.c

clean:
	rm -f $(objects)