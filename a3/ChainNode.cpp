#include "ChainNode.h"

using namespace std; 



chainNode::chainNode(chainNode *a, int b)
{
  next = a;
  element = b;

}

