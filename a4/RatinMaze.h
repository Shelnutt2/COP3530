/*
Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

using namespace std; 

#ifndef _stack //Make sure we only include headers once
#define _stack
#include <stack.h>
#endif
#ifndef _queue
#define _queue
#include <queue.h>
#endif

#define COLUMNS = 13 //Define rows and columns for easy changing
#define ROWS = 15

struct Maze{ //Struct to keep the maze and information on the maze
   char maze[13][15];
   int rows;
   int columns;
};

class RatInMaze {
  private:
    Maze maze;
    stack* Stack;
    queue* Queue;
    int currentPOS[2];
    int globalcounter,perfcounter; //Performance counters
    int computeCord(int x, int y); //Computer 1d array location based on maze
    int computeXCord(int w); //Computer X cordinate from 1d coordinate array
    int computeYCord(int w); //Computer Y cordinate from 1d coordinate array

  public:
    RatInMaze();
    bool searchStack(int fromX,int fromY,int toX,int toY); //Stack Search
    bool searchQueue(int fromX,int fromY,int toX,int toY); //Queue based search
    bool searchStackSmart(int fromX,int fromY,int toX,int toY); //Smart Search
    void load(char inMaze[13][15], int rows, int columns); //Load the maze
    void print(bool done); //Function to print the finished maze
    bool inMaze(string point, int X, int Y); //Make sure a point is in the maze

};
