/*
Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#ifndef _priorityqueue
#define _priorityqueue
#include <PriorityQueue.h>
#endif

#include <stdio.h>

using namespace std; 


PriorityQueue::PriorityQueue(){ //Constructor to intialize based on size
    //minHeap = new MinHeap(initialCapacity);
}

PriorityQueue::PriorityQueue(arrayList* Array){ //Constructor to intialize based on an arrayList
    minHeap = new MinHeap(Array);
}

void PriorityQueue::initialize(arrayList *Array, int size){ //intialize based on size and a given array lsit
    minHeap = new MinHeap(Array,size);
}

void PriorityQueue::preOrder(int position){ //Print elements in preorder form
    if (position == 0)
        position++; //Start with 1 not 0;
    if (position > minHeap -> size()) //If we are outside of the heap return
      return;
    else{
      printf("%d ",minHeap -> get(position)); //Print element
      preOrder(position*2); //Visit left child
      preOrder(position*2+1); //Visit right child
    }
}

void PriorityQueue::postOrder(int position){ //Print elements in postorder form
    if (position == 0)
        position++; //Start with 1 not 0;
    if (position > minHeap -> size())
      return;
    else{
      postOrder(position*2); //Visit left child
      postOrder(position*2+1); //Visit right child
      printf("%d ",minHeap -> get(position)); //Print element
    }
}

void PriorityQueue::inOrder(int position){ //Print elements in order form
    if (position == 0)
        position++; //Start with 1 not 0;
    if (position > minHeap -> size())
      return;
    else{
      postOrder(position*2); //Visit left child
      printf("%d ",minHeap -> get(position)); //Print element
      postOrder(position*2+1); //Visit right child
    }
}

void PriorityQueue::sort(){ //Sort the queue and remove all elements
    while(minHeap -> size() > 0){
        printf("%d ",pop()); //Print and pop
    }
}

int PriorityQueue::pop(){ //Pop first element from queue
    int first = top(); //Get top
    minHeap -> remove(1); //Remove top
    return first; //return previous top
}

int PriorityQueue::top(){ //Get top element
    return minHeap -> get(1);
}
