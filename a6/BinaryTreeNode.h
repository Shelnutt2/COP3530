/*Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

using namespace std;

class BinaryTreeNode{
    public:
        BinaryTreeNode();
        BinaryTreeNode(BinaryTreeNode* l, BinaryTreeNode* r, BinaryTreeNode* p);
       
    public:
        BinaryTreeNode *lchild;
        BinaryTreeNode *rchild;
        BinaryTreeNode *parent;
        int initialCapacity;
        int capacity;
        int binNumber;
        int depth;
};
