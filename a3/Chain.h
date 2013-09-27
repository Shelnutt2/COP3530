/*
Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#include "Linearlist.h"
#include "ChainNode.h"


using namespace std;

class chain : public linearList
{
   public:
      chain();
      chain(int initialCapacity);
      ~chain();
      virtual int* get(int theIndex) const;
      virtual int indexOf(const int& theElement)const;
      virtual void erase(int theIndex);
      virtual void insert(int theIndex,
                          const int& theElement);
      virtual void traverse();
      virtual void MaxMin();

      virtual bool empty() const {return listSize == 0;}
      virtual int size() const {return listSize;}

   protected:
      void checkIndex(int theIndex) const;
      chainNode* firstNode; 
      int listSize;          
};
