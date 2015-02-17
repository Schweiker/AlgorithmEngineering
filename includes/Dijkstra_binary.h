#ifndef Dijkstra_binary_h
#define Dijkstra_binary_h

#include <algorithm>
#include <climits>

using namespace std;

const int maxnodes = 200000;
const int maxedges = 1000000;


    void graphclear();
    void addEdge(int u, int v, int weight);

    void hswap(int i, int j);
    void moveUp(int pos);
    void add(int id, int prio);
    void increasePriority(int id, int prio);
    void moveDown(int pos);
    int removeMin();

    //dijkstra
    int dijkstra_binary(int s);
    void GenerateGraph_binary(int len);


#endif // Dijkstra_binary_h
