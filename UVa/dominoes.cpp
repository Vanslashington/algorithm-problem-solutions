#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int WHITE = -1;

int graph[100001]
int dfsNum[100001];
int dfsLowF[100001];
int dfsLowB[100001];

int nDoms;


void findScc(int d)
{
}


int main()
{
    int cases;
    cin >> cases;
    
    int nEdges;
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        memset(graph, 0, sizeof(graph));
        memset(dfsNum, WHITE, sizeof(dfsNum));
        memset(dfsLowF, 0, sizeof(dfsLowF));
        memset(dfsLowB, 0, sizeof(dfsLowB));
        
        cin >> nDoms >> nEdges;
        
        int d1, d2;
        for(int e = 0; e < nEdges; ++e)
        {
            scanf("%i %i", &d1, &d2);
            graph[d1] = d2;
        }
        
        
    }
    
    return 0;
}
