#include <Dijkstra_binary.h>
#include <iostream>
#include <climits>

/*
RUNS IN O(E * log(V)
*/

//graph
int edges;
int last[maxnodes];
int head[maxedges];
int previous[maxedges];
int len[maxedges];
int prio[maxnodes+maxnodes];
int pred[maxnodes+maxnodes];

//binary heap
int h[maxnodes];
int pos2ID[maxnodes];
int ID2pos[maxnodes];
int hsize;


void graphclear()
{
    fill(last,last+maxnodes, -1);
    edges = 0;
}

void addEdge(int u, int v, int weight)
{
    head[edges] = v;
    len[edges] = weight;
    previous[edges] = last[u];
    last[u] = edges++;
}

void hswap(int i, int j)
{
    swap(h[i],h[j]);
    swap(pos2ID[i],pos2ID[j]);
    swap(ID2pos[pos2ID[i]], ID2pos[pos2ID[j]]);
}

void moveUp(int pos)
{
    while(pos > 0)
    {
        int parent = (pos - 1) >> 1;
        if(h[pos] >= h[parent])
        {
            break;
        }
        hswap(pos,parent);
        pos = parent;
    }
}

void add(int id, int prio)
{
    h[hsize] = prio;
    pos2ID[hsize] = id;
    ID2pos[id] = hsize;
    moveUp(hsize++);
}

void increasePriority(int id, int prio)
{
    int pos = ID2pos[id];
    h[pos] = prio;
    moveUp(pos);
}

void moveDown(int pos)
{
    while(pos <= (hsize >> 1))
    {
        int child = 2 * pos + 1;
        if(child + 1 < hsize && h[child + 1] < h[child])
        {
            ++child;
        }
        if(h[pos] <= h[child])
        {
            break;
        }
        hswap(pos,child);
        pos = child;
    }
}

int removeMin()
{
    int res = pos2ID[0];
    int lastNode = h[--hsize];
    if(hsize > 0)
    {
        h[0] = lastNode;
        int id = pos2ID[hsize];
        ID2pos[id] = 0;
        pos2ID[0] = id;
        moveDown(0);
    }
    return res;
}

int dijkstra_binary(int s)
{
    fill(pred, pred+maxnodes,-1);
    fill(prio,prio+maxnodes,INT_MAX);
    prio[s] = 0;
    hsize = 0;
    add(s,0);
    while(hsize)
    {
        int u = removeMin();
        for(int e = last[u];e >= 0; e = previous[e])
        {
            int v = head[e];
            int nprio = prio[u] + len[e];
            if(prio[v] > nprio)
            {
                if(prio[v] == INT_MAX)
                {
                    add(v,nprio);
                }
                else
                {
                    increasePriority(v,nprio);
                }
                prio[v] = nprio;
                pred[v] = u;
            }
        }
    }
    return h[hsize];
}
void GenerateGraph_binary(int n)
{
    graphclear();
    for(int i = 0; i < n;i++)
    {
        for(int j = 0; j < n;j++)
        {
            addEdge(i,j,rand()%101);
        }
    }
}




















































