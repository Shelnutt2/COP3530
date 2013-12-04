/*Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#ifndef _Graph
#define _Graph
#include <Graph.h>
#endif

using namespace std;

#if 0
class Dijkstras{
    public:
        Dijkstras(Graph* graph);

};
#endif

int checkPath(Vertex* source, Vertex* target){
    if(source->id == target->id){
        return 1;
    }
    else{
        int i = 0;
        for(i=0;i<source->numConnections;i++){
            if(checkPath(source->connections[i].vertex, target))
                return 1;
        }
    }
}

int setWeight(Vertex* source, Vertex* target){
    if(source->id == target->id){
        return 1;
    }
    else{
        int i = 0;
        for(i=0;i<source->numConnections;i++){
            if(setWeight(source->connections[i].vertex,target)){
                target->weight += source->connections[i].weight;
                int* tmp = new int[target->hops+1];
                int j = 0;
                for(j=0;j<target->hops;j++){
                    tmp[j] = target->route[j];
                }
                tmp[j+1] = source->id;
                target->route = tmp;
            }
        }
    }
}

int* Dijkstras(Graph* graph, Vertex* target){
    int numVertexs = graph -> numVertexs;
    Vertex* source = graph -> rootVertex;
    int i = 0;
    for(i = 0; i < source->numConnections;i++){
        if(checkPath(source,source->connections[i].vertex)){
            
        }
    }
}
