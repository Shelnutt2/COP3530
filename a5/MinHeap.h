/*
Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#ifndef _binarytree
#define _binarytree
#include <BinaryTree.h>
#endif

using namespace std; 

class MinHeap : public BinaryTree
{
   public:
    MinHeap(int initialCapacity = 1);
    MinHeap(arrayList *MinArray);
    MinHeap(arrayList *MinArray,int size);
    virtual ~MinHeap(){delete binTree;};
    virtual void insert(int element);
    virtual int get(int position);
    virtual void sort();
    virtual void remove(int position);
    virtual int size();
//    virtual void getChildren(int a);
//    virtual void getParent();

   protected:
    BinaryTree* binTree;
};
