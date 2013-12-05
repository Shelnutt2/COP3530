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


class Graph{ //Graph to hold the Vertexs

    public:
        Graph();
        Graph(Vertex* rootVertex,Vertex* *arrayVertexs,int numberOfVertexs);

    public:
        int numVertexs; //Number of Vertex in graph
        Vertex* rootVertex; //Root Vertex
        Vertex* *vertexArray;

};
