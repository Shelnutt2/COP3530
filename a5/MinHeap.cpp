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

#ifndef ARRLIST
#define ARRLIST
#include <ArrayLisy.h>
#endif
#include <functional>

using namespace std; 

MinHeap::MinHeap(int initialCapacity){
    binTree = new BinaryTree(initialCapacity);
}

MinHeap::MinHeap(arrayList *MinArray){
    binTree = new BinaryTree(MinArray);
    sort();
}

MinHeap::MinHeap(arrayList* MinArray, int size){
    binTree = new BinaryTree(size);
    int i = 1;
    for(i = 1; i<=size;i++){
        binTree->insert(i,*MinArray->get(i-1));
    }
    sort();
}

void MinHeap::insert(int element){
    binTree->insert(binTree -> size(), element);
    MinHeap::sort();
}

int MinHeap::get(int index){
    return binTree -> get(index);
}

void MinHeap::remove(int index){
    binTree -> remove(index);
    if(size() > 1)
        sort();
}

void MinHeap::sort(){
    binTree -> sort();
}

int MinHeap::size(){
    return binTree -> size();
}
