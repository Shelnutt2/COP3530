/*Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#ifndef _Dijkstras
#define _Dijkstras
#include <Dijkstras.h>
#endif

#ifndef _Graph
#define _Graph
#include <Graph.h>
#endif

using namespace std;


void existingGraph(){ //Prexisting graph

    aList alist(6); //Create a new adjacent graph

    alist[0].push_back(Vertex(1, 10)); //Set the links between vertexs
    alist[0].push_back(Vertex(3, 30));
    alist[0].push_back(Vertex(4, 100));

    alist[1].push_back(Vertex(0, 10));
    alist[1].push_back(Vertex(2, 50));

    alist[2].push_back(Vertex(1, 50));
    alist[2].push_back(Vertex(3, 20));
    alist[2].push_back(Vertex(4, 10));
    alist[2].push_back(Vertex(5, 5));

    alist[3].push_back(Vertex(0, 30));
    alist[3].push_back(Vertex(2, 20));
    alist[3].push_back(Vertex(4, 60));
    alist[3].push_back(Vertex(5, 15));

    alist[4].push_back(Vertex(0, 100));
    alist[4].push_back(Vertex(2, 10));
    alist[4].push_back(Vertex(3, 60));

    alist[5].push_back(Vertex(2, 15));
    alist[5].push_back(Vertex(3, 5));
 
    vector<double> min_distance; //Since we can implement this how we want, use vectors for resizable arrays
    vector<int> previous; 
    DijkstraPaths(0, alist, min_distance, previous); //Get all the paths and store the distances
    vector<double> min_distance_sorted = min_distance; //Copy the distance
    sort (min_distance_sorted.begin(), min_distance_sorted.end()); //Sort for output
    unsigned int i = 0;
    unsigned int j = 0;
    for(j=0;j<min_distance.size();j++){ //Loop through sorted min_distances
        for(i=0;i<min_distance.size();i++){ //Loop through unsorted distances
            if(min_distance_sorted[j] == min_distance[i]){ //Output in correct order
                cout << min_distance[i] << ": ";
                list<int> path = findShortestpath(i, previous); //Get the route
                list<int>::const_iterator it; //Iterator
                for(list<int>::iterator it=path.begin(); it != path.end(); ++it){ //Iterate through the path
                    cout << *it+1; //Print the path
                    if( *it != path.back())
                        printf(" -> ");
                }
                printf("\n");
            }
        }
    }
}

int main(){
#ifdef USER_INPUT //Toggle if we accept user input at compile time
  long int data;
  long int x = 0;

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


    }
    else{
#endif
    existingGraph(); //Use existing data by default and when user input is disabled
#ifdef USER_INPUT
    }
#endif
}
