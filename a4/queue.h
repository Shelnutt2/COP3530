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

class queue : public arrayList
{
   private:
    virtual void queueEmpty();

   public:
    queue(int initialCapacity = 1);
    virtual ~queue(){delete queueArray;};
    virtual bool empty();
    virtual int size();
    virtual int* back();
    virtual int* front();
    virtual void pop();
    virtual void push(const int theElement);

   protected:
    arrayList* queueArray;
};
