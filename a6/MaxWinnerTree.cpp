/*Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#ifndef _MaxWinnerTree
#define _MaxWinnerTree
#include <MaxWinnerTree.h>
#endif

#ifndef _BinaryTree
#define _BinaryTree
#include <BinaryTree.h>
#endif

#ifndef _cstddef
#define _cstddef
#include <cstddef>
#endif

#include <stdio.h>
using namespace std;

MaxWinnerTree::MaxWinnerTree(int *object, int numberofObjects){
            binTree = new BinaryTree();
            initialize(object, numberofObjects);
}

MaxWinnerTree::MaxWinnerTree(int *object, int numberofObjects, int binCapacity){
            binTree = new BinaryTree();
            binTree->root->capacity = binCapacity;
            binTree->root->initialCapacity = binCapacity;
            binTree->root->binNumber = 1;
//            binTree->setCapacity(binTree->root,binCapacity);
  //          binTree->setinitialCapacity(binTree->root,binCapacity);
    //        binTree->setbinNumber(binTree->root,1);
            //initialize(object, numberofObjects);
}

void MaxWinnerTree::initialize(int* object, int numberofObjects){
    int i;
    for(i = 0;i<numberofObjects;i++){
//        printf("Pack object %d in bin %d\n", i+1, i+1);
        if(binTree->treeSize == 1){
            if(binTree->root->capacity >= object[i]){

            }
        }
    }
}

BinaryTreeNode* MaxWinnerTree::play(int objectSize){

        if(binTree->treeSize == 1){
            if(binTree->root->capacity >= objectSize){
                return binTree->root;
            }
        
            else{
                BinaryTreeNode* newNode = new BinaryTreeNode();
                newNode->initialCapacity=binTree->root->initialCapacity;
                newNode->binNumber = treeSize+1;
                binTree->add(newNode);
                return newNode;
            }
        }
        else{
            BinaryTreeNode* newNode = binTree->findLessObject(binTree->root,objectSize);
            if(newNode == NULL){
                newNode = new BinaryTreeNode();
                newNode->initialCapacity=binTree->root->initialCapacity;
                newNode->binNumber = binTree->treeSize+1;
                binTree->add(newNode);
                return newNode;
            }
            else
                return newNode;
        }
    
}

/*







//    int n = numberofObjects;
// Create winner tree for thePlayer[1:numberOfPlayers].
    int n = numberofObjects;
    if (n < 2)
        throw illegalParameterValue("must have at least 2 players");

    player = thePlayer;
    numberOfPlayers = n;
    delete [] tree;
    tree = new int [n];

    // compute  s = 2^log (n-1)
    int i, s;
    for (s = 1; 2 * s <= n - 1; s += s);

    lowExt = 2 * (n - s);
    offset = 2 * s - 1;

    // play matches for lowest-level external nodes
    for (i = 2; i <= lowExt; i += 2)
        play((offset + i) / 2, i - 1, i);

    // handle remaining external nodes
    if (n % 2 == 1)
    {// special case for odd n, play internal and exteral node
        play(n/2, tree[n - 1], lowExt + 1);
        i = lowExt + 3;
    }
    else i = lowExt + 2;

    // i is left-most remaining external node
    for (; i <= n; i += 2)
        play((i - lowExt + n - 1) / 2, i - 1, i);
}

void MaxWinnerTree::play(int p, int leftChild, int rightChild)
{// play matches beginning at tree[p]
 // leftChild is left child of p
 // rightChild is right child of p

    tree[p] = (player[leftChild] <= player[rightChild]) ? leftChild : rightChild;

    // more matches possible if at right child
    while (p % 2 == 1 && p > 1)
    {// at a right child
        tree[p / 2] = (player[tree[p - 1]] <= player[tree[p]]) ? tree[p - 1] : tree[p];
        p /= 2;  // go to parent
    }
}

void MaxWinnerTree::rePlay(int thePlayer)
{// Replay matches for player thePlayer.
    int n = numberOfPlayers;
    if (thePlayer <= 0 || thePlayer > n)
        throw illegalParameterValue("Player index is illegal");

    int matchNode; // node where next match is to be played
    int leftChild; // left child of matchNode
    int rightChild; // right child of matchNode

    // find first match node and its children
    if (thePlayer <= lowExt)
    {// begin at lowest level
        matchNode = (offset + thePlayer) / 2;
        leftChild = 2 * matchNode - offset;
        rightChild = leftChild + 1;
    }
    else
    {
        matchNode = (thePlayer - lowExt + n - 1) / 2;
        if (2 * matchNode == n - 1)
        {
            leftChild = tree[2 * matchNode];
            rightChild = thePlayer;
        }
        else
        {
            leftChild = 2 * matchNode - n + 1 + lowExt;
            rightChild = leftChild + 1;
        }
    }

    tree[matchNode] = (player[leftChild] <= player[rightChild]) ? leftChild : rightChild;

    // special case for second match
    if (matchNode == n - 1 && n % 2 == 1)
    {
        matchNode /= 2;   // move to parent
        tree[matchNode] = (player[tree[n - 1]] <= player[lowExt + 1]) ? tree[n - 1] : lowExt + 1;
    }

    // play remaining matches
    matchNode /= 2;  // move to parent
    for (; matchNode >= 1; matchNode /= 2)
        tree[matchNode] = (player[tree[2 * matchNode]] <= player[tree[2 * matchNode + 1]]) ? tree[2 * matchNode] : tree[2 * matchNode + 1];
}

void MaxWinnerTree::output() const
{
    cout << "number of players  = " << numberOfPlayers << endl
            << " lowExt = " << lowExt << endl
            << " offset = " << offset << endl;
    cout << "complete winner tree pointers are" << endl;
    for (int i = 1; i < numberOfPlayers; i++)
        cout << tree[i] << ' ';
    cout << endl;
}

*/
