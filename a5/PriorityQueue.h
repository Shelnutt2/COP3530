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

class PriorityQueue : public MinHeap
{
   public:
    PriorityQueue(); //Constructor to intialize based on size
    PriorityQueue(arrayList* Array); //Constructor to intialize based on arrayList
//    virtual ~PriorityQueue(){delete MinHeap;};
    virtual void initialize(arrayList* Array, int size); //intialize based on size and a given array lsit
    virtual void preOrder(int position); //Print elements in preorder form
    virtual void postOrder(int position); //Print elements in postorder form
    virtual void inOrder(int position); //Print elements in order form
    virtual void sort(); //Sort the queue and remove all elements
    virtual int pop(); //Pop first element from queue
    virtual int top(); //Get top Element

   protected:
    MinHeap* minHeap; //Underlying Heap
};
