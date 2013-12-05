/*Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#ifndef _Graph
#define _Graph
#include <Graph.h>
#endif

#include <vector>
#include <string.h>
#include <list>
#include <set>
#include <utility>
#include <algorithm>
#include <iterator>

#include <float.h>
 
using namespace std;

int checkPath(Vertex* source, Vertex* target){ //Function to check and see if there is a path between two vertexs
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
    return -1;
}

int setWeight(Vertex* source, Vertex* target){ //Set the weight of a given vertex
    if(source->id == target->id){
        return 1;
    }
    else{
        int i = 0;
        for(i=0;i<source->numConnections;i++){ //Loop through all links
            if(setWeight(source->connections[i].vertex,target)){
                target->weight += source->connections[i].weight;
                int* tmp = new int[target->hops+1]; //Adjust the route to where we are
                int j = 0;
                for(j=0;j<target->hops;j++){
                    tmp[j] = target->route[j];
                }
                tmp[j+1] = source->id; //Set new hop
                target->route = tmp;
            }
        }
    }
   return -1;
}

const double max_weight = DBL_MAX; //Define max double

typedef vector<vector<Vertex> > aList; //Set out double vector typedef.

void DijkstraPaths(int source, const aList &alist, vector<double> &min_distance, vector<int> &previous){ //Find the paths between vertexes
    int n = alist.size(); //Get size of given list
    min_distance.clear(); //Erase the min_dist vecotr
    min_distance.resize(n, max_weight); //Set it to the size of the list
    min_distance[source] = 0;
    previous.clear(); //Clean previous vectory
    previous.resize(n, -1); //Set it to one smaller
    set<pair<double, int> > vertex_queue; //New queue structure
    vertex_queue.insert(make_pair(min_distance[source], source)); //Add to the queue
 
    while (!vertex_queue.empty()) //While we still have nodes to check
    {
        double dist = vertex_queue.begin()->first; //Start at the source vertex
        int u = vertex_queue.begin()->second; //iterate with second vertex
        vertex_queue.erase(vertex_queue.begin());
 
	const vector<Vertex> &Vertexs = alist[u]; //Set the vector to our vertex
        for (vector<Vertex>::const_iterator Vertex_iter = Vertexs.begin(); Vertex_iter != Vertexs.end(); Vertex_iter++){  //Iterate through
            int v = Vertex_iter->target; //Get target
            double weight = Vertex_iter->weight; //Get current weight
            double distance_through_u = dist + weight; //Get distance
	    if (distance_through_u < min_distance[v]) { //Check if we are below current distance
	        vertex_queue.erase(make_pair(min_distance[v], v)); //Remove these as an option
 	        min_distance[v] = distance_through_u; //Set new Max
	        previous[v] = u; //Set previous
	        vertex_queue.insert(make_pair(min_distance[v], v)); //Insert new pair 
	    } 
        }
    }
}

list<int> findShortestpath(int vertex, const vector<int> &previous){ //Find the shortest path between two vertexes
    list<int> path; //New path list
    for ( ; vertex != -1; vertex = previous[vertex]) //Iterate through list
        path.push_front(vertex);
    return path;
}
 
