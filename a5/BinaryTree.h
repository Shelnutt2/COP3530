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
    BinaryTree(int initialCapacity = 1); //Constructor to intialize based on size
    BinaryTree(arrayList* Array); //Cosntructor to intialize based on arrayList
    virtual ~BinaryTree(){delete binArray;}; //Deconstructor
    virtual void insert(int position, int element); //Insertion method
    virtual int get(int position); //Get the given element
    virtual int size(); //Get the size of the binarytree
    virtual int remove(int position); //Remove element
    void sort(); //Sort the tree
    void compare(int index);
    void compare2(int index);
    void printTree();

   protected:
    arrayList* binArray; //Underlying array
};
