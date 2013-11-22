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

BinaryTreeNode::BinaryTreeNode(){

}


BinaryTreeNode::BinaryTreeNode(BinaryTreeNode* l, BinaryTreeNode* r, BinaryTreeNode* p){
    lchild = l;
    rchild = r;
    parent = p;
}

