#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;


const int INF = 200000000;

int s1Size, s2Size;
int start, sink;

typedef set<int> si;
typedef si::iterator si_it;
typedef map<int, si> nset;
typedef nset::iterator nset_it;

si s1, s2;
nset adjList;

typedef map<int,int> mii;
map<int, mii> adjMat;

mii parent;


int tFlow;

void augmentPath(int node, int minFlow)
{
    if(node == start)
    {
        tFlow = minFlow;
        return;
    }
    
    augmentPath(parent[node], min(minFlow, adjMat[parent[node]][node]));
    adjMat[parent[node]][node] -= tFlow;
    adjMat[node][parent[node]] += tFlow;
}


int main()
{
    int cases;
    cin >> cases;
    
    int tn;
    for(int tcase = 1; tcase <= cases; ++tcase)
    {
        s1.clear(); 
        s2.clear();
        adjList.clear();
        adjMat.clear();
        parent.clear();
        s1Size = 0;
        s2Size = 0;
        start = 0;
        sink = 0;
        
        
        // Get input, Build adjacency list + matrix
        cin >> s1Size;
        for(int n = 0; n < s1Size; ++n)
        {
            scanf("%i", &tn);
            s1.insert(tn);
            adjList[tn] = si();
            adjMat[tn] = mii();
        }
        
        cin >> s2Size;
        for(int n = 0; n < s2Size; ++n)
        {
            scanf("%i", &tn);
            s2.insert(tn);
            adjList[tn] = si();
            adjMat[tn] = mii();
            
            for(si_it a = s1.begin(); a != s1.end(); ++a)
                if((tn == 0 && *a == 0) || tn == 0 || 
                   (*a != 0 && tn % (*a) == 0))
                {
                    adjList[*a].insert(tn);
                    adjMat[*a][tn] = 1;
                    adjMat[tn][*a] = 1;
                }
                else
                {
                    adjMat[*a][tn] = 0;
                    adjMat[tn][*a] = 0;
                }
        }
        
        for(start = 0; s1.count(start) || s2.count(start); ++start) {}
        for(sink = 1; s1.count(sink) || s2.count(sink) || 
                      sink == start; ++sink) {}
        
        adjList[start] = si();
        adjList[sink] = si();
        adjMat[start] = mii();
        adjMat[sink] = mii();
        
        for(si_it a = s1.begin(); a != s1.end(); ++a)
        {
            adjList[start].insert(*a);
            adjMat[start][*a] = 1;
            adjMat[*a][start] = 1;
        }
        for(si_it a = s2.begin(); a != s2.end(); ++a)
        {
            adjList[*a].insert(sink);
            adjMat[*a][sink] = 1;
            adjMat[sink][*a] = 1;
        }
        
        
        // Edmonds Karp's
        int maxFlow = 0;
        
        while(true)
        {
            queue<int> bfsQ;
            set<int> visited;
            tFlow = 0;
            
            bfsQ.push(start);
            visited.insert(start);
            
            while(!bfsQ.empty())
            {
                int tn = bfsQ.front();
                bfsQ.pop();
                
                if(tn == sink)
                    break;
                    
                for(si_it a = adjList[tn].begin();
                          a != adjList[tn].end(); ++a)
                {
                    if(adjMat[tn][*a] > 0 && !visited.count(*a))
                    {
                        visited.insert(*a);
                        parent[*a] = tn;
                        bfsQ.push(*a);
                    }
                }
            }
            
            augmentPath(sink, INF);
            if(tFlow == 0)
                break;
            maxFlow += tFlow;
        }
        
        printf("Case %i: %i\n", tcase, maxFlow);
    }
    
    return 0;
}
