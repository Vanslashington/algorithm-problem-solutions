#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int INF = 2000000000;

int nNodes, nEdges;
int start, target;

struct edge
{
    edge(int end, int w) : end(end), w(w) {}
    int end, w;
};

typedef vector<edge> ve;
typedef ve::iterator ve_it;

ve adjList[20000];


struct node
{
    node(int num, int dist) : num(num), dist(dist) {}
    int num, dist;
    bool operator<(const node& other) const {return dist >= other.dist;}
};

int dist[20000];

priority_queue<node> nodes;


int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 1; tcase <= cases; ++tcase)
    {
        scanf("%i %i %i %i", &nNodes, &nEdges, &start, &target);
        
        for(int n = 0; n < nNodes; ++n)
        {
            adjList[n].clear();
            dist[n] = INF;
        }
        
        while(!nodes.empty())
            nodes.pop();
        
        for(int e = 0; e < nEdges; ++e)
        {
            int tnA, tnB, tw;
            scanf("%i %i %i", &tnA, &tnB, &tw);
            adjList[tnA].push_back(edge(tnB, tw));
            adjList[tnB].push_back(edge(tnA, tw));
        }
        
        nodes.push(node(start, 0));
        dist[start] = 0;
        
        printf("Case #%i: ", tcase);
        
        while(!nodes.empty())
        {
            node top = nodes.top();
            nodes.pop();
            
            if(top.dist == dist[top.num])
            {
                if(top.num == target)
                {
                    printf("%i\n", dist[top.num]);
                    break;
                }
                
                for(ve_it a = adjList[top.num].begin(); 
                    a != adjList[top.num].end(); ++a)
                {
                    if((dist[top.num] + a->w) < (dist[a->end]))
                    {
                        dist[a->end] = dist[top.num] + a->w;
                        nodes.push(node((a->end), dist[a->end]));
                    }
                }
            }
        }
        
        if(dist[target] == INF)
            printf("unreachable\n");
    }
    
    return 0;
}
