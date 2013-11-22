/*Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#ifndef _BinaryTree
#define _BinaryTree
#include <BinaryTree.h>
#endif

#ifndef _cstddef
#define _cstddef
#include <cstddef>
#endif

#include <math.h>
#include <stdio.h>

using namespace std;

BinaryTree::BinaryTree(){
    treeSize++;
    root = new BinaryTreeNode();
}

BinaryTree::BinaryTree(BinaryTreeNode* node){ //Constructor
    root = node;
    treeSize++;
}

BinaryTreeNode* BinaryTree::visit(BinaryTreeNode* node){ //Constructor
    return node;
}

void BinaryTree::setCapacity(BinaryTreeNode* node, int binCapacity){
    node->capacity = binCapacity;
}

void BinaryTree::setinitialCapacity(BinaryTreeNode* node, int binCapacity){
    node->initialCapacity = binCapacity;
}

void BinaryTree::setbinNumber(BinaryTreeNode* node,int num){
    node->binNumber = num;
}

void BinaryTree::preOrder(BinaryTreeNode* node){
    if (node != NULL){ //If we are outside of the heap return
      visit(node); //visit
      preOrder(node -> lchild); //Visit left child
      preOrder(node -> rchild); //Visit right child
    }
}

BinaryTreeNode* BinaryTree::findLast(BinaryTreeNode* node,int depth){ //Find last node leaf
    if (node != NULL){ //If we are outside of the heap return
        depth++;
        node->depth = depth;
        BinaryTreeNode* tmp = NULL;
        BinaryTreeNode* tmp2 = NULL;
        if(node -> lchild != NULL)
            tmp = findLast(node -> lchild,depth); //Visit left child
        if(node -> rchild != NULL)
            tmp2 = findLast(node -> rchild,depth); //Visit right child
        if(tmp != NULL){
            if(node->depth > tmp->depth){
                if(tmp2 != NULL){
                    if(node->depth > tmp2->depth)
                        return node;
                    else
                        return tmp2;
                }
                    return node;
            }
            else if(tmp->depth > node->depth){
                if(tmp2 != NULL){
                    if(tmp->depth > tmp2->depth)
                        return tmp;
                    else
                        return tmp2;
                }
                    return tmp;
            }
            else if(tmp->depth > tmp2->depth){
                     return tmp;
            }
            else if(tmp2->depth > tmp->depth){
                     return tmp2;
            }
        }
        else
            return node;
    }
    return NULL;
}

void BinaryTree::inOrder(BinaryTreeNode* node){
    if (node != NULL){ //If we are outside of the heap return
      inOrder(node -> lchild); //Visit left child
      visit(node); //visit
      inOrder(node -> rchild); //Visit right child
    }
}

BinaryTreeNode* BinaryTree::getbinNumber(BinaryTreeNode* node, int parentbinNumber){ //Get bin by binNumber
    if (node != NULL){ //If we are outside of the heap return
        BinaryTreeNode* tmp = getbinNumber(node -> lchild,parentbinNumber); //Visit left child
//        printf("parentbinNumber is: %d nodeBinNumber is: %d\n",parentbinNumber,node->binNumber);
        if(node->binNumber == parentbinNumber){
//            printf("Found parentnode\n");
            return node;
        }
        BinaryTreeNode* tmp2 = getbinNumber(node -> rchild,parentbinNumber); //Visit right child
        if(tmp != NULL)
            return tmp;
        else if(tmp2 != NULL)
            return tmp2;
    }
    return NULL;
}

BinaryTreeNode* BinaryTree::findLessObject(BinaryTreeNode* node, int objectSize){ //Find the less of the nodes
    if (node != NULL){ //If we are outside of the heap return
        BinaryTreeNode* tmp = NULL;
        BinaryTreeNode* tmp2 = NULL;
        tmp = findLessObject(node -> lchild,objectSize); //Visit left child
        tmp2 = findLessObject(node -> rchild,objectSize); //Visit right child
        printf("node is: %d node capacity is: %d objectSize is: %d\n",node->binNumber,node->capacity ,objectSize);
        if(node->capacity >= objectSize)
            return node;
        else if(tmp!=NULL){
            if(tmp->capacity >= objectSize)
                return tmp;
        }
        else if(tmp2!=NULL){
            if(tmp2->capacity >= objectSize)
                return tmp2;
        }
        if(tmp != NULL)
            return tmp;
        else if(tmp2 != NULL)
            return tmp2;
    }
    return NULL;
}


void BinaryTree::postOrder(BinaryTreeNode* node){
    if (node != NULL){ //If we are outside of the heap return
      postOrder(node -> lchild); //Visit left child
      postOrder(node -> rchild); //Visit right child
      visit(node); //visit
    }
}

void BinaryTree::insertTop(BinaryTreeNode* node){
    BinaryTreeNode* tmp = root;
    node -> lchild = tmp->lchild;
    node -> rchild = tmp;
    tmp -> parent = node;
    root = node;
    treeSize++;
    sortMax();
}

/*BinaryTreeNode* BinaryTree::getLastLeaf(){
    int leftDepth = 1;
    BinaryTreeNode* node = root;
    while(node != null){
        if(node -> lchild != null){
            node = node->lchild;
            leftDepth++
        }
    }
}*/

