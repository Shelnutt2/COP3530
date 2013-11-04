#Name : Seth Shelnutt
#UF ID: 42941969
#Gator ID: s.shelnutt
#Discussion section # : 1085


# What compiler to use
CC=g++
# CFLAGS to pass
CFLAGS=-c -Wall -I. -g

all: main tar

main: main.o Arraylist.o myException.o BinaryTree.o MinHeap.o PriorityQueue.o
	$(CC) main.o Arraylist.o myException.o BinaryTree.o MinHeap.o PriorityQueue.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Arraylist.o: Arraylist.cpp
	$(CC) $(CFLAGS) Arraylist.cpp

myException.o: myException.cpp
	$(CC) $(CFLAGS) myException.cpp

BinaryTree.o: BinaryTree.cpp
	$(CC) $(CFLAGS) BinaryTree.cpp

MinHeap.o: MinHeap.cpp
	$(CC) $(CFLAGS) MinHeap.cpp

PriorityQueue.o: PriorityQueue.cpp
	$(CC) $(CFLAGS) PriorityQueue.cpp

clean:
	rm -rf *o main SethShelnutt_42941969.tar

tar:
	tar -cf SethShelnutt_42941969.tar Arraylist.cpp BinaryTree.h Makefile myException.h Arraylist.h Linearlist.h MinHeap.cpp PriorityQueue.cpp BinaryTree.cpp MinHeap.h main.cpp myException.cpp PriorityQueue.h
