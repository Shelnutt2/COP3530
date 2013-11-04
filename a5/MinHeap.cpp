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

#include <functional>

using namespace std; 

MinHeap::MinHeap(int initialCapacity){
    binTree = new BinaryTree(initialCapacity);
}

MinHeap::MinHeap(arrayList *MinArray){
    binTree = new BinaryTree(MinArray);
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
    sort();
}

void MinHeap::sort(){
    binTree -> sort();
}
