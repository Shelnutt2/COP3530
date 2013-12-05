/*Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#ifndef _Vertex
#define _Vertex
#include <Vertex.h>
#endif

using namespace std;

Vertex::Vertex(){

}

Vertex::Vertex(link* newConnections, int newNumConnections, int newId){
    id = newId;
    numConnections = newNumConnections;
    connections = new link[numConnections];
    int i = 0;
    for(i = 0; i<numConnections;i++){
        connections[i] = newConnections[i];
    }
}

Vertex::Vertex(int arg_target, double arg_weight){
    target = arg_target;
    weight = arg_weight;
}

void Vertex::addConnection(link* newLink){
    int i = 0;
    int j = 0;
    for(i=0;i<numConnections;i++){ //Check to see if link already exists
        if(connections[i].vertex->id == newLink->vertex->id){ // If it does just change the weight
            connections[i].weight = newLink->weight;
            j = 1;
        }
    }
    if(j == 0){ //If link does not exist add it to the array of links
        numConnections++;
        link* tmp = new link[numConnections];
        for(i = 0; i<numConnections-1;i++){
            tmp[i] = connections[i];
        }
        tmp[i+1] = *newLink;
        connections = tmp;
    }
}
