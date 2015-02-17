#include <algorithm>
#include <iostream>

#include <Dijkstra_binary.h>
#include <Dijkstra_pq.h>
#include <Dijkstra_redblack.h>

int main()
{

    std::cout << "Dijkstra Binary!" << endl;
    graphclear();
    addEdge(0,1,2);
    addEdge(0,1,4);

    int length = dijkstra_binary(0);


    /*
    std::cout << "Dijkstra Red-Black!" << endl;

//for a undirected graph edges must be pushed both sides
    adjacency_list adjacence_list(6);
    //first vertex
    adjacence_list[0].push_back(neighbor(1,7));
    adjacence_list[0].push_back(neighbor(2,9));
    adjacence_list[0].push_back(neighbor(5,14));

    //Second
    adjacence_list[1].push_back(neighbor(0,7));
    adjacence_list[1].push_back(neighbor(2,10));
    adjacence_list[1].push_back(neighbor(3,15));

    //third
    adjacence_list[2].push_back(neighbor(0,9));
    adjacence_list[2].push_back(neighbor(1,10));
    adjacence_list[2].push_back(neighbor(3,11));
    adjacence_list[2].push_back(neighbor(5,2));
    //fourth
    adjacence_list[3].push_back(neighbor(1, 15));
    adjacence_list[3].push_back(neighbor(2,11));
    adjacence_list[3].push_back(neighbor(4,6));
    //five
    adjacence_list[4].push_back(neighbor(3,6));
    adjacence_list[4].push_back(neighbor(5,9));
    //sixth
    adjacence_list[5].push_back(neighbor(0,14));
    adjacence_list[5].push_back(neighbor(2,2));
    adjacence_list[5].push_back(neighbor(4,9));

    std::vector<weight_t> min_distance;
    std::vector<vertex_t> previous;

    dijkstra_redblack(0,adjacence_list,min_distance,previous);

    std::cout << "Distance from 0 to 4: " << min_distance[4] << std::endl;
    std::list<vertex_t> path = DijkstraGetShortestPath_redblack(4,previous);
    std::cout << "Path : ";
    std::copy(path.begin(),path.end(),std::ostream_iterator<vertex_t>(std::cout," "));
    std::cout << std::endl;

    */
    std::cout << "Dijkstra Priority Queue!" << endl;

    Graph g(2);
    g[0].push_back(make_pair(1, 3));
    g[0].push_back(make_pair(1, 1));

    //Graph g = generateGraph_pq(4,10);
    //printOutGraph(g);

    dijkstra_pq(g);

    //std::cout << prio[1] << endl;


}
