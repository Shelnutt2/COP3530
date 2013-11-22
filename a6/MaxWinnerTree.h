/*Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#ifndef _BinaryTree
#define _BinaryTree
#include <BinaryTree.h>
#endif

using namespace std;

class MaxWinnerTree : public BinaryTree{
    public:
        MaxWinnerTree();
        MaxWinnerTree(int *object, int numberofObjects);
        MaxWinnerTree(int *object, int numberofObjects, int binCapacity);
        ~MaxWinnerTree(){delete binTree;};
        void initialize(int* bins, int numerOfBins);
        void replay(BinaryTreeNode* n);
        BinaryTreeNode* find(int objectSize);
        //int winner(int i) const{return (i < numerOfBins) ? tree[i] : 0;}
        void rePlay(int);
        BinaryTreeNode* play(int objectSize);
    protected:
        int numerOfBins;
        BinaryTree* binTree;
};


