#include <Dijkstra_redblack.h>

/*
RUNS IN O(E * log(V)
*/

int dijkstra_redblack(const adjacency_list &adjacence)
{
    std::vector<weight_t> min_distance;
    std::vector<vertex_t> previous;

    return dijkstra_redblack_routine(0, adjacence, min_distance,previous,adjacence.size() - 1);
}

int dijkstra_redblack_routine(vertex_t source, const adjacency_list &adjacence, std::vector<weight_t> &min_distance,std::vector<vertex_t> &previous,vertex_t target)
{
    int n = adjacence.size();
    min_distance.clear();
    min_distance.resize(n,max_weight);
    min_distance[source] = 0;
    previous.clear();
    previous.resize(n, -1);
    //set = redblack-tree
    std::set<std::pair<weight_t,vertex_t>> vertex_queue;
    vertex_queue.insert(std::make_pair(min_distance[source],source));

    //std::cout << "while" << std::endl;

    while(!vertex_queue.empty())
    {
        weight_t dist = vertex_queue.begin()->first;
        vertex_t u = vertex_queue.begin()->second;
        vertex_queue.erase(vertex_queue.begin());

        //Visit each Edge from u
        assert(u < (int)adjacence.size());
        const std::vector<neighbor> &neighbors = adjacence[u];
        for(std::vector<neighbor>::const_iterator neighbor_iter = neighbors.begin();
            neighbor_iter != neighbors.end();
            neighbor_iter++)
            {
                vertex_t v = neighbor_iter->target;
                weight_t weight = neighbor_iter->weight;
                weight_t distance_through_u = dist + weight;
                //std::cout << "if" << std::endl;
                if(distance_through_u < min_distance[v])
                {
                    vertex_queue.erase(std::make_pair(min_distance[v],v));
                    min_distance[v] = distance_through_u;
                    previous[v] = u;
                    vertex_queue.insert(std::make_pair(min_distance[v],v));
                }

            }
    }

    return returnLength(min_distance,target);
}

int returnLength(std::vector<weight_t> &min_distance,vertex_t target)
{
    return (int)min_distance[target];
}

adjacency_list GenerateGraph_rb(int len)
{
    adjacency_list a(len);

    //std::cout << "generating graph" << std::endl;

    //std::cout << "len : " << a.size() <<std::endl;

    for(int i = 0; i < len - 2;i++)
    {
        //for undirected Graph push edges back
        a[i].push_back(neighbor(i+1,1));
        a[i+1].push_back(neighbor(i,1));
    }
    //generate The rest

    for(int i = 0; i < len; i++)
    {
        //std::cout << "for rest" << std::endl;
        bool x = true;
        int y;
        int z;
        int weight;
        while(x)
        {
            y = rand() % len;
            z = rand() % len;
            weight = rand() %101 + 1;
            if(x != y && weight > 0) x = false;
        }
        a[y].push_back(neighbor(z,weight));
        a[z].push_back(neighbor(y,weight));
        //std::cout << "for rest end" << std::endl;
    }
    //std::cout << "end generating" << std::endl;

    return a;
}
/*
int DijkstraGetShortestPath_redblack(
    vertex_t vertex, const std::vector<vertex_t> &previous,const adjacency_list &adjacence)
{

    std::list<vertex_t> path;
    for( ; vertex != -1;vertex = previous[vertex])
        path.push_front(vertex);
;
    int Weight = 0;
    for(std::list<vertex_t>::const_iterator it = path.begin(), end = path.end(); it != end; it++)
    {
        int cur = (int)it;
        int prev = (int)--it;
        Weight += adjacence[prev][cur].weight;
    }
    return Weight;
}
*/
/*
int main()
{
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

    dijkstraComputePaths(0,adjacence_list,min_distance,previous);

    std::cout << "DIstance from 0 to 4: " << min_distance[4] << std::endl;
    std::list<vertex_t> path = DijkstraGetShortestPath(4,previous);
    std::cout << "Path : ";
    std::copy(path.begin(),path.end(),std::ostream_iterator<vertex_t>(std::cout," "));
    std::cout << std::endl;
}
*/
