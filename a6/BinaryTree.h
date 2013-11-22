/*Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#ifndef _BinaryTreeNode
#define _BinaryTreeNode
#include <BinaryTreeNode.h>
#endif


using namespace std;

class BinaryTree{
    public:
        BinaryTree();
        BinaryTree(BinaryTreeNode* node);
        void preOrder(BinaryTreeNode* node);
        void inOrder(BinaryTreeNode* node);
        BinaryTreeNode* getbinNumber(BinaryTreeNode* node, int binNum);
        BinaryTreeNode* findLessObject(BinaryTreeNode* node, int binNum);
        BinaryTreeNode* findLast(BinaryTreeNode* node, int depth);
        void postOrder(BinaryTreeNode* node);
        void setCapacity(BinaryTreeNode* node, int binCapacity);
        void setinitialCapacity(BinaryTreeNode* node, int binCapacity);
        void setbinNumber(BinaryTreeNode* node,int num);
        BinaryTreeNode* visit(BinaryTreeNode* node);
        void sortMax();
        void insertTop(BinaryTreeNode* node);
        void addLeftChild(BinaryTreeNode* parent, BinaryTreeNode* child);
        void addRightChild(BinaryTreeNode* parent, BinaryTreeNode* child);
        void swapLeft(BinaryTreeNode* first, BinaryTreeNode* second);
        void swapRight(BinaryTreeNode* first, BinaryTreeNode* second);
        void swapChildren(BinaryTreeNode* parent);
        void binCompare(BinaryTreeNode* index);
        void add(BinaryTreeNode* node);

        BinaryTreeNode* root;



        int treeSize;
};
