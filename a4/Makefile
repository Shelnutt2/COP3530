#Name : Seth Shelnutt
#UF ID: 42941969
#Gator ID: s.shelnutt
#Discussion section # : 1085


# What compiler to use
CC=g++
# CFLAGS to pass
CFLAGS=-c -Wall -I. -g

all: main tar

main: main.o Arraylist.o myException.o queue.o stack.o RatinMaze.o
	$(CC) main.o Arraylist.o myException.o queue.o stack.o RatinMaze.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Arraylist.o: Arraylist.cpp
	$(CC) $(CFLAGS) Arraylist.cpp

myException.o: myException.cpp
	$(CC) $(CFLAGS) myException.cpp

queue.o: queue.cpp
	$(CC) $(CFLAGS) queue.cpp

stack.o: stack.cpp
	$(CC) $(CFLAGS) stack.cpp

RatinMaze.o: RatinMaze.cpp
	$(CC) $(CFLAGS) RatinMaze.cpp

clean:
	rm -rf *o main SethShelnutt_42941969.tar

tar:
	tar -cf SethShelnutt_42941969.tar Arraylist.cpp main.cpp myException.h RatinMaze.cpp stack.h Arraylist.h Makefile queue.cpp RatinMaze.h Linearlist.h myException.cpp queue.h stack.cpp

