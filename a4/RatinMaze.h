/*
Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

using namespace std; 

#ifndef _stack
#define _stack
#include <stack.h>
#endif
#ifndef _queue
#define _queue
#include <queue.h>
#endif

struct Maze{
   char maze[13][15];
   int rows;
   int columns;
};

class RatInMaze {
  private:
    Maze maze;
    stack* Stack;
    queue* Queue;
    size_t currentPOS[2];
  public:
    RatInMaze();
    bool searchStack(int fromX,int fromY,int toX,int toY);
    bool searchQueue(int fromX,int fromY,int toX,int toY);
    bool searchStackSmart(int fromX,int fromY,int toX,int toY);
    void load(char inMaze[13][15], int rows, int columns);
    void print(bool done);
    bool inMaze(string point, int X, int Y);

};
