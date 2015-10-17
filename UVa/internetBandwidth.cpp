#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;


const int INF = 200000000;

int nNodes, nEdges;
int start, sink;

typedef set<int> vi;
typedef vi::iterator vi_it;
vi adjList[101];
int adjMat[101][101];
int dist[101], parent[101];
queue<int> bfsQ;

int maxFlow, tFlow;


void augmentPath(int cn, int minCap)
{
    if(cn == start)
    {
        tFlow = minCap;
        return;
    }
    else if(parent[cn] != 0)
    {
        augmentPath(parent[cn], min(minCap, adjMat[parent[cn]][cn]));
        adjMat[parent[cn]][cn] -= tFlow;
        adjMat[cn][parent[cn]] += tFlow;
    }
}


int main()
{
    int tcase = 0;
    
    cin >> nNodes;
    while(nNodes != 0)
    {
        for(int i = 1; i <= nNodes; ++i)
            adjList[i].clear();
            
        memset(adjMat, 0, sizeof(adjMat));
        
        
        cin >> start >> sink >> nEdges;
        int na, nb, cap;
        for(int e = 0; e < nEdges; ++e)
        {
            scanf("%i %i %i", &na, &nb, &cap);
            adjMat[na][nb] += cap; 
            adjMat[nb][na] += cap;
            adjList[na].insert(nb);
            adjList[nb].insert(na);
        }
        
        maxFlow = 0;
        while(true)
        {
            while(!bfsQ.empty())
                bfsQ.pop();
            
            for(int i = 1; i <= nNodes; ++i)
                dist[i] = INF;
                
            memset(parent, 0, sizeof(parent));
            
            tFlow = 0;
            bfsQ.push(start);
            dist[start] = 0;
            
            while(!bfsQ.empty())
            {
                int tn = bfsQ.front();
                bfsQ.pop();
                
                if(tn == sink)
                    break;
                    
                for(vi_it e = adjList[tn].begin();
                          e != adjList[tn].end(); ++e)
                {
                    if(adjMat[tn][*e] > 0 && dist[*e] == INF)
                    {
                        dist[*e] = dist[tn] + 1;
                        bfsQ.push(*e);
                        parent[*e] = tn;
                    }
                }
            }
            
            augmentPath(sink, INF);
            if(tFlow == 0)
                break;
            maxFlow += tFlow;
        }
        
        printf("Network %i\nThe bandwidth is %i.\n\n", ++tcase, maxFlow);
        
        cin >> nNodes;
    }
    
    return 0;
}
