#Name : Seth Shelnutt
#UF ID: 42941969
#Gator ID: s.shelnutt
#Discussion section # : 1085


# What compiler to use
CC=g++
# CFLAGS to pass
CFLAGS=-c -Wall -I. -g

all: main tar

main: main.o BinaryTreeNode.o myException.o BinaryTree.o BinarySearchTree.o MaxWinnerTree.o BinPacking.o
	$(CC) main.o BinaryTreeNode.o myException.o BinaryTree.o BinarySearchTree.o MaxWinnerTree.o BinPacking.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

BinaryTreeNode.o: BinaryTreeNode.cpp
	$(CC) $(CFLAGS) BinaryTreeNode.cpp

myException.o: myException.cpp
	$(CC) $(CFLAGS) myException.cpp

BinaryTree.o: BinaryTree.cpp
	$(CC) $(CFLAGS) BinaryTree.cpp

BinarySearchTree.o: BinarySearchTree.cpp
	$(CC) $(CFLAGS) BinarySearchTree.cpp

MaxWinnerTree.o: MaxWinnerTree.cpp
	$(CC) $(CFLAGS) MaxWinnerTree.cpp

BinPacking.o: BinPacking.cpp
	$(CC) $(CFLAGS) BinPacking.cpp

clean:
	rm -rf *o main SethShelnutt_42941969.tar

tar:
	tar -cf SethShelnutt_42941969.tar BinarySearchTree.cpp BinaryTreeNode.cpp main.cpp myException.cpp BinarySearchTree.h BinaryTreeNode.h Makefile myException.h BinaryTree.cpp BinPacking.cpp MaxWinnerTree.cpp BinaryTree.h BinPacking.h MaxWinnerTree.h

