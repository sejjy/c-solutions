CC = gcc
CFLAGS = -O -Wall -W -pedantic -ansi -std=c99

queueclient.out: queueclient.o queueADT.o
	$(CC) $(CFLAGS) -o queueclient.out queueclient.o queueADT.o

queueclient.o: queueclient.c queueADT.h
	$(CC) $(CFLAGS) -c queueclient.c

queueADT.o: queueADT.c queueADT.h
	$(CC) $(CFLAGS) -c queueADT.c
