CC = gcc
CFLAGS = -O -Wall -W -pedantic -ansi -std=c99

stackclient.out: stackclient.o stackADT.o
	$(CC) $(CFLAGS) -o stackclient.out stackclient.o stackADT.o

stackclient.o: stackclient.c stackADT.h
	$(CC) $(CFLAGS) -c stackclient.c

stackADT.o: stackADT.c stackADT.h
	$(CC) $(CFLAGS) -c stackADT.c
