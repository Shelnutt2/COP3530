/*
Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#ifndef _minheap
#define _minheap
#include <MinHeap.h>
#endif


using namespace std; 

MinHeap::MinHeap(int initialCapacity){ //Constructor to intialize based on size
    binTree = new BinaryTree(initialCapacity);
}

MinHeap::MinHeap(arrayList *MinArray){ //Cosntructor to intialize based on arrayList
    binTree = new BinaryTree(MinArray);
    sort();
}

MinHeap::MinHeap(arrayList* MinArray, int size){ //Cosntructor to intialize based on size and arrayList.
    binTree = new BinaryTree(size); //Create a new binaryTree based on size
    int i = 1;
    for(i = 1; i<=size;i++){ //Insert elements into the binaryTree
        binTree->insert(i,*MinArray->get(i-1));
    }
    sort();
}

void MinHeap::insert(int element){ //Insert Function, and sort array after each insert
    binTree->insert(binTree -> size(), element); //Insert element
    MinHeap::sort(); //Sort the tree again
}

int MinHeap::get(int index){ //Get an element from the tree
    return binTree -> get(index);
}

int MinHeap::remove(int index){ //Remove an element from the tree
    int temp = binTree -> remove(index); //Remove the element
    if(size() > 1) //If we have more that one item, sort the tree.
        sort();
    return temp;
}

void MinHeap::sort(){ //Call the sort function of binTree
    binTree -> sort();
}

int MinHeap::size(){ //Get the size of the heap
    return binTree -> size();
}
