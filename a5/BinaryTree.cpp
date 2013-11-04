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

BinaryTree::BinaryTree(int initialCapacity){
    binArray = new arrayList(initialCapacity);
}

BinaryTree::BinaryTree(arrayList* Array){
    binArray = new arrayList(*Array);
}

void BinaryTree::insert(int position, int element){
//    printf("Position is: %d, element is: %d \n",position,element);
    binArray->insert(position-1,element);
//    printf("The inserted element is now: %d\n", get(position));
}

void BinaryTree::remove(int position){
    if(size() == 1){
        binArray = new arrayList();
    }
    else
        binArray->erase(position-1);
}

#if 0
int* BinaryTree::getChildren(int position){
    if(position*2 <= binArray->size()){
        int r[2];
        r[0] = binArray->get(floor(2*position)-1);
        r[1] = binArray->get(floor(2*position));
        return r;
    }
    else
        return NULL;
}


int BinaryTree::getParent(int position){
    return(binArray->get(floor(position/2)-1));
}
#endif
int BinaryTree::get(int position){
    return(*binArray->get(position-1));
}

int BinaryTree::size(){
    return binArray->size();
}

int cmp(const void * pa, const void * pb)
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

void BinaryTree::sort(){
    int size1 = size();
    int temp[size1];
    int i;
    for(i = 0; i<size1;i++){
        temp[i] = get(i+1);
    }
    size1 = sizeof(temp)/sizeof(temp[0]);
    qsort(temp, size1,sizeof(int), cmp);
    binArray = new arrayList(size1);
    for(i = 0; i<size1;i++){
        insert(i+1,temp[i]);
    }

}
