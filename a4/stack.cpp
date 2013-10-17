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
    if(stackArray->size() > 0)
        return false;
    else
        return true;
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
    int size = stackArray->size();
    if (size < 1)
        stackEmpty();
    else if (size > 1){
       arrayList* a = new arrayList(stackArray->size() - 1);
       for(int i = 0; i < stackArray->size()-1; i++){
          a->insert(i,*(stackArray->get(i)));
       }
       stackArray = a;
    }
}

void stack::push(int theElement){
    stackArray->insert(stackArray->size(),theElement);
    /*if(stackArray->size() == 0){
        stackArray->insert(stackArray->size(),theElement);
    }
    else{
        arrayList* a = new arrayList(stackArray->size() + 1);
        for(int i = 0; i < stackArray->size(); i++){
           a->insert(i,*(stackArray->get(i)));
        }
        a->insert(a->size(),theElement);
        stackArray = a;
    }*/
}

void stack::stackEmpty(){
   cout << "Stack is Empty" << endl;
}
