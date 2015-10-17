#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;


int nNodes, nEdges;
int start, target;
int budget;

const int INF = 200000000;


struct edge
{
    edge(int end, int price) : end(end), price(price) {}
    int end, price;
};
typedef vector<edge> ve;
typedef ve::iterator ve_it;
ve fAdjList[10001], bAdjList[10001]; 


struct node
{
    node(int num, int dist) : num(num), dist(dist) {}
    int num, dist;
    bool operator<(const node& other) const {return dist > other.dist;}
};
priority_queue<node> nodes;
int fDist[10001], bDist[10001];


void dijkstra(int tstart, ve* adjList, int* dist)
{
    while(!nodes.empty())
        nodes.pop();
    for(int n = 1; n <= nNodes; ++n)
        dist[n] = INF;
        
    dist[tstart] = 0;
    nodes.push(node(tstart, 0));
    
    while(!nodes.empty())
    {
        node top = nodes.top();   nodes.pop();
        int tn = top.num, td = top.dist;
        
        if(td == dist[tn])
            for(ve_it e = adjList[tn].begin();
                      e != adjList[tn].end(); ++e)
            {
                int ee = e->end, ep = e->price;
                int newprice = dist[tn] + ep;
                if(newprice < dist[ee] && newprice <= budget)
                {
                    dist[ee] = newprice;
                    nodes.push(node(ee, newprice));
                }
            }
    }
}


int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        for(int n = 1; n <= nNodes; ++n)
        {
            fAdjList[n].clear();
            bAdjList[n].clear();
        }
        
        cin >> nNodes >> nEdges >> start >> target >> budget;
        for(int e = 0; e < nEdges; ++e)
        {
            int na, nb, p;
            scanf("%i%i%i", &na, &nb, &p);
            fAdjList[na].push_back(edge(nb, p));
            bAdjList[nb].push_back(edge(na, p));
        }
        
        dijkstra(start, fAdjList, fDist);
        dijkstra(target, bAdjList, bDist);
        
        int highToll = -1;
        for(int n = 1; n <= nNodes; ++n)
            for(ve_it e = fAdjList[n].begin();
                      e != fAdjList[n].end(); ++e)
            {
                int na = n, nb = e->end, p = e->price;
                if(fDist[na] + bDist[nb] + p <= budget)
                    highToll = max(highToll, p);
            }
        
        cout << highToll << '\n';
    }
    
    return 0;
}
