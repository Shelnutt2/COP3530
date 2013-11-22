/*Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#include <stdio.h>

#ifndef _BinPacking
#define _BinPacking
#include <BinPacking.h>
#endif

#ifndef _BinaryTreeNode
#define _BinaryTreeNode
#include <BinaryTreeNode.h>
#endif

#ifndef _BinarySearchTree
#define _BinarySearchTree
#include <BinarySearchTree.h>
#endif

#ifndef _MaxWinnerTree
#define _MaxWinnerTree
#include <MaxWinnerTree.h>
#endif

using namespace std;

void BinPacking::firstFitPack2(int *objectSize, int numberOfObjects, int binCapacity){
    MaxWinnerTree* MWT = new MaxWinnerTree(objectSize,numberOfObjects,binCapacity);
    int i;
    for(i = 0;i<numberOfObjects;i++){
        BinaryTreeNode* bin = MWT->play(objectSize[i]);
        bin->capacity -= objectSize[i];
        printf("Pack object %d in bin %d\n", i+1, bin->binNumber);            
    }

}

//Reference implementation, not called unless PRIMARY is undefined
void BinPacking::firstFitPack(int *objectSize, int numberOfObjects, int binCapacity){
    int n = numberOfObjects;
    BinaryTreeNode *bin = new BinaryTreeNode[n+1];
    int i;
    for(i = 0; i <n;i++){
        bin[i].capacity = binCapacity;
        bin[i].initialCapacity = binCapacity;
    }
    int j;
    for(i = 0;i<n;i++){
        for(j = 0;j<=n;j++){
            if(bin[j].capacity >= objectSize[i]){
                bin[j].capacity -= objectSize[i];
                printf("Pack object %d in bin %d\n", i+1, j+1);
                break;
            }
        }
    }

}


void BinPacking::bestFitPack(int *objectSize, int numberOfObjects, int binCapacity){
    int n = numberOfObjects;
    BinaryTreeNode *bin = new BinaryTreeNode[n+1];
    BinarySearchTree* BST = new BinarySearchTree();
    int i;
    for(i = 0; i <n;i++){
        bin[i].capacity = binCapacity;
        bin[i].initialCapacity = binCapacity;
    }
    for(i = 0; i<n;i++){
        BST->insert(i,binCapacity);
    }
    int j;
    int currentBin = -1;
    for(i = 0;i<n;i++){
        currentBin = -1;
        for(j = 0;j<n;j++){
            if(BST->find(j)->capacity >= objectSize[i]){
                if(currentBin == -1){
                    currentBin = j;
                }
                else{
                    if(BST->find(j)->capacity < BST->find(currentBin)->capacity)
                        currentBin = j;
                }
            }
        }
                BST->find(currentBin)->capacity -= objectSize[i];
                printf("Pack object %d in bin %d\n", i+1, currentBin+1);
    }
}

//Reference implementation, not called unless PRIMARY is undefined
void BinPacking::bestFitPack2(int *objectSize, int numberOfObjects, int binCapacity){
        int n = numberOfObjects;
    BinaryTreeNode *bin = new BinaryTreeNode[n+1];
    int i;
    for(i = 0; i <n;i++){
        bin[i].capacity = binCapacity;
        bin[i].initialCapacity = binCapacity;
    }
    int j;
    int currentBin = -1;
    for(i = 0;i<n;i++){
        currentBin = -1;
        for(j = 0;j<=n;j++){
            if(bin[j].capacity >= objectSize[i]){
                if(currentBin == -1){
                    currentBin = j;
                }
                else{
                    if(bin[j].capacity < bin[currentBin].capacity)
                        currentBin = j;
                }
            }
        }
                bin[currentBin].capacity -= objectSize[i];
                printf("Pack object %d in bin %d\n", i+1, currentBin+1);
    }
}