void BinaryTree::add(BinaryTreeNode* node){
    int parentbinNumber = floor((treeSize+1)/2);
//    printf("parentbinNumber: %d\n",parentbinNumber);
    BinaryTreeNode* parentNode = findLast(root,0);
    if(parentNode != root)
        parentNode = parentNode->parent;
    if(parentNode -> lchild == NULL)
        parentNode -> lchild = node;
    else if(parentNode -> rchild == NULL)
        parentNode -> rchild = node;
    node -> parent = parentNode;
    sortMax();
    treeSize++;
}

void BinaryTree::addLeftChild(BinaryTreeNode* parent, BinaryTreeNode* child){
    parent -> lchild = child;
}

void BinaryTree::addRightChild(BinaryTreeNode* parent, BinaryTreeNode* child){
    parent -> rchild = child;
}

void BinaryTree::sortMax(){ //Sorting algorthm
    int startingParent = floor(treeSize/2); //Get the starting parent node
    while(startingParent > 1){ //Make sure we have the real starting parent
        if(startingParent*2 <= treeSize) //Check to see if parent has valid node
            break;
        else
            startingParent--; //If not keep looking
    }
    while(startingParent > 0){ // While we are in the tree, sort it
        binCompare(getbinNumber(root,startingParent)); //Compare and change if needed
        startingParent--; //Sort in reverse order
    }
}

void BinaryTree::swapLeft(BinaryTreeNode* first, BinaryTreeNode* second){ //Swap parent with left child
        BinaryTreeNode* firstr = first->rchild;
        BinaryTreeNode* firstp = first->parent;
        BinaryTreeNode* secondl = second->lchild;
        BinaryTreeNode* secondr = second->rchild;
        first->lchild = secondl;
        first->rchild = secondr;
        first->parent = second;
        second->lchild = first;
        second->rchild = firstr;
        second->parent = firstp;
}

void BinaryTree::swapRight(BinaryTreeNode* first, BinaryTreeNode* second){ //Swap parent with right child
        BinaryTreeNode* firstl = first->lchild;
        BinaryTreeNode* firstp = first->parent;
        BinaryTreeNode* secondl = second->lchild;
        BinaryTreeNode* secondr = second->rchild;
        first->lchild = secondl;
        first->rchild = secondr;
        first->parent = second;
        second->lchild = firstl;
        second->rchild = first;
        second->parent = firstp;
}

void BinaryTree::swapChildren(BinaryTreeNode* parent){ //Swap children of parent
        BinaryTreeNode* leftl = parent->lchild->lchild;
        BinaryTreeNode* leftr = parent->lchild->rchild;
        BinaryTreeNode* rightl = parent->rchild->lchild;
        BinaryTreeNode* rightr = parent->rchild->rchild;
        parent->lchild->lchild = rightl;
        parent->lchild->rchild = rightr;
        parent->rchild->lchild = leftl;
        parent->rchild->rchild = leftr;
        BinaryTreeNode* parentlc = parent->lchild;
        parent->rchild = parent->lchild;
        parent->lchild = parentlc;
}

void BinaryTree::binCompare(BinaryTreeNode* index){ //Compare function
    if(index == NULL)
        return;
    if(index ->lchild != NULL && index->binNumber < index->lchild ->binNumber){ //Check for if the right child is smaller
        swapLeft(index,index->lchild);
/*        int tmpinitialCapacity = index->initialCapacity, tmpCapacity = index->Capacity, tmpbinNumber = index->binNumber;
        index -> initialCapacity = index ->lchild -> initialCapacity ;
        index ->  capacity = ndex ->lchild ->  capacity ;
        index ->  binNumber = index ->lchild ->  binNumber;
        index ->lchild -> initialCapacity = tmpinitialCapacity;
        index ->lchild ->  capacity = tmpCapacity;
        index ->lchild ->  binNumber = tmpbinNumber;*/
        binCompare(index->lchild); //Check to see if we need to sort down
    }
    else if(index -> rchild != NULL && index->binNumber < index->rchild -> binNumber){ //Check for if the right child is smaller
        swapRight(index,index->rchild);
        binCompare(index->rchild); //Check to see if we need to sort down
    }
    if(index->lchild != NULL && index->rchild != NULL && index->lchild->binNumber > index->rchild->binNumber){ //Check if childnodes need swaping
        /*int tmpinitialCapacity = index->rchild->initialCapacity, tmpCapacity = index->rchild->Capacity, tmpbinNumber = index->rchild->binNumber;
        index ->rchild -> initialCapacity = index ->lchild -> initialCapacity ;
        index ->rchild ->  capacity = ndex ->lchild ->  capacity ;
        index ->rchild ->  binNumber = index ->lchild ->  binNumber;
        index ->lchild -> initialCapacity = tmpinitialCapacity;
        index ->lchild ->  capacity = tmpCapacity;
        index ->lchild ->  binNumber = tmpbinNumber;*/
        swapChildren(index);
    }
}
