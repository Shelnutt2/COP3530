/*
Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#ifndef _stack
#define _stack
#include <stack.h>
#endif

using namespace std; 

stack::stack(int initialCapacity){
   stackArray = new arrayList(initialCapacity);
}

bool stack::empty(){
return stackArray->empty();
}

int stack::size(){
return stackArray->size();
}

int* stack::top(){
   if (stackArray->empty())
       stackEmpty();
   return stackArray->get(stackArray->size() - 1);
}

void stack::pop(){
   if (stackArray->empty())
        stackEmpty();
   arrayList* a = new arrayList(stackArray->size() - 1);
   for(int i = 0; i < stackArray->size()-2; i++){
      a->insert(i,*(stackArray->get(i)));
   }
   stackArray = a;
}

void stack::push(int& theElement){
   arrayList* a = new arrayList(stackArray->size() + 1);
   for(int i = 0; i < stackArray->size()-1; i++){
      a->insert(i,*(stackArray->get(i)));
   }
   a->insert(a->size()-1,theElement);
   stackArray = a;
}

void stack::stackEmpty(){
   cout << "Stack is Empty" << endl;
}
