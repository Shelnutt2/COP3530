/*
Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#include <RatinMaze.h>
#include <string.h>
#include <stdio.h>

#define cancled printf("Search canceled \n");

using namespace std;

RatInMaze::RatInMaze(){
        Stack = new stack(1);
        Queue = new queue(1);
        currentPOS[0] = -1;
        currentPOS[1] = -1;
}

bool RatInMaze::searchStack(int fromX,int fromY,int toX,int toY){
    if(!inMaze("Starting",fromX, fromY)){
        cancled;
        return false
    }
    else if(!inMaze("Ending",toX, toY)){
        cancled;
        return false;
    }
    if(currentPOS[0] == -1 || currentPOS[1] == -1){
        currentPOS[0] = fromX;
        currentPOS[1] = fromY;
    }
    Stack->push(*currentPOS);
    while(Stack->top()[0] != toX && Stack->top()[1] != toY){
         int x[2] = {Stack->top()[0],Stack->top()[1]};
         //Try moving right
        if(!((x[0] + 1) > maze.columns) && maze.maze[(x[0] + 1)][x[1]] == 0){
            x[0] = x[0]+1;
            maze.maze[(x[0] + 1)][x[1]] = 2;
            Stack->push(*x);
        }
         //Try moving down
        else if(!((x[1] + 1) > maze.rows) && maze.maze[x[0]][(x[1]+1)] == 0){
            x[1] = x[1]+1;
            maze.maze[x[0]][(x[1]+1)] = 2;
            Stack->push(*x);
        }
         //Try moving left
        else if(!((x[0] - 1) < 0 ) && maze.maze[(x[0] - 1)][x[1]] == 0){
            x[0] = x[0]-1;
            maze.maze[(x[0] - 1)][x[1]] = 2;
            Stack->push(*x);
        }
         //Try moving up
        else if(!((x[1] - 1) < 0 ) && maze.maze[x[0]][(x[1]-1)] == 0){
            x[1] = x[1]-1;
            maze.maze[x[0]][(x[1]-1)] = 2;
            Stack->push(*x);
        }
        else{
            Stack->pop();
        }

    }
    return true;
}

bool RatInMaze::searchQueue(int fromX,int fromY,int toX,int toY){
    if(!inMaze("Starting",fromX, fromY)){
        cancled;
        return false;
    }
    else if(!inMaze("Ending",toX, toY)){
        cancled;
        return false;
    }

    else
        return true;
}

bool RatInMaze::searchStackSmart(int fromX,int fromY,int toX,int toY){
    if(!inMaze("Starting",fromX, fromY)){
        cancled;
        return false;
    }
    else if(!inMaze("Ending",toX, toY)){
        cancled;
        return false;
    }

    else
        return true;
}

void RatInMaze::load(char inMaze[13][15], int rows, int columns){
    int i=0,j=0;
    for(i=0;i<13;i++){
        for(j=0;j<13;j++){
            maze.maze[i][j] = inMaze[i][j];
        }
    }
    maze.rows = rows;
    maze.columns = columns;
    
}

void RatInMaze::print(bool done){
    if(done){
       //cout << maze.maze << endl;
    int i=0,j=0;
        for(i=0;i<13;i++){
            for(j=0;j<13;j++){
                printf("%c",maze.maze[i][j]);
            }
            printf("\n");
        }
    }
/*    else{
        cout << "Lost" << endl;
    }*/
}

bool RatInMaze::inMaze(string point, int X, int Y){
    if((X > maze.columns || X < 0) || (Y > maze.rows || Y < 0)){
        printf("%s point is not inside the maze!\n",point.c_str());
        return false;
    }

    else
        return true;
}
