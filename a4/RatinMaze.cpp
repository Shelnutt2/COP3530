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
#define dprint printf
#endif

#define cancled printf("Search canceled \n");

using namespace std;

RatInMaze::RatInMaze(){
        Stack = new stack(10);
        Queue = new queue(10);
        currentPOS[0] = -1;
        currentPOS[1] = -1;
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
    if(currentPOS[0] == -1 || currentPOS[1] == -1){
        currentPOS[0] = fromX;
        currentPOS[1] = fromY;
    }
    dprint("Stack size is: %d\n", Stack->size());
    Stack->push((int)(intptr_t)currentPOS);
    dprint("Stack size is: %d\n", Stack->size());
#if 0

    dprint("Original is: %ld \n", currentPOS[1]);
    dprint("Original is: %ld \n", currentPOS);
    intptr_t test = ((intptr_t)currentPOS);
    dprint("Middle is: %lu \n", ((int*)test));
    int test2 = ((int)(intptr_t)currentPOS);
    dprint("Hack is: %d \n", ((int*)test2));
    dprint("Hack is: %d \n", ((int*)test2)[0]);
    intptr_t t = ((intptr_t)((Stack->top())[0]));
    dprint("T is: %d \n", t);
    dprint("T[0] is: %d \n", ((intptr_t*)t)[0]);
    dprint("T[1] is: %d \n", ((intptr_t*)t)[1]);
    intptr_t *ptr = ((intptr_t*)((Stack->top())[0]));
    dprint("ptr is: %d \n", ptr);
    dprint("ptr[0] is: %d \n", ptr[0]);
    dprint("ptr[1] is: %d \n", ptr[1]);
    dprint("Top Stack is: %d \n", (Stack->top())[0]);
    dprint("Top Stack is: %d \n", ((intptr_t*)((Stack->top())[0])));
#endif
    while(((intptr_t*)((Stack->top())[0]))[0] != toX && ((intptr_t*)((Stack->top())[0]))[1] != toY){
        size_t x[2];
        x[0] = ((uintptr_t*)((Stack->top())[0]))[0];
        x[1] = ((intptr_t*)((Stack->top())[0]))[1];
        dprint("current x is: %d, current y is: %d\n",x[0],x[1]);
        dprint("Columns are: %d\n",maze.columns);
        dprint("Rows are: %d\n",maze.rows);
        dprint("x[0] + 1 = %d\n",x[0]+1);
         //Try moving right
        if(((x[0] + 1) <= maze.columns) && maze.maze[x[1]][(x[0] + 1)] == '0'){
            printf("Moving right\n");
            x[0] = x[0]+1;
            maze.maze[x[1]][x[0]] = '2';
            Stack->push((int)(intptr_t)x);
            dprint("x is %d, y is %d\n",x[0],x[1]);
        }
         //Try moving down
        else if(!((x[1] + 1) > maze.rows) && maze.maze[(x[1]+1)][x[0]] == '0'){
            printf("Moving down\n");
            x[1] = x[1]+1;
            maze.maze[x[1]][x[0]] = '2';
            Stack->push((int)(intptr_t)x);
        }
         //Try moving left
        else if(!((x[0] - 1) < 0 ) && maze.maze[x[1]][(x[0] - 1)] == '0'){
            printf("Moving left\n");
            x[0] = x[0]-1;
            maze.maze[x[1]][x[0]] = '2';
            Stack->push((int)(intptr_t)x);
        }
         //Try moving up
        else if(!((x[1] - 1) < 0 ) && maze.maze[(x[1]-1)][x[0]] == '0'){
            printf("Moving up\n");
            x[1] = x[1]-1;
            maze.maze[x[1]][x[0]] = '2';
            Stack->push((int)(intptr_t)x);
        }
        else{
            printf("Popping\n");
            Stack->pop();
        }
        dprint("x : %d\n",x);
        intptr_t *test = (intptr_t*)(Stack->top());
        dprint("test : %lu\n",test[0]);
        size_t ptr = ((size_t*)(Stack->top()))[0];
        dprint("ptr : %lu\n",ptr);
//       intptr_t *test3 = ((Stack->top()))[0];
        dprint("test3 : %lu\n",((intptr_t*)((Stack->top())[0]))[0]);
        printf("new x is: %d, new y is: %d\n", ((intptr_t*)((Stack->top())[0]))[0],((intptr_t*)((Stack->top())[0]))[1]);
        RatInMaze::print(true);
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
    printf("\n\n");
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
