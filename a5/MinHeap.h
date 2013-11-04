/*
Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#ifndef _binarytree
#define _binarytree
#include <BinaryTree.h>
#endif

using namespace std; 

class MinHeap : public BinaryTree
{
   public:
    MinHeap(int initialCapacity = 1); //Constructor to intialize based on size
    MinHeap(arrayList *MinArray); //Cosntructor to intialize based on arrayList
    MinHeap(arrayList *MinArray,int size); //Cosntructor to intialize based on size and arrayList
    virtual ~MinHeap(){delete binTree;}; //Decosntructor
    virtual void insert(int element); //Insert an element
    virtual int get(int position); //Get an index
    virtual void sort(); //Calls bintree's sort method
    virtual void remove(int position); //Remove an indexs
    virtual int size(); //Get the current size

   protected:
    BinaryTree* binTree; //Underlying binarytree
};
