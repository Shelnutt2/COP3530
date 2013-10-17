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
   if (queueArray->empty())
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
   arrayList* a = new arrayList(queueArray->size() - 1);
   for(int i = 1; i < queueArray->size()-1; i++){
      a->insert(i,*(queueArray->get(i)));
   }
   queueArray = a;
}

void queue::push(int theElement){
    queueArray->insert(queueArray->size(),theElement);
/*   arrayList* a = new arrayList(queueArray->size() + 1);
   for(int i = 0; i < queueArray->size()-1; i++){
      a->insert(i,*(queueArray->get(i)));
   }
   a->insert(a->size()-1,theElement);
   queueArray = a;*/
}

void queue::queueEmpty(){
   cout << "queue is Empty" << endl;
}