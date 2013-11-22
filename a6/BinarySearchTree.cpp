/*Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#ifndef _BinarySearchTree
#define _BinarySearchTree
#include <BinarySearchTree.h>
#endif

#ifndef _cstddef
#define _cstddef
#include <cstddef>
#endif

// linked binary tree implementation of a binary search tree
// implements all dictionary and bsTree methods


using namespace std;

BinarySearchTree::BinarySearchTree(){//Constructor

}

BinaryTreeNode* BinarySearchTree::find(const int binNumber){ //Find treenode with matching binNumber

   BinaryTreeNode *p = root; //Set initial to root;
   while (p != NULL) //Loop through all elements
      if (binNumber < p->binNumber) //Compare binNumbers
         p = p->lchild; //Move to left child
      else
         if (binNumber > p->binNumber) //Compare binNumbers
            p = p->rchild; //Move to right child
         else // found binNumber
            return p;

   return NULL;
}

void BinarySearchTree::insert(int binNumber, int capacity){ //Insert new bin

   BinaryTreeNode *p = root, *pp = NULL; //Create temp nodes

   while (p != NULL){ //Loop through all nodes
   
      pp = p;
      if (binNumber < p->binNumber) //Compare binNumber
         p = p->lchild; //Move to the left child
      else
         if (binNumber > p->binNumber) //Compare binNumber
            p = p->rchild; //Move to the right child
         else
         {//If binNumber already exist, set new capacity
            p->capacity = capacity;
            return;
         }
   }

   //Else make new node
   BinaryTreeNode *newNode = new BinaryTreeNode();
   newNode -> capacity = capacity; //Set initial capacity
   newNode -> binNumber = binNumber; //Set binNumber
   if (root != NULL) // Make sure tree isn't empy
      if (binNumber < pp->binNumber) //Compare binNumber
         pp->lchild = newNode; //Set as left child
      else
         pp->rchild = newNode; //Set as right child
   else
      root = newNode; //Else make it root element if tree is empty
   treeSize++; //Increase treeSize
}


void BinarySearchTree::erase(BinaryTreeNode *n){ //Delete a node

   //Find the given node
   BinaryTreeNode *p = root, *pp = NULL;
   while (p != NULL && p == n){ //Loop through nodes
   
      pp = p;
      if (n->binNumber < p->binNumber) //Compare binNumbers
         p = p->lchild; //Move to left child
      else
         p = p->rchild; //Move to right child
   }
   if (p == NULL)
      return; 

   if (p->lchild != NULL && p->rchild != NULL){ //Reset the tree structure
   
      BinaryTreeNode*s = p->lchild, *ps = p;
      while (s->rchild != NULL){
         ps = s;
         s = s->rchild;
      }
      BinaryTreeNode *q = new BinaryTreeNode(p->lchild, p->rchild,s);
      if (pp == NULL)
         root = q;
      else if (p == pp->lchild)
              pp->lchild = q;
           else
              pp->rchild = q;
      if (ps == p) pp = q;
      else pp = ps;
      delete p;
      p = s;
   }
   BinaryTreeNode *c;
   if (p->lchild != NULL)
      c = p->lchild;
   else
      c = p->rchild;

   if (p == root)
      root = c;
   else{
      if (p == pp->lchild)
         pp->lchild = c;
      else pp->rchild = c;
   }
   treeSize--;
   delete p;
}
