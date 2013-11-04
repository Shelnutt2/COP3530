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

#include <math.h>
#include <stdlib.h>

using namespace std; 

class BinaryTree : public arrayList
{
   public:
    BinaryTree(int initialCapacity = 1);
    BinaryTree(arrayList *binArray);
    virtual ~BinaryTree(){delete binArray;};
    virtual void insert(int position, int element);
//    virtual int* getChildren(int position);
//    virtual int getParent(int position);
    virtual int get(int position);
    virtual int size();
    virtual void remove(int position);
    void sort();

   protected:
    arrayList* binArray;
};
