#ifndef Dijkstra_redblack_h
#define Dijkstra_redblack_h

#include <iostream>
#include <vector>
#include <string>
#include <list>

#include <limits>
#include <set>
#include <utility>
#include <algorithm>
#include <iterator>
#include <assert.h>

typedef int vertex_t;
typedef double weight_t;

const weight_t max_weight = std::numeric_limits<double>::infinity();

struct neighbor
{
    vertex_t target;
    weight_t weight;
    neighbor(vertex_t arg_target,vertex_t arg_weight)
        : target(arg_target), weight(arg_weight) { }
};

typedef std::vector<std::vector<neighbor>> adjacency_list;

    int dijkstra_redblack(const adjacency_list &adjacence);

    int dijkstra_redblack_routine(vertex_t source, const adjacency_list &adjacence, std::vector<weight_t> &min_distance,std::vector<vertex_t> &previous,vertex_t target);

    int returnLength(std::vector<weight_t> &min_distance,vertex_t target);

    adjacency_list GenerateGraph_rb(int len);

    //int DijkstraGetShortestPath_redblack(vertex_t vertex, const std::vector<vertex_t> &previous);


#endif // Dijkstra_redblack_h

