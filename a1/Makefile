# What compiler to use
CC=g++
# CFLAGS to pass
CFLAGS=-c -Wall -I.

all: main tar

main: main.o
	$(CC) main.o -o main
	

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -rf *o main SethShelnutt_42941969.tar

tar:
	tar -cf SethShelnutt_42941969.tar header.h  main.cpp Makefile
