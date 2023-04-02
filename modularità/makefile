CC=gcc
CFLAGS= -std=c89

app: applicazioni.o operazioni.o
	$(CC) -o app *.o $(CFLAGS)


clean:
	rm -f *.o


run:
	./app
