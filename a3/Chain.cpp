/*
Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#include <iostream>
#include <sstream>
#include <Chain.h>
#include <Myexception.h>
#include <limits.h>

using namespace std; 

chain::chain(int initialCapacity = 10) //Create a new instance
{
   if (initialCapacity < 1) //Check for intialCapacity being less than 1 and throw exceptions
   {ostringstream s;
    s << "Initial capacity = " 
      << initialCapacity << " Must be > 0";
    throw illegalParameterValue(s.str());
   }
   firstNode = NULL; //First node is null
   listSize = 0;
}

chain::~chain() //Delete the chain
{
   while (firstNode != NULL) // Iterate through all chainnodes
   {
      chainNode* nextNode = firstNode->next;
      delete firstNode;
      firstNode = nextNode;
   }
}

void chain::checkIndex(int theIndex) const //Check if the index is greater than the number of eliminates
{

   	if (theIndex < 0 || theIndex >= listSize){
		ostringstream s;
    		s << "index = " << theIndex << " size = " 
                    << listSize<<", the input index is invalid";
    		throw illegalIndex(s.str());
	}
 
}

int* chain::get(int theIndex) const //Get an index element
{
   	try{
		checkIndex(theIndex);
	}
	catch(illegalIndex &e){
		e.outputMessage();
		return NULL;
	}

   chainNode* currentNode = firstNode; //Iterate through the chain till we arrive at the specified index
   for (int i = 0; i < theIndex; i++)
      currentNode = currentNode->next;
   return &currentNode->element;
}

int chain::indexOf(const int& theElement) const //Find first index of given element
{

   chainNode* currentNode = firstNode;
   int index = 0;
   while (currentNode != NULL && 
          currentNode->element != theElement) // Iterate through the elements
   {

      currentNode = currentNode->next;
      index++;
   }

   if (currentNode == NULL) //Not found
      return -1;
   else
      return index;
}

void chain::erase(int theIndex) //Method to delete a chainnode
{
      	try{
		checkIndex(theIndex); //Make sure that the index is inbounds
	}
	catch(illegalIndex &e){
		e.outputMessage();
		return;
	}

   chainNode* deleteNode;
   if (theIndex == 0) //If it's first, delete the first node.
   {
      deleteNode = firstNode;
      firstNode = firstNode->next;
   }

   else
   {
   chainNode* p = firstNode; // Loop through all the nodes
   for (int i = 0; i < theIndex - 1; i++)
      p = p->next;
   
   deleteNode = p->next;
   p->next = p->next->next; 
   }
   listSize--; //Reduce list size by one
   delete deleteNode;
}

void chain::insert(int theIndex, const int& theElement) //Insert an element
{
	try{
   		if (theIndex < 0 || theIndex > listSize) //Need a custom check here since the listSize can be 0
   		{
			ostringstream s;
    			s << "index = " << theIndex << " size = " 
                    		<< listSize<<", the input index is invalid";
    			throw illegalIndex(s.str());
		}
	}
	catch(illegalIndex &e){ //Catch the exception
		e.outputMessage();
		return;
	}
   

   if (theIndex == 0)
      firstNode = new chainNode(firstNode, theElement); //First Element
   else
   { //Iterate through the chain till we are at the prior index to the one we want.
      chainNode* p = firstNode;
      for (int i = 0; i < theIndex - 1; i++)
         p = p->next;

      p->next = new chainNode(p->next,theElement); //insert the chainnode
   }
   listSize++; //Increment the list size
}

void chain::traverse() //Print out the list
{
  	if(listSize==0){
    		cout<<"List is Empty"<<endl;
    		return;
  	}
        chainNode* p = firstNode; //Step through all chainnodes
        for (int i = 0; i < listSize; i++){
                cout<<p->element<<" ";
                p = p->next;
  	}
  	cout<<endl;
}

void chain::MaxMin(){ //Prints the min and max
	if(listSize==0){
    		cout<<"List is Empty"<<endl;
   	 return;
	}

	int max=INT_MIN;
	int min=INT_MAX;
        chainNode* p = firstNode;
	for (int i= 0; i<listSize;i++) {
		if(p->element>max)max=p->element;
		if(p->element<min)min=p->element;
                p = p->next;   		
  	}
	cout<<"The maximum element in the list is "<<max<<endl;
	cout<<"The minimum element in the list is "<<min<<endl;

}



