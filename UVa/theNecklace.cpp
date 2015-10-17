#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
#include <list>
#include <queue>

using namespace std;


int nEdges;

typedef deque<int> di;
typedef di::iterator di_it;
di adjList[51];

typedef list<int> li;
typedef li::iterator li_it;
li eCycle;


bool eulerian;
bool dfsLog[51];
void dfs(int node)
{
    if(!eulerian)
        return;
    
    if(adjList[node].size() % 2 != 0)
    {
        eulerian = false;
        return;
    }
    
    dfsLog[node] = false;
    
    for(di_it e = adjList[node].begin();
              e != adjList[node].end(); ++e)
        if(dfsLog[*e] == true && eulerian)
            dfs(*e);
}


typedef queue<int> qi;
qi startPoints;
void makeCycle(int node, int start, li_it ecPtr)
{
    eCycle.insert(ecPtr, node);
    
    if(adjList[node].size() > 2)
        startPoints.push(node);
    
    if(node == start)
        return;
    
    int next = *(adjList[node].begin());
    adjList[node].pop_front();
    adjList[next].erase(find(adjList[next].begin(),
                             adjList[next].end(), node));
    
    makeCycle(next, start, ecPtr);
}


int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 1; tcase <= cases; ++tcase)
    {
        // Clear
        for(int i = 1; i <= 50; ++i)
            adjList[i].clear();
            
        eCycle.clear();
        
        memset(dfsLog, 0, sizeof(dfsLog));
        
        while(!startPoints.empty())
            startPoints.pop();
        
        
        // Build adjacency list
        cin >> nEdges;
        
        int nA, nB;
        for(int e = 0; e < nEdges; ++e)
        {
            scanf("%i%i", &nA, &nB);
            
            adjList[nA].push_back(nB);
            adjList[nB].push_back(nA);
            
            dfsLog[nA] = dfsLog[nB] = true;
        }
        
        
        // Check for connected and eulerian
        eulerian = true;
        dfs(nA);
        
        if(eulerian)
            for(int i = 1; i <= 50; ++i)
                if(dfsLog[i] == true)
                {
                    eulerian = false;
                    break;
                }
        
        
        // Quit if not workable
        printf("%sCase #%i\n", (tcase != 1 ? "\n" : ""), tcase);
        
        if(!eulerian || nEdges == 0)
        {
            printf("some beads may be lost\n");
            continue;
        }
        
        
        // Else, build the eulerian cycle
        startPoints.push(nA);
        eCycle.push_back(nA);
        
        while(!startPoints.empty())
        {
            int tn = startPoints.front();
            if(adjList[tn].size() > 0)
            {
                if(adjList[tn].size() > 2)
                    startPoints.push(tn);
                    
                int next = *(adjList[tn].begin());
                adjList[tn].pop_front();
                adjList[next].erase(find(adjList[next].begin(),
                                         adjList[next].end(), tn));
                
                li_it ecPtr = find(eCycle.begin(), eCycle.end(), tn);
                ++ecPtr;
                makeCycle(next, tn, ecPtr);
            }
            
            startPoints.pop();
        }
        
        
        // Output eulerian cycle
        li_it it1, it2;
        it1 = it2 = eCycle.begin();
        ++it2;
        
        while(it2 != eCycle.end())
            printf("%i %i\n", *(it1++), *(it2++));
    }
    
    return 0;
}
