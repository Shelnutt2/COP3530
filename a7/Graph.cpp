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

Graph::Graph(){
    rootVertex = new Vertex();
    
}

Graph::Graph(Vertex* vertex,Vertex* *arrayVertexs,int V){
    rootVertex = vertex;
    numVertexs = V;
    vertexArray = arrayVertexs;
}
