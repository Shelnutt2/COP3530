/*
Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#include <list>
#include <iostream>
#include <algorithm>
#include <stdlib.h>

#ifndef exceptions
#define exceptions
#include <exceptions.h>
#endif

using namespace std;

template<class T> class ArrayLinearList : public std::list<T>
{
  private:
    std::list<T> L; //private list

  public:
    ArrayLinearList(); //Constructor
    ArrayLinearList(T a, T b); //Constructor
    ArrayLinearList(T a[], uint size); //Constructor
    void insert(uint i, T a); //insert method
    void del(uint i); //delete method
    void printall(); //print all elements
    void print(uint i); //print single element
    uint size(); //get size
    T *minmax(); //get the minimum and the maximum
    T *min(); //get the minimum
    T *max(); //get the maximum
};

template <class T> ArrayLinearList<T>::ArrayLinearList()
{
  
}

template <class T> ArrayLinearList<T>::ArrayLinearList(T a, T b)
{
  std::list<T> L = std::list<T>(a,b); //initalize the list
}

template <class T> ArrayLinearList<T>::ArrayLinearList(T a[], uint size)
{
 std::list<T> L = std::list<T>(a, a+size); //initialize the list
}

template <class T> void ArrayLinearList<T>::insert(uint i,T a)
{
  if(i > L.size()){ //check for if the index is out of bounds
    throw illegalIndex(); //throw exception if it is
  }
  typename list <T>::iterator it = L.begin(); //iterator to iterate through the list
  for(uint j = 0;j<i;j++)
    it++; //move the iterator to the position we want
  L.insert(it,a); //insert the element
  return;
}

template <class T> void ArrayLinearList<T>::del(uint i)
{
  if(i > L.size()){ //check for if the index is out of bounds
    throw illegalIndex(); //throw exception if it is
  }
  typename list<T>::iterator it = L.begin(); //iterator to iterate through the list
  for(uint a = 0;a<i;a++)
    it++; //move the iterator to the position we want
  L.erase(it); //delete the element
  return;
}

template <class T> void ArrayLinearList<T>::printall(void)
{
  for (typename std::list<T>::iterator it = L.begin(); it != L.end(); it++) //iterate through all elements
    std::cout << *it << ' '; //print them out
  std::cout << std::endl;
  return;
}

template <class T> void ArrayLinearList<T>::print(uint i)
{
  if(i > L.size()){ //check for if the index is out of bounds
    throw illegalIndex(); //throw exception if it is
  }
  typename list<T>::iterator it = L.begin();
  for(uint a = 0;a<i;a++)
    it++; //move the iterator to the position we want
  std::cout << *it << ' '; //print out element
  std::cout << std::endl;
  return;
}

template <class T> uint ArrayLinearList<T>::size()
{
  return L.size(); //return size of the list
}

template <class T> T *ArrayLinearList<T>::minmax()
{
  typename list<T>::iterator itmin = std::min_element(L.begin(), L.end()); //Find min element
  typename list<T>::iterator itmax = std::max_element(L.begin(), L.end()); //Find max element
  T* i = (int *)malloc(2); //pre-allocate the memory for array
  i[0] = *itmin;
  i[1] = *itmax;
  return i; //return the min and max in an array
}

template <class T> T *ArrayLinearList<T>::min() //return min element
{
  typename list<T>::iterator itmin = std::min_element(L.begin(), L.end());
  return *itmin;
}

template <class T> T *ArrayLinearList<T>::max() //return max element
{
  typename list<T>::iterator itmax = std::max_element(L.begin(), L.end());
  return *itmax;
}
