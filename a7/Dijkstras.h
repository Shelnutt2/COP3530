/*Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#ifndef _Graph
#define _Graph
#include <Graph.h>
#endif

#include <iostream>
#include <vector>
#include <string>
#include <list>
 
#include <limits> // for numeric_limits
 
#include <set>
#include <utility> // for pair
#include <algorithm>
#include <iterator>

#include <float.h>
 
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

 
const double max_weight = DBL_MAX;

typedef std::vector<std::vector<Vertex> > aList;

void DijkstraComputePaths(int source, const aList &alist,
                          std::vector<double> &min_distance, std::vector<int> &previous)
{
    int n = alist.size();
    min_distance.clear();
    min_distance.resize(n, max_weight);
    min_distance[source] = 0;
    previous.clear();
    previous.resize(n, -1);
    std::set<std::pair<double, int> > vertex_queue;
    vertex_queue.insert(std::make_pair(min_distance[source], source));
 
    while (!vertex_queue.empty()) 
    {
        double dist = vertex_queue.begin()->first;
        int u = vertex_queue.begin()->second;
        vertex_queue.erase(vertex_queue.begin());
 
        // Visit each edge exiting u
	const std::vector<Vertex> &Vertexs = alist[u];
        for (std::vector<Vertex>::const_iterator Vertex_iter = Vertexs.begin();
             Vertex_iter != Vertexs.end();
             Vertex_iter++)
        {
            int v = Vertex_iter->target;
            double weight = Vertex_iter->weight;
            double distance_through_u = dist + weight;
	    if (distance_through_u < min_distance[v]) {
	        vertex_queue.erase(std::make_pair(min_distance[v], v));
 
	        min_distance[v] = distance_through_u;
	        previous[v] = u;
	        vertex_queue.insert(std::make_pair(min_distance[v], v));
 
	    }
 
        }
    }
}

std::list<int> DijkstraGetShortestPathTo(int vertex, const std::vector<int> &previous)
{
    std::list<int> path;
    for ( ; vertex != -1; vertex = previous[vertex])
        path.push_front(vertex);
    return path;
}
 
