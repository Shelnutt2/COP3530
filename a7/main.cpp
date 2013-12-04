/*Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _Dijkstras
#define _Dijkstras
#include <Dijkstras.h>
#endif

#ifndef _Graph
#define _Graph
#include <Graph.h>
#endif

using namespace std;

int main(){
  long int data;
  long int x = 0;
  Graph* graph;
//  Dijkstras* d = new Dijkstras();

  char buf[BUFSIZ]; //create a buffer with the defined buffer size
  char *c = NULL; //character used for checking to make sure user entered an integer


  while(1<2){ //Loop for input and computation until user wishes to quit
   printf("Please choose to what graph to use: 1. Prebuilt, 2. Input new graph, 3. Quit? "); //ask for user input

   if (fgets(buf, sizeof(buf), stdin) != NULL) //get user input and store in buffer
   {
    x = strtol(buf, &c, 10); //convert to long

    if (buf[0] != '\n' && (*c == '\n' || *c == '\0')){ //check to make sure user actually entered a value and that value is an integer
      switch(x){

      case 1:{
        data = 0;
        break;
      }
      case 2:{
        data = 1;
        break;
      }
      case 3:{
        return 0;
      }
      default:{
        printf("Please enter only a valid selection, 1,2 or 3\n");
        break;
      }

      }
    }
   }
    if(data == 0 || data == 1)
        break;
 }
    if(data == 1){
#if 0
  int i = 0;
   printf("Enter number of objects and bin capacity for %s\n",algorithmName); //ask for user input
  while(i<2){ //Loop for input and computation until user wishes to quit

   if (fgets(buf, sizeof(buf), stdin) != NULL) //get user input and store in buffer
   {
    x = strtol(buf, &c, 10); //convert to long
    if (buf[0] != '\n' && (*c == '\n' || *c == '\0')){ 
      if(i == 0) // 
         numObjects = x;
      else if(i == 1)
         binCap = x;
    i++;
    }
   }
  }

  oArray = new int[numObjects];
  for(i = 0; i<numObjects;i++){
  printf("Enter space requirement of object %d\n", i+1); //ask for user input
   if (fgets(buf, sizeof(buf), stdin) != NULL) //get user input and store in buffer
   {
    x = strtol(buf, &c, 10); //convert to long

    if (buf[0] != '\n' && (*c == '\n' || *c == '\0')){ //check to make sure user actually entered a value and that value is an integer
      oArray[i] = x;
    }
   }

  }
#endif
    }
    else{
        Vertex* vertex1 = new Vertex();
        Vertex* vertex2 = new Vertex();
        Vertex* vertex3 = new Vertex();
        Vertex* vertex4 = new Vertex();
        Vertex* vertex5 = new Vertex();
        Vertex* vertex6 = new Vertex();
        vertex1->id = 1;
        vertex2->id = 2;
        vertex3->id = 3;
        vertex4->id = 4;
        vertex5->id = 5;
        vertex6->id = 6;
        vertex1->addConnection(new link(vertex2,10));
        vertex1->addConnection(new link(vertex4,30));
        vertex1->addConnection(new link(vertex5,100));

        vertex2->addConnection(new link(vertex3,50));

        vertex3->addConnection(new link(vertex5,10));
        vertex3->addConnection(new link(vertex6,5));

        vertex4->addConnection(new link(vertex3,20));
        vertex4->addConnection(new link(vertex6,15));

        vertex5->addConnection(new link(vertex4,60));
        Vertex *vertexArray[6] = {vertex1,vertex2,vertex3,vertex4,vertex5,vertex6};
        graph = new Graph(vertex1,vertexArray,6);
        Dijkstras(graph);

    }
}
