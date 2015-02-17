#include <gtest/gtest.h>
#include <vector>
#include <Dijkstra_binary.h>
#include <Dijkstra_pq.h>
#include <Dijkstra_redblack.h>

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

TEST(Dijkstra_pq,Dijkstra)
{
//Graph 1
Graph g(2);
g[0].push_back(make_pair(1,2));
g[0].push_back(make_pair(1,4));
//graph 2
Graph f(3);
f[0].push_back(make_pair(1,2));
f[0].push_back(make_pair(1,4));
f[1].push_back(make_pair(2,3));
f[1].push_back(make_pair(2,5));
f[1].push_back(make_pair(2,-1));
Graph h(4);
h[0].push_back(make_pair(1,1));
h[0].push_back(make_pair(3,1));
h[0].push_back(make_pair(2,3));
h[1].push_back(make_pair(2,1));
h[1].push_back(make_pair(3,5));
h[2].push_back(make_pair(3,4));
h[2].push_back(make_pair(3,1));
h[2].push_back(make_pair(3,10));

EXPECT_EQ(2,dijkstra_pq(g));
EXPECT_EQ(1,dijkstra_pq(f));
EXPECT_EQ(1,dijkstra_pq(h));
}

TEST(Dijkstra_binary,Dijkstra)
{
    graphclear();
    addEdge(0,1,1);
    addEdge(0,1,2);

    EXPECT_EQ(1,dijkstra_binary(0));

    graphclear();
    addEdge(0,1,1);
    addEdge(0,1,2);
    addEdge(1,2,1);
    addEdge(1,2,3);

    EXPECT_EQ(2,dijkstra_binary(0));

    graphclear();
    addEdge(0,1,1);
    addEdge(0,1,-1);
    addEdge(1,2,2);
    addEdge(1,2,4);
    addEdge(2,3,3);
    addEdge(2,3,1);

    EXPECT_EQ(2,dijkstra_binary(0));
}

TEST(Dijkstra_redblack,Dijkstra)
{
    adjacency_list a(2);
    adjacency_list b(3);
    adjacency_list c(4);

    std::vector<weight_t> min_distance_a;
    std::vector<vertex_t> previous_a;

    std::vector<weight_t> min_distance_b;
    std::vector<vertex_t> previous_b;

    std::vector<weight_t> min_distance_c;
    std::vector<vertex_t> previous_c;

    a[0].push_back(neighbor(1,1));
    a[0].push_back(neighbor(1,2));

    b[0].push_back(neighbor(1,1));
    b[0].push_back(neighbor(1,2));
    b[1].push_back(neighbor(2,1));
    b[1].push_back(neighbor(2,3));

    c[0].push_back(neighbor(1,1));
    c[0].push_back(neighbor(1,2));
    c[1].push_back(neighbor(2,1));
    c[1].push_back(neighbor(2,3));
    c[2].push_back(neighbor(3,10));
    c[2].push_back(neighbor(3,9));

    EXPECT_EQ(1,dijkstra_redblack(a));
    EXPECT_EQ(2,dijkstra_redblack(b));
    EXPECT_EQ(11,dijkstra_redblack(c));
}


















