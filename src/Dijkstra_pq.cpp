#include <Dijkstra_pq.h>

/*
RUNS IN O(E * log(V)
*/
int dijkstra_pq(Graph &g)
{
    vector<int> prio;
    vector<int> pred;

    return dijkstra_pq_routine(g,0,prio,pred);
}

int dijkstra_pq_routine(Graph &g, int s, vector<int> &prio, vector<int> &pred)
{
    int n = g.size();
    prio.assign(n,INT_MAX);
    prio[s] = 0;
    pred.assign(n,-1);
    priority_queue<pii,vector<pii>, greater<pii> > q;

    q.push(make_pair(0,s));

    while(!q.empty())
    {
        int d = q.top().first;
        int u = q.top().second;
        q.pop();
        if(d != prio.at(u))
            continue;
        for(int i = 0;i <(int) g.at(u).size(); i++)
        {

            int v = g[u][i].first;
            int nprio = prio.at(u) + g.at(u).at(i).second;
            if(prio[v] > nprio)
            {
                prio.at(v) = nprio;
                pred.at(v) = u;
                q.push(make_pair(nprio,v));
            }
        }
    }

    int len = returnPathLength(prio,(int)g.size()-1);
    return len;
}

int returnPathLength(vector<int> &prio,int target)
{
    return prio[target];
}

Graph GenerateGraph_pq(int n)
{
    srand(time(NULL));
    Graph g(n);
    //generate Path with given length and weight
    for(int i = 0; i < (int)g.size();i++)
    {
        for(int j = 0; i < (int)g.size();i++)
        {
            g.at(i).push_back(make_pair(j,rand()%101));
        }
    }
    return g;
}

/*
void printOutGraph(Graph g)
{
    for(int i = 0; i < (int)g.size();i++)
    {
        std::cout << "i : " << i << "g[i] : " << g[i] << endl;
    }
}
*/
/*
int main()
{
    Graph g = GenerateGraph_pq(3);
    dijkstra_pq(g);
}
*/

