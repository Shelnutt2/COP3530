/*
Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#include <RatinMaze.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#ifdef Debug
#define dprint printf
#endif
//Macro for search canceled
#define cancled printf("Search canceled \n");

using namespace std;

RatInMaze::RatInMaze(){ //Initialize class
        Stack = new stack(1);
        Queue = new queue(1);
        currentPOS[0] = -1;
        currentPOS[1] = -1;
}

int RatInMaze::computeCord(int x, int y){ //We need to create an interger representation
                                          //of the 2d coordinates to be stored in the
                                          // arraylist which holds only ints.
    if(y == 0)
        return x;
    else if (x == 0)
        return y * 15;
    else
        return (y * 15) + x;

}

int RatInMaze::computeXCord(int w){ //Get X coordinate from intger representation of coordinates
    if (w < 0)
        return -1;
    else
        return w - ((w / 15) * 15);
}

int RatInMaze::computeYCord(int w){ //Get Y coordinate from intger representation of coordinates
    if (w < 0)
        return -1;
    else
        return w / 15;
}

bool RatInMaze::searchStack(int fromX,int fromY,int toX,int toY){ //Stack search
    if(!inMaze("Starting",fromX, fromY)){ 
        cancled;
        return false;
    }
    else if(!inMaze("Ending",toX, toY)){
        cancled;
        return false;
    }
    currentPOS[0] = fromX;
    currentPOS[1] = fromY;
    maze.maze[currentPOS[1]][currentPOS[0]] = '2';
    globalcounter = 0;
    perfcounter = 0;
    Stack->push(computeCord(currentPOS[0],currentPOS[1]));
    bool finished = false;
    while(!finished){
        currentPOS[0] = computeXCord(*Stack->top());
        currentPOS[1] = computeYCord(*Stack->top());
         //Try moving right
        if(((currentPOS[0] + 1) < maze.columns) && maze.maze[currentPOS[1]][(currentPOS[0] + 1)] == '0'){
            currentPOS[0] = currentPOS[0]+1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
         //Try moving down
        else if(!((currentPOS[1] + 1) >= maze.rows) && maze.maze[(currentPOS[1]+1)][currentPOS[0]] == '0'){
            currentPOS[1] = currentPOS[1]+1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
         //Try moving left
        else if(!((currentPOS[0] - 1) < 0 ) && maze.maze[currentPOS[1]][(currentPOS[0] - 1)] == '0'){
            currentPOS[0] = currentPOS[0]-1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
         //Try moving up
        else if(!((currentPOS[1] - 1) < 0 ) && maze.maze[(currentPOS[1]-1)][currentPOS[0]] == '0'){
            currentPOS[1] = currentPOS[1]-1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
        else{
            Stack->pop();
            perfcounter--;
        }
        globalcounter++;
        if((currentPOS[0] == toX) && (currentPOS[1] == toY))
            finished = true;
    }
    return true;
}

bool RatInMaze::searchQueue(int fromX,int fromY,int toX,int toY){
    if(!inMaze("Starting",fromX, fromY)){ //Check to make sure the start and end is inside the maze
        cancled;
        return false;
    }
    else if(!inMaze("Ending",toX, toY)){
        cancled;
        return false;
    }

    currentPOS[0] = fromX;
    currentPOS[1] = fromY;
    maze.maze[currentPOS[1]][currentPOS[0]] = '2';

    globalcounter = 0;
    perfcounter = 0;
    Queue->push(computeCord(currentPOS[0],currentPOS[1]));
    bool finished = false;
    while(!finished){
        currentPOS[0] = computeXCord(*Queue->front());
        currentPOS[1] = computeYCord(*Queue->front());
        if((currentPOS[0] == toX) && (currentPOS[1] == toY)){
            finished = true;
            break; 
        }
         //Try moving right
        if(((currentPOS[0] + 1) < maze.columns) && maze.maze[currentPOS[1]][(currentPOS[0] + 1)] == '0'){
            maze.maze[currentPOS[1]][currentPOS[0]+1] = '2';
            Queue->push(computeCord(currentPOS[0]+1,currentPOS[1]));
            perfcounter++;
        }
         //Try moving down
        if(!((currentPOS[1] + 1) >= maze.rows) && maze.maze[(currentPOS[1]+1)][currentPOS[0]] == '0'){
            maze.maze[currentPOS[1]+1][currentPOS[0]] = '2';
            Queue->push(computeCord(currentPOS[0],currentPOS[1]+1));
            perfcounter++;
        }
         //Try moving left
        if(!((currentPOS[0] - 1) < 0 ) && maze.maze[currentPOS[1]][(currentPOS[0] - 1)] == '0'){
            maze.maze[currentPOS[1]][currentPOS[0]-1] = '2';
            Queue->push(computeCord(currentPOS[0]-1,currentPOS[1]));
            perfcounter++;
        }
         //Try moving up
        if(!((currentPOS[1] - 1) < 0 ) && maze.maze[(currentPOS[1]-1)][currentPOS[0]] == '0'){
            maze.maze[currentPOS[1]-1][currentPOS[0]] = '2';
            Queue->push(computeCord(currentPOS[0],currentPOS[1]-1));
            perfcounter++;
        }
        else{
            Queue->pop();
            perfcounter--;
        }
        globalcounter++;
    }
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
    currentPOS[0] = fromX; //Get the current position
    currentPOS[1] = fromY; //Get the current position
    maze.maze[currentPOS[1]][currentPOS[0]] = '2'; //Set the initial position to be '2'
    globalcounter = 0;
    perfcounter = 0;
    Stack->push(computeCord(currentPOS[0],currentPOS[1])); //Push the start position to the stack
    bool finished = false;
    while(!finished){
        currentPOS[0] = computeXCord(*Stack->top());
        currentPOS[1] = computeYCord(*Stack->top());

        if((toY - currentPOS[1]) > 0){ //See if we are closer to going up or down
            if(!((currentPOS[1] + 1) >= maze.rows) && maze.maze[(currentPOS[1]+1)][currentPOS[0]] == '0'){
                currentPOS[1] = currentPOS[1]+1;
                maze.maze[currentPOS[1]][currentPOS[0]] = '2';
                Stack->push(computeCord(currentPOS[0],currentPOS[1]));
                perfcounter++;
            }
        }
        else if((toY - currentPOS[1]) < 0){//See if we are closer to going up or down
            if(!((currentPOS[1] - 1) < 0 ) && maze.maze[(currentPOS[1]-1)][currentPOS[0]] == '0'){
                currentPOS[1] = currentPOS[1]-1;
                maze.maze[currentPOS[1]][currentPOS[0]] = '2';
                Stack->push(computeCord(currentPOS[0],currentPOS[1]));
                perfcounter++;
            }
        }
        else if((toX - currentPOS[0]) > 0){//See if we are closer to going lefr or right
            if(((currentPOS[0] + 1) < maze.columns) && maze.maze[currentPOS[1]][(currentPOS[0] + 1)] == '0'){
                currentPOS[0] = currentPOS[0]+1;
                maze.maze[currentPOS[1]][currentPOS[0]] = '2';
                Stack->push(computeCord(currentPOS[0],currentPOS[1]));
                perfcounter++;
            }
        }
        else if((toX - currentPOS[0]) < 0){//See if we are closer to going lefr or right
            if(!((currentPOS[0] - 1) < 0 ) && maze.maze[currentPOS[1]][(currentPOS[0] - 1)] == '0'){
                currentPOS[0] = currentPOS[0]-1;
                maze.maze[currentPOS[1]][currentPOS[0]] = '2';
                Stack->push(computeCord(currentPOS[0],currentPOS[1]));
                perfcounter++;
            }
        }
         //Try normal if none of the above cases work
         //Try moving right
        if(((currentPOS[0] + 1) < maze.columns) && maze.maze[currentPOS[1]][(currentPOS[0] + 1)] == '0'){
            currentPOS[0] = currentPOS[0]+1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
         //Try moving down
        else if(!((currentPOS[1] + 1) >= maze.rows) && maze.maze[(currentPOS[1]+1)][currentPOS[0]] == '0'){
            currentPOS[1] = currentPOS[1]+1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
         //Try moving left
        else if(!((currentPOS[0] - 1) < 0 ) && maze.maze[currentPOS[1]][(currentPOS[0] - 1)] == '0'){
            currentPOS[0] = currentPOS[0]-1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
         //Try moving up
        else if(!((currentPOS[1] - 1) < 0 ) && maze.maze[(currentPOS[1]-1)][currentPOS[0]] == '0'){
            currentPOS[1] = currentPOS[1]-1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
        else{
            Stack->pop();
            perfcounter--;
        }
        globalcounter++;
        if((currentPOS[0] == toX) && (currentPOS[1] == toY))
            finished = true;
    }
    return true;
}

void RatInMaze::load(char inMaze[13][15], int rows, int columns){ //Load the Maze
    int i=0,j=0;
    for(i=0;i<13;i++){
        for(j=0;j<15;j++){
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
            for(j=0;j<15;j++){
                printf("%c",maze.maze[i][j]);
            }
            printf("\n");
        }
    printf("I've travelled through %d square(s). The path contains %d square(s)\n",globalcounter,perfcounter);
    printf("\n\n");
    }
}

bool RatInMaze::inMaze(string point, int X, int Y){
    if((X > maze.columns || X < 0) || (Y > maze.rows || Y < 0)){
        printf("%s point is not inside the maze!\n",point.c_str());
        return false;
    }

    else
        return true;
}
