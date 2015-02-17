#ifndef Dijkstra_pq_h
#define Dijkstra_pq_h

#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii> > Graph;

    int dijkstra_pq(Graph &g);

    int dijkstra_pq_routine(Graph &g, int s, vector<int> &prio, vector<int> &pred);

    int returnPathLength(vector<int> &prio,int target);

    Graph GenerateGraph_pq(int len);


#endif
