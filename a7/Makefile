#Name : Seth Shelnutt
#UF ID: 42941969
#Gator ID: s.shelnutt
#Discussion section # : 1085


# What compiler to use
CC=g++
# CFLAGS to pass
CFLAGS=-c -Wall -I. -g

all: main tar

main: main.o myException.o Graph.o Vertex.o
	$(CC) main.o myException.o Graph.o Vertex.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Vertex.o: Vertex.cpp
	$(CC) $(CFLAGS) Vertex.cpp

myException.o: myException.cpp
	$(CC) $(CFLAGS) myException.cpp

Graph.o: Graph.cpp
	$(CC) $(CFLAGS) Graph.cpp

clean:
	rm -rf *o main SethShelnutt_42941969.tar

tar:
	tar -cf SethShelnutt_42941969.tar Dijkstras.h Vertex.cpp Vertex.h main.cpp myException.cpp Graph.cpp Graph.h Makefile myException.h

