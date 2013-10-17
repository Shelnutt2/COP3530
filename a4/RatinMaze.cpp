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

#if 1
#define dprint 
#endif

#define cancled printf("Search canceled \n");

using namespace std;

RatInMaze::RatInMaze(){
        Stack = new stack(128);
        Queue = new queue(2);
        currentPOS[0] = -1;
        currentPOS[1] = -1;
}

int computeCord(int x, int y){
    if(y == 0)
        return x;
    else if (x == 0)
        return y * 15;
    else
        return (y * 15) + x;

}

int computeXCord(int w){
    if (w < 0)
        return -1;
    else
        return w - ((w / 15) * 15);
}

int computeYCord(int w){
    if (w < 0)
        return -1;
    else
        return w / 15;
}

bool RatInMaze::searchStack(int fromX,int fromY,int toX,int toY){
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
    dprint("Stack size is: %d\n", Stack->size());
    Stack->push(computeCord(currentPOS[0],currentPOS[1]));
    dprint("Stack size is: %d\n", Stack->size());
    bool finished = false;
    while(!finished){
        currentPOS[0] = computeXCord(*Stack->top());
        currentPOS[1] = computeYCord(*Stack->top());
         //Try moving right
        if(((currentPOS[0] + 1) < maze.columns) && maze.maze[currentPOS[1]][(currentPOS[0] + 1)] == '0'){
            dprint("Moving right\n");
            currentPOS[0] = currentPOS[0]+1;
            dprint("currentPOS[0]: %d\n",currentPOS[0]);
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
         //Try moving down
        else if(!((currentPOS[1] + 1) >= maze.rows) && maze.maze[(currentPOS[1]+1)][currentPOS[0]] == '0'){
            dprint("Moving down\n");
            currentPOS[1] = currentPOS[1]+1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
         //Try moving left
        else if(!((currentPOS[0] - 1) < 0 ) && maze.maze[currentPOS[1]][(currentPOS[0] - 1)] == '0'){
            dprint("Moving left\n");
            currentPOS[0] = currentPOS[0]-1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
         //Try moving up
        else if(!((currentPOS[1] - 1) < 0 ) && maze.maze[(currentPOS[1]-1)][currentPOS[0]] == '0'){
            dprint("Moving up\n");
            currentPOS[1] = currentPOS[1]-1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
        else{
            dprint("Popping\n");
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
    dprint("Queue size is: %d\n", Queue->size());
    Queue->push(computeCord(currentPOS[0],currentPOS[1]));
    dprint("Queue size is: %d\n", Queue->size());
    bool finished = false;
    while(!finished){
        currentPOS[0] = computeXCord(*Queue->front());
        currentPOS[1] = computeYCord(*Queue->front());
         //Try moving right
        if(((currentPOS[0] + 1) < maze.columns) && maze.maze[currentPOS[1]][(currentPOS[0] + 1)] == '0'){
            dprint("Moving right\n");
            currentPOS[0] = currentPOS[0]+1;
            dprint("currentPOS[0]: %d\n",currentPOS[0]);
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Queue->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
         //Try moving down
        if(!((currentPOS[1] + 1) >= maze.rows) && maze.maze[(currentPOS[1]+1)][currentPOS[0]] == '0'){
            dprint("Moving down\n");
            currentPOS[1] = currentPOS[1]+1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Queue->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
         //Try moving left
        if(!((currentPOS[0] - 1) < 0 ) && maze.maze[currentPOS[1]][(currentPOS[0] - 1)] == '0'){
            dprint("Moving left\n");
            currentPOS[0] = currentPOS[0]-1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Queue->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
         //Try moving up
        if(!((currentPOS[1] - 1) < 0 ) && maze.maze[(currentPOS[1]-1)][currentPOS[0]] == '0'){
            dprint("Moving up\n");
            currentPOS[1] = currentPOS[1]-1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Queue->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
        else{
            dprint("Popping\n");
            Queue->pop();
            perfcounter--;
        }
        globalcounter++;
        if((currentPOS[0] == toX) && (currentPOS[1] == toY))
            finished = true;
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
    currentPOS[0] = fromX;
    currentPOS[1] = fromY;
    maze.maze[currentPOS[1]][currentPOS[0]] = '2';
    globalcounter = 0;
    perfcounter = 0;
    dprint("Stack size is: %d\n", Stack->size());
    Stack->push(computeCord(currentPOS[0],currentPOS[1]));
    dprint("Stack size is: %d\n", Stack->size());
    bool finished = false;
    while(!finished){
        currentPOS[0] = computeXCord(*Stack->top());
        currentPOS[1] = computeYCord(*Stack->top());

        if((toY - currentPOS[1]) > 0)
            if(!((currentPOS[1] + 1) >= maze.rows) && maze.maze[(currentPOS[1]+1)][currentPOS[0]] == '0'){
                dprint("Moving down\n");
                currentPOS[1] = currentPOS[1]+1;
                maze.maze[currentPOS[1]][currentPOS[0]] = '2';
                Stack->push(computeCord(currentPOS[0],currentPOS[1]));
                perfcounter++;
            }
        else if((toY - currentPOS[1]) < 0)
            if(!((currentPOS[1] - 1) < 0 ) && maze.maze[(currentPOS[1]-1)][currentPOS[0]] == '0'){
                dprint("Moving up\n");
                currentPOS[1] = currentPOS[1]-1;
                maze.maze[currentPOS[1]][currentPOS[0]] = '2';
                Stack->push(computeCord(currentPOS[0],currentPOS[1]));
                perfcounter++;
        }
        else if((toX - currentPOS[0]) > 0)
            if(((currentPOS[0] + 1) < maze.columns) && maze.maze[currentPOS[1]][(currentPOS[0] + 1)] == '0'){
                dprint("Moving right\n");
                currentPOS[0] = currentPOS[0]+1;
                dprint("currentPOS[0]: %d\n",currentPOS[0]);
                maze.maze[currentPOS[1]][currentPOS[0]] = '2';
                Stack->push(computeCord(currentPOS[0],currentPOS[1]));
                perfcounter++;
        }

        else if((toX - currentPOS[0]) < 0)
            if(!((currentPOS[0] - 1) < 0 ) && maze.maze[currentPOS[1]][(currentPOS[0] - 1)] == '0'){
                dprint("Moving left\n");
                currentPOS[0] = currentPOS[0]-1;
                maze.maze[currentPOS[1]][currentPOS[0]] = '2';
                Stack->push(computeCord(currentPOS[0],currentPOS[1]));
                perfcounter++;
            }


         //Try moving right
        if(((currentPOS[0] + 1) < maze.columns) && maze.maze[currentPOS[1]][(currentPOS[0] + 1)] == '0'){
            dprint("Moving right\n");
            currentPOS[0] = currentPOS[0]+1;
            dprint("currentPOS[0]: %d\n",currentPOS[0]);
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
         //Try moving down
        else if(!((currentPOS[1] + 1) >= maze.rows) && maze.maze[(currentPOS[1]+1)][currentPOS[0]] == '0'){
            dprint("Moving down\n");
            currentPOS[1] = currentPOS[1]+1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
         //Try moving left
        else if(!((currentPOS[0] - 1) < 0 ) && maze.maze[currentPOS[1]][(currentPOS[0] - 1)] == '0'){
            dprint("Moving left\n");
            currentPOS[0] = currentPOS[0]-1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
         //Try moving up
        else if(!((currentPOS[1] - 1) < 0 ) && maze.maze[(currentPOS[1]-1)][currentPOS[0]] == '0'){
            dprint("Moving up\n");
            currentPOS[1] = currentPOS[1]-1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
        }
        else{
            dprint("Popping\n");
            Stack->pop();
            perfcounter--;
        }
        globalcounter++;
        if((currentPOS[0] == toX) && (currentPOS[1] == toY))
            finished = true;
    }
    return true;

#if 0
    enum{
        RIGHT = 1,
        DOWN = 2,
        LEFT = 3,
        UP = 4
    } direction;

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
    dprint("Stack size is: %d\n", Stack->size());
    Stack->push(computeCord(currentPOS[0],currentPOS[1]));
    dprint("Stack size is: %d\n", Stack->size());
    bool finished = false;
    int d = UP;
    while(!finished){
        currentPOS[0] = computeXCord(*Stack->top());
        currentPOS[1] = computeYCord(*Stack->top());
        if((toY - currentPOS[1]) > 0)
            if(!((currentPOS[1] + 1) >= maze.rows) && maze.maze[(currentPOS[1]+1)][currentPOS[0]] == '0')
                d=DOWN;
            else
                continue;
        else if((toY - currentPOS[1]) < 0)
            if(!((currentPOS[1] - 1) < 0 ) && maze.maze[(currentPOS[1]-1)][currentPOS[0]] == '0')
                d=UP;
            else
                continue;
        else
            if((toX - currentPOS[0]) > 0)
                if(((currentPOS[0] + 1) < maze.columns) && maze.maze[currentPOS[1]][(currentPOS[0] + 1)] == '0')
                    d=RIGHT;
                else
                    continue;
            else if((toX - currentPOS[0]) < 0)
                if(!((currentPOS[0] - 1) < 0 ) && maze.maze[currentPOS[1]][(currentPOS[0] - 1)] == '0')
                    d=LEFT;
                else
                    continue;
        
        switch(d){
         //Try moving right
        //if(((currentPOS[0] + 1) < maze.columns) && maze.maze[currentPOS[1]][(currentPOS[0] + 1)] == '0'){
        case RIGHT:{
            dprint("Moving right\n");
            currentPOS[0] = currentPOS[0]+1;
            dprint("currentPOS[0]: %d\n",currentPOS[0]);
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
            break;
        }
         //Try moving down
        //else if(!((currentPOS[1] + 1) >= maze.rows) && maze.maze[(currentPOS[1]+1)][currentPOS[0]] == '0'){
        case DOWN:{
            dprint("Moving down\n");
            currentPOS[1] = currentPOS[1]+1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
            break;
        }
         //Try moving left
//        else if(!((currentPOS[0] - 1) < 0 ) && maze.maze[currentPOS[1]][(currentPOS[0] - 1)] == '0'){
        case LEFT:{
            dprint("Moving left\n");
            currentPOS[0] = currentPOS[0]-1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
            break;
        }
         //Try moving up
//        else if(!((currentPOS[1] - 1) < 0 ) && maze.maze[(currentPOS[1]-1)][currentPOS[0]] == '0'){
        case UP:{
            dprint("Moving up\n");
            currentPOS[1] = currentPOS[1]-1;
            maze.maze[currentPOS[1]][currentPOS[0]] = '2';
            Stack->push(computeCord(currentPOS[0],currentPOS[1]));
            perfcounter++;
            break;
        }
        default:{
            //Try moving right
            if(((currentPOS[0] + 1) < maze.columns) && maze.maze[currentPOS[1]][(currentPOS[0] + 1)] == '0'){
                dprint("Moving right\n");
                currentPOS[0] = currentPOS[0]+1;
                dprint("currentPOS[0]: %d\n",currentPOS[0]);
                maze.maze[currentPOS[1]][currentPOS[0]] = '2';
                Stack->push(computeCord(currentPOS[0],currentPOS[1]));
                perfcounter++;
            }
            //Try moving down
            else if(!((currentPOS[1] + 1) >= maze.rows) && maze.maze[(currentPOS[1]+1)][currentPOS[0]] == '0'){
                dprint("Moving down\n");
                currentPOS[1] = currentPOS[1]+1;
                maze.maze[currentPOS[1]][currentPOS[0]] = '2';
                Stack->push(computeCord(currentPOS[0],currentPOS[1]));
                perfcounter++;
            }
            //Try moving left
            else if(!((currentPOS[0] - 1) < 0 ) && maze.maze[currentPOS[1]][(currentPOS[0] - 1)] == '0'){
                dprint("Moving left\n");
                currentPOS[0] = currentPOS[0]-1;
                maze.maze[currentPOS[1]][currentPOS[0]] = '2';
                Stack->push(computeCord(currentPOS[0],currentPOS[1]));
                perfcounter++;
            }
            //Try moving up
            else if(!((currentPOS[1] - 1) < 0 ) && maze.maze[(currentPOS[1]-1)][currentPOS[0]] == '0'){
                dprint("Moving up\n");
                currentPOS[1] = currentPOS[1]-1;
                maze.maze[currentPOS[1]][currentPOS[0]] = '2';
                Stack->push(computeCord(currentPOS[0],currentPOS[1]));
                perfcounter++;
            }
            else{
                dprint("Popping\n");
                Stack->pop();
                perfcounter--;
            }
        }
    }
        globalcounter++;
        if((currentPOS[0] == toX) && (currentPOS[1] == toY))
            finished = true;
    }
    return true;
#endif
}

void RatInMaze::load(char inMaze[13][15], int rows, int columns){
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
