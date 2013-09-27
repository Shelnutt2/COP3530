/*
Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#include "ChainNode.h"

using namespace std; 

chainNode::chainNode(chainNode *a, int b)
{
  next = a; //Set the point to the next chain
  element = b; //Set the element
}

