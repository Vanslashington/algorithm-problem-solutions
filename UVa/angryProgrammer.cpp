#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <set>

using namespace std;


const int INF = 200000000;

int nMachs, nWires;
int start, sink;
int tFlow;

typedef set<int> si;
typedef si::iterator si_it;
si adjList[101];
int adjMat[101][101];
int parent[101];


void augmentPath(int cn, int minEdge)
{
    if(cn == start)
        tFlow = minEdge;
    else if(parent[cn] != 0)
    {
        augmentPath(parent[cn], min(minEdge, adjMat[parent[cn]][cn]));
        adjMat[parent[cn]][cn] -= tFlow;
        adjMat[cn][parent[cn]] += tFlow;
    }
}


int main()
{
    cin >> nMachs >> nWires;
    while(nMachs != 0)
    {
        for(int n = 1; n <= nMachs * 2; ++n)
            adjList[n].clear();
        memset(adjMat, 0, sizeof(adjMat));
        
        adjMat[1][nMachs + 1] = INF;
        adjMat[nMachs][nMachs + nMachs] = INF;
        
        adjList[1].insert(nMachs + 1);
        adjList[1].insert(1);
        adjList[nMachs].insert(nMachs + nMachs);
        adjList[nMachs + nMachs].insert(nMachs);
        
        int mNum, mCost;
        for(int m = 0; m < nMachs-2; ++m)
        {
            scanf("%i %i", &mNum, &mCost);
            adjMat[mNum][nMachs + mNum] = mCost;
            adjList[mNum].insert(nMachs + mNum);
            adjList[nMachs + mNum].insert(mNum);
        }
        
        int ma, mb, c;
        for(int w = 0; w < nWires; ++w)
        {
            scanf("%i %i %i", &ma, &mb, &c);
            
            adjMat[nMachs + ma][mb] = c;
            adjMat[nMachs + mb][ma] = c;
            
            adjList[nMachs + ma].insert(mb);
            adjList[mb].insert(nMachs + ma);
            adjList[nMachs + mb].insert(ma);
            adjList[ma].insert(nMachs + mb);
        }
        
        int maxFlow = 0;
        while(true)
        {
            queue<int> bfsQ;
            int dist[101];
            for(int i = 1; i <= nMachs*2; ++i)
            {
                dist[i] = INF;
                parent[i] = 0;
            }
            
            
            tFlow = 0;
            
            bfsQ.push(1);
            dist[1] = 0;
            
            start = 1;
            sink = nMachs*2;
            
            while(!bfsQ.empty())
            {
                int tn = bfsQ.front();
                bfsQ.pop();
                
                if(tn == sink)
                    break;
                    
                for(si_it e = adjList[tn].begin();
                          e != adjList[tn].end(); ++e)
                {
                    if(adjMat[tn][*e] > 0 && dist[*e] == INF)
                    {
                        bfsQ.push(*e);
                        parent[*e] = tn;
                        dist[*e] = dist[tn] + 1;
                    }
                }
            }
            
            augmentPath(sink, INF);
            if(tFlow == 0)
                break;
            maxFlow += tFlow;
        }
        
        cout << maxFlow << "\n";
        
        cin >> nMachs >> nWires;
    }
    
    return 0;
}
