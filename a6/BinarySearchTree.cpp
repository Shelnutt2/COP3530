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



BinaryTreeNode* BinarySearchTree::find(const int theKey)
{// Return pointer to matching pair.
 // Return NULL if no matching pair.
   // p starts at the root and moves through
   // the tree looking for an element with key theKey
   BinaryTreeNode *p = root;
   while (p != NULL)
      // examine p->element
      if (theKey < p->binNumber)
         p = p->lchild;
      else
         if (theKey > p->binNumber)
            p = p->rchild;
         else // found matching pair
            return p;

   // no matching pair
   return NULL;
}

void BinarySearchTree::insert(int capacity, int binNumber)
{// Insert node into the tree. Overwrite existing
 // pair, if any, with same key.
   // find place to insert
   BinaryTreeNode *p = root, *pp = NULL;

   while (p != NULL)
   {// examine p->element
      pp = p;
      // move p to a child
      if (capacity < p->capacity)
         p = p->lchild;
      else
         if (capacity > p->capacity)
            p = p->rchild;
         else
         {// replace old value
            p->binNumber = binNumber;
            return;
         }
   }

   // get a node for thePair and attach to pp
   BinaryTreeNode *newNode = new BinaryTreeNode();
   newNode -> capacity = capacity;
   newNode -> binNumber = binNumber;
   if (root != NULL) // the tree is not empty
      if (capacity < pp->capacity)
         pp->lchild = newNode;
      else
         pp->rchild = newNode;
   else
      root = newNode; // insertion into empty tree
   treeSize++;
}


void BinarySearchTree::erase(BinaryTreeNode *n)
{// Delete the pair, if any, whose key equals theKey.

   // search for node with key theKey
   BinaryTreeNode *p = root, *pp = NULL;
   while (p != NULL && p == n)
   {// move to a child of p
      pp = p;
      if (n->binNumber < p->binNumber)
         p = p->lchild;
      else
         p = p->rchild;
   }
   if (p == NULL)
      return; // no pair with key theKey

   // restructure tree
   // handle case when p has two children
   if (p->lchild != NULL && p->rchild != NULL)
   {// two children
      // convert to zero or one child case
      // find largest element in left subtree of p
      BinaryTreeNode*s = p->lchild, *ps = p;  // parent of s
      while (s->rchild != NULL)
      {// move to larger element
         ps = s;
         s = s->rchild;
      }

      // move largest from s to p, can't do a simple move
      // p->element = s->element as key is const
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

   // p has at most one child
   // save child pointer in c
   BinaryTreeNode *c;
   if (p->lchild != NULL)
      c = p->lchild;
   else
      c = p->rchild;

   // delete p
   if (p == root)
      root = c;
   else
   {// is p left or right child of pp?
      if (p == pp->lchild)
         pp->lchild = c;
      else pp->rchild = c;
   }
   treeSize--;
   delete p;
}
