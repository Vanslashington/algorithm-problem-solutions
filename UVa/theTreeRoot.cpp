#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


int nNodes;

typedef set<int> si;
typedef si::iterator si_it;
si adjList[5001];


si worst, best;

int farLen, farNode;
bool visited[5001];

void dfs1(int node, int depth)
{
    visited[node] = true;
    
    if(depth > farLen)
    {
        farLen = depth;
        farNode = node;
    }
    
    for(si_it a = adjList[node].begin();
              a != adjList[node].end(); ++a)
    {
        if(!visited[*a])
            dfs1(*a, depth + 1);
    }
}


void dfs2(int node, int depth)
{
    visited[node] = true;
    
    if(depth == farLen)
        worst.insert(node);
    
    if(depth > farLen)
    {
        farLen = depth;
        worst.clear();
        worst.insert(node);
    }
    
    for(si_it a = adjList[node].begin();
              a != adjList[node].end(); ++a)
    {
        if(!visited[*a])
            dfs2(*a, depth + 1);
    }
}


const int INF = 200000000;
int height[5001];
bool dfs3(int node, int depth)
{
    visited[node] = true;
    
    if(depth == farLen)
    {
        height[node] = max(depth, farLen - depth);
        return true;
    }
    
    bool inPath = false;
    
    for(si_it a = adjList[node].begin();
              a != adjList[node].end(); ++a)
    {
        if(!visited[*a])
            if(dfs3(*a, depth + 1))
                inPath = true;
    }
    
    if(!inPath)
        return false;
    
    height[node] = max(depth, farLen - depth);
    
    return true;
}


int main()
{
    while(cin >> nNodes)
    {
        worst.clear();
        best.clear();
        for(int i = 1; i <= nNodes; ++i)
            adjList[i].clear();
            
        int nAdj;
        for(int n = 1; n <= nNodes; ++n)
        {
            scanf("%i", &nAdj);
            int tempn;
            for(int a = 0; a < nAdj; ++a)
            {
                scanf("%i", &tempn);
                adjList[n].insert(tempn);
                adjList[tempn].insert(n);
            }
        }
        
        farLen = farNode = 0;
        memset(visited, 0, sizeof(visited));
        dfs1(1, 0);
        
        farLen = 0;
        memset(visited, 0, sizeof(visited));
        dfs2(farNode, 0);
        
        memset(visited, 0, sizeof(visited));
        dfs2(*(worst.begin()), 0);
        
        memset(visited, 0, sizeof(visited));
        for(int i = 1; i <= nNodes; ++i) height[i] = INF;
        dfs3(*(worst.begin()), 0);
        
        int minH = INF+1;
        for(int i = 1; i <= nNodes; ++i)
        {
            if(height[i] == minH)
                best.insert(i);
                
            if(height[i] < minH)
            {
                best.clear();
                best.insert(i);
                minH = height[i];
            }
        }
        
        
        if(nNodes == 1)
        {
            best.clear();
            worst.clear();
            
            best.insert(1);
            worst.insert(1);
        }
        
        printf("Best Roots  :");
        
        for(si_it it = best.begin();
                    it != best.end(); ++it)
            printf(" %i", *it);
        cout << endl;
        
        printf("Worst Roots :");
        
        for(si_it it = worst.begin();
                    it != worst.end(); ++it)
            printf(" %i", *it);
        cout << endl;
    }
    
    return 0;
}
