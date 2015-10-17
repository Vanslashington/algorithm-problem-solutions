#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>

using namespace std;


// Resources
const int SOURCE = 0;
int SINK;
const int INF = 200000000;

int h, w;
int grid[41][11];
bool dfsVisit[41][11];

int nNodes;
typedef vector<int> vi;
typedef vi::iterator vi_it;
vi adjList[410];
int adjMat[410][410];

int tFlow;
queue<int> bfsQ;
set<int> bfsVisit;
int bfsParent[410];


// Make bitartite graph
void makeBiGraph(int i, int j, bool color)
{
    dfsVisit[i][j] = false;
    
    int node = grid[i][j];
    
    for(int ii = i-1; ii <= i+1; ++ii)
        for(int jj = j-1; jj <= j+1; ++jj)
            if((ii == i || jj == j) && 
               (ii != i || jj != j) && 
                ii >= 0 && ii < h   &&
                jj >= 0 && jj < w   &&
               (grid[ii][jj]))
            {
                adjList[node].push_back(grid[ii][jj]);
                adjMat[node][grid[ii][jj]] = 1;
                
                if(dfsVisit[ii][jj])
                    makeBiGraph(ii, jj, !color);
            }
            
    int side = (color ? SOURCE : SINK);
    
    adjList[node].push_back(side);
    adjList[side].push_back(node);
    
    adjMat[node][side] = adjMat[side][node] = 1;
}


// Augment path
void augmentPath(int node, int minEdge)
{
    int parent = bfsParent[node];
    
    if(node == SOURCE)
    {
        tFlow = minEdge;
        return;
    }
    
    if(parent != -1)
    {
        augmentPath(parent, min(minEdge, adjMat[parent][node]));
        
        adjMat[parent][node] -= tFlow;
        adjMat[node][parent] += tFlow;
    }
}


// Main
int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        // Clear
        memset(grid, 0, sizeof(grid));
        memset(dfsVisit, 0, sizeof(dfsVisit));
        for(int i = 0; i < 410; ++i)
            adjList[i].clear();
        memset(adjMat, 0, sizeof(adjMat));
        while(!bfsQ.empty())
            bfsQ.pop();
        memset(bfsParent, -1, sizeof(bfsParent));
        bfsVisit.clear();
        
        
        // Input grid
        cin >> h >> w;
        
        nNodes = 0;
        for(int i = 0; i < h; ++i)
            for(int j = 0; j < w; ++j)
            {
                char t;
                cin >> t;
                if(t == '*')
                {
                    grid[i][j] = (++nNodes);
                    dfsVisit[i][j] = true;
                }
            }
        
        SINK = nNodes + 1;
        
        
        // Create bitartite graph using flood fill
        for(int i = 0; i < h; ++i)
            for(int j = 0; j < w; ++j)
                if(dfsVisit[i][j])
                    makeBiGraph(i, j, true);
        
        
        // Edmonds Karp's on bitartite graph
        int maxFlow = 0;
        while(true)
        {
            tFlow = 0;
            
            bfsVisit.clear();
            memset(bfsParent, -1, sizeof(bfsParent));
            while(!bfsQ.empty())
                bfsQ.pop();
            
            bfsQ.push(SOURCE);
            bfsVisit.insert(SOURCE);
            
            while(!bfsQ.empty())
            {
                int tn = bfsQ.front();
                bfsQ.pop();
                
                if(tn == SINK)
                    break;
                    
                for(vi_it a = adjList[tn].begin();
                          a != adjList[tn].end(); ++a)
                {
                    if(adjMat[tn][*a] > 0 && !(bfsVisit.count(*a)))
                    {
                        bfsQ.push(*a);
                        bfsVisit.insert(*a);
                        bfsParent[*a] = tn;
                    }
                }
            }
            
            augmentPath(SINK, INF);
            
            if(tFlow == 0)
                break;
            
            maxFlow += tFlow;
        }
        
        
        // Output
        cout << nNodes - maxFlow << endl;
    }
    
    return 0;
}
