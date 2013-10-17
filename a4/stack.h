/*
Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#ifndef ARRLIST
#define ARRLIST
#include <Arraylist.h>
#endif
using namespace std; 

class stack : public arrayList
{
   private:
    virtual void stackEmpty();

   public:
    stack(int initialCapacity = 1);
    virtual ~stack(){delete stackArray;};
    virtual bool empty();
    virtual int size();
    virtual int* top();
    virtual void pop();
    virtual void push(int theElement);

   protected:
    arrayList* stackArray;
};
