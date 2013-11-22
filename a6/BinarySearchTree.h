/*Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#ifndef _BinaryTree
#define _BinaryTree
#include <BinaryTree.h>
#endif

class BinarySearchTree : public BinaryTree{
	public:
		BinarySearchTree();
		~BinarySearchTree();
		void insert(int capacity, int binNumber);
		void erase(BinaryTreeNode *n);
		BinaryTreeNode* find(int objectSize);
       protected:
       int numberOfPlayers;		
};
