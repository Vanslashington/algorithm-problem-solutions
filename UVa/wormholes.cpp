#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int nNodes, nEdges;

const int INF = 2000000000;

struct edge
{
    edge(int end, int tdiff) : end(end), tdiff(tdiff) {}
    int end, tdiff;
};
typedef vector<edge> ve;
typedef ve::iterator ve_it;
ve adjList[1000];
int dist[1000];


bool cycle()
{
    for(int n = 0; n < nNodes; ++n)
        for(ve_it e = adjList[n].begin();
                  e != adjList[n].end(); ++e)
            if(dist[e->end] > dist[n] + e->tdiff)
                return true;
                
    return false;
}


int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        cin >> nNodes >> nEdges;
        for(int n = 0; n < nNodes; ++n)
        {
            adjList[n].clear();
            dist[n] = INF;
        }
        
        int sn, en, wt;
        for(int e = 0; e < nEdges; ++e)
        {
            scanf("%i%i%i", &sn, &en, &wt);
            adjList[sn].push_back(edge(en, wt));
        }
        
        dist[0] = 0;
        
        for(int i = 0; i < nNodes - 1; ++i)
            for(int n = 0; n < nNodes; ++n)
                for(ve_it e = adjList[n].begin();
                          e != adjList[n].end(); ++e)
                    dist[e->end] = min(dist[e->end], dist[n] + e->tdiff);
                    
        printf("%spossible\n", (cycle() ? "" : "not "));
    }
    
    return 0;
}
