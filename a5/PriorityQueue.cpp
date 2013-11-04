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


PriorityQueue::PriorityQueue(){
    //minHeap = new MinHeap(initialCapacity);
}

PriorityQueue::PriorityQueue(arrayList* Array){
    minHeap = new MinHeap(Array);
}

void PriorityQueue::initialize(arrayList *Array, int size){

    minHeap = new MinHeap(Array,size);
}

void PriorityQueue::preOrder(int position){
    if (position == 0)
        position++; //Start with 1 not 0;
    if (position > minHeap -> size())
      return;
    else{
      printf("%d ",minHeap -> get(position));
      preOrder(position*2);
      preOrder(position*2+1);
    }
}

void PriorityQueue::postOrder(int position){
    if (position == 0)
        position++; //Start with 1 not 0;
    if (position > minHeap -> size())
      return;
    else{
      postOrder(position*2);
      postOrder(position*2+1);
      printf("%d ",minHeap -> get(position));
    }
}

void PriorityQueue::inOrder(int position){
    if (position == 0)
        position++; //Start with 1 not 0;
    if (position > minHeap -> size())
      return;
    else{
      postOrder(position*2);
      printf("%d ",minHeap -> get(position));
      postOrder(position*2+1);
    }
}

void PriorityQueue::sort(){
    while(minHeap -> size() > 0){
        printf("%d ",pop());
    }
}

int PriorityQueue::pop(){
    int first = top();
    minHeap -> remove(0);
    return first;
}

int PriorityQueue::top(){
    return minHeap -> get(0);
}
