#Name : Seth Shelnutt
#UF ID: 42941969
#Gator ID: s.shelnutt
#Discussion section # : 1085


# What compiler to use
CC=g++
# CFLAGS to pass
CFLAGS=-c -Wall -I.

all: main1 main2 tar

main1: main1.o Arraylist.o IOcode.o Myexception.o
	$(CC) main1.o Arraylist.o IOcode.o Myexception.o -o main1

main2: main2.o Chain.o ChainNode.o IOcode.o Myexception.o
	$(CC) main2.o Chain.o ChainNode.o IOcode.o Myexception.o -o main2

main1.o: main1.cpp
	$(CC) $(CFLAGS) main1.cpp
main2.o: main2.cpp
	$(CC) $(CFLAGS) main2.cpp

Arraylist.o: Arraylist.cpp
	$(CC) $(CFLAGS) Arraylist.cpp

IOcode.o: IOcode.cpp
	$(CC) $(CFLAGS) IOcode.cpp

Myexception.o: Myexception.cpp
	$(CC) $(CFLAGS) Myexception.cpp

Chain.o: Chain.cpp
	$(CC) $(CFLAGS) Chain.cpp

ChainNode.o: ChainNode.cpp
	$(CC) $(CFLAGS) ChainNode.cpp

clean:
	rm -rf *o main1 main2 SethShelnutt_42941969.tar

tar:
	tar -cf SethShelnutt_42941969.tar IOcode.cpp IOcode.h Myexception.cpp Myexception.h Linearlist.h Arraylist.cpp Arraylist.h Chain.cpp Chain.h ChainNode.cpp ChainNode.h main1.cpp main2.cpp Makefile
