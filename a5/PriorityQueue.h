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
    PriorityQueue(int initialCapacity = 1);
    PriorityQueue(arrayList *Array);
//    virtual ~PriorityQueue(){delete MinHeap;};
    virtual void initialize(arrayList* Array, int size);
    virtual void preOrder(int position);
    virtual void postOrder(int position);
    virtual void inOrder(int position);
    virtual void sort();
    virtual int pop();
    virtual int top();

   protected:
    MinHeap* minHeap;
};
