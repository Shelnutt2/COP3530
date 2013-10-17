/*
Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#ifndef _queue
#define _queue
#include <queue.h>
#endif

using namespace std; 

queue::queue(int initialCapacity){
   queueArray = new arrayList(initialCapacity);
}

bool queue::empty(){
    if(queueArray->size() > 0)
        return false;
    else
        return true;
}

int queue::size(){
    return queueArray->size();
}

int* queue::back(){
   if (queueArray->empty()) //Check for if the queue is empty
        queueEmpty();
   return queueArray->get(queueArray->size() - 1);
}

int* queue::front(){
   if (queueArray->size() == 0)
        queueEmpty();
   return queueArray->get(0);
}

void queue::pop(){
   if (queueArray->size() == 0)
        queueEmpty();
   queueArray->erase(0);
}

void queue::push(int theElement){ //Push element to queue
    queueArray->insert(queueArray->size(),theElement);
}

void queue::queueEmpty(){
   cout << "queue is Empty" << endl;
}
