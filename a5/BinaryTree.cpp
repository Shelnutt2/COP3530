/*
Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#ifndef _bintree
#define _bintree
#include <BinaryTree.h>
#endif

#include <stdio.h>

using namespace std;

BinaryTree::BinaryTree(int initialCapacity){ //Constructor to intialize based on size
    binArray = new arrayList(initialCapacity);
}

BinaryTree::BinaryTree(arrayList* Array){ //Cosntructor to intialize based on arrayList
    binArray = new arrayList(*Array);
}

void BinaryTree::insert(int position, int element){ //Insertation method
    binArray->insert(position-1,element); //Insert the element, offset for -1 since trees start at "1" but arrays at "0"
}

void BinaryTree::remove(int position){ //Remove a given index
    if(size() == 1){ //If we only have 1 index, just create a new array
        binArray = new arrayList();
    }
    else //Else remove the given index, offsetting for 1 again
        binArray->erase(position-1);
}

int BinaryTree::get(int position){ //Get a given element
    return(*binArray->get(position-1));
}

int BinaryTree::size(){ //Get the size of the array
    return binArray->size();
}

int cmp(const void * pa, const void * pb) //Compare function for sorting
{
    int a = *(const int*)pa;
    int b = *(const int*)pb;
    if (a==b)
        return 0;
    else
        if (a < b)
            return -1;
        else
            return 1;
}

void BinaryTree::sort(){ //Sorting algorthm
    int size1 = size(); //Get the current size
    int temp[size1]; //Create a temporary array
    int i;
    for(i = 0; i<size1;i++){ //Add all elments to the array
        temp[i] = get(i+1);
    }
    size1 = sizeof(temp)/sizeof(temp[0]); //Get size of new array
    qsort(temp, size1,sizeof(int), cmp); //Use the quicksort algorthm to sort the array
    binArray = new arrayList(size1); //Create a new binary array
    for(i = 0; i<size1;i++){ //Insert all sorted elements into the new arraylist
        insert(i+1,temp[i]);
    }

}
