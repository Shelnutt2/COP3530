/*Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

using namespace std;

struct link;

class Vertex {
    public:
        Vertex();
        Vertex(link* newConnections, int newNumConnections, int id);
        void addConnection(link* newLink);
        Vertex(int arg_target, double arg_weight);
       
    public:
        link* connections;
        int id;
        int target;
        int numConnections;
        int weight;
        int hops;
        int* route;
};

struct link{
        Vertex* vertex;
        int weight;
        link() : vertex(), weight() {}
        link( Vertex* n, int w ) : vertex( n ), weight( w ) {}
};
