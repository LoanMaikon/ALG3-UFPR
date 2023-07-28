CFLAGS = -Wall -std=c99  # flags de compilacao
LDFLAGS = -lm

CC = gcc

# arquivos-objeto
	objects = myht myht.o hash.o
     
myht: myht.o hash.o
	$(CC) -o myht myht.o hash.o $(LDFLAGS)

myht.o: myht.c
	$(CC) -c $(CFLAGS) myht.c

hash.o: hash.c
	$(CC) -c $(CFLAGS) hash.c

clean:
	rm -f $(objects)