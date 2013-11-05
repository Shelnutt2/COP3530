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
#include <math.h>

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

int BinaryTree::remove(int position){ //Remove a given index
    int* temp = binArray->get(position-1);
    if(size() == 1){ //If we only have 1 index, just create a new array
        binArray = new arrayList();
    }
    else //Else remove the given index, offsetting for 1 again
        binArray->erase(position-1);
    return *temp;
}

#if 0
void BinaryTree::shiftdown(int index){
    printf("shifting\n");
    int current = index;
    int child = current*2;
    int Item = get(current);    // Used to compare values

    while (child < size())
    {
        printf("current: %d, child: %d \n",current,child);
        if (child < (size() - 1))
            if (get(child) < get(child+1))  // Set Child to largest Child node
                ++child;

        if (Item < get(child)){    // Switch the Current node and the Child node
            binArray -> changeValue(current,get(child));
            current       = child;
            child         = current*2;
        }
        else
            break;
    }
    binArray -> changeValue(current,Item);
}
#endif

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

#if 0
void BinaryTree::sort2(){ //Sorting algorthm
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
#endif

void BinaryTree::sort(){ //Sorting algorthm
    int startingParent = floor(size()/2);
    while(startingParent > 1){
        if(startingParent*2 <= size())
            break;
        else
            startingParent--;
    }
// printTree();
    while(startingParent > 0){
        compare(startingParent);
        startingParent--;
    }
}

void BinaryTree::printTree(){
printf("     %d\n",get(1));
printf("     /  \\\n");
printf("   %d    %d\n",get(2),get(3));
printf("  /   \\  / \\\n");
printf(" %d    %d  %d  %d\n",get(4),get(5),get(6),get(7));
printf(" /\\   /\n");
printf("%d  %d %d\n\n",get(8),get(9),get(10));
}

void BinaryTree::compare(int index){
    int temp = get(index);
    if(index == 1){
        compare2(index);
    }
    if(index*2+1 <= size() && get(index) > get(index*2+1)){
        int temp2 = get(index*2+1);
        binArray -> changeValue(index-1,temp2);
        binArray -> changeValue((index*2),temp);
        compare(index*2+1);
    }
    else if(index*2 <=size() && get(index) > get(index*2)){
        int temp2 = get(index*2);
        binArray -> changeValue(index-1,temp2);
        binArray -> changeValue((index*2-1),temp);
        compare(index*2);
    }
//    printTree();
}

void BinaryTree::compare2(int index){
    int temp = get(index);
        if(index*2 <= size() && get(index) > get(index*2)){
            int temp2 = get(index*2);
            binArray -> changeValue(index-1,temp2);
            binArray -> changeValue((index*2-1),temp);
            compare2(index*2);
        }
        else if(index*2+1 <=size() && get(index) > get(index*2+1)){
            int temp2 = get(index*2+1);
            binArray -> changeValue(index-1,temp2);
            binArray -> changeValue((index*2),temp);
            compare2(index*2+1);
        }
//    printTree();
}
#if 0
void BinaryTree::compare2(int index){
    int temp = get(index);
    if(index*2+1 <= size() && get(index) > get(index*2+1)){
        if(get(index*2+1)>=get(index*2)){
            int temp2 = get(index*2+1);
            binArray -> changeValue(index-1,temp2);
            binArray -> changeValue((index*2),temp);
            compare2(index*2+1);
        }
    }
    else if(index*2 <=size() && get(index) > get(index*2)){
        int temp2 = get(index*2);
        binArray -> changeValue(index-1,temp2);
        binArray -> changeValue((index*2-1),temp);
        compare2(index*2);
    }
    printTree();
}
#endif
