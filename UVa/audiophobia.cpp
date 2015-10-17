#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;


const int INF = 30000000;


int nNodes, nEdges, nQueries;

struct edge
{
    int nA, nB, w;
    edge(int nA, int nB, int w) : nA(nA), nB(nB), w(w) {}
    bool operator<(const edge& other) const {return this->w >= other.w;}
};


priority_queue<edge> edges;

int totAdjMatrix[101][101];
int minAdjMatrix[101][101];


int nset[101];
int findSet(int n)
{return (nset[n] == n ? n : nset[n] = findSet(nset[n]));}

bool sameSet(int nA, int nB)
{return findSet(nA) == findSet(nB);}

bool unionSet(int nA, int nB)
{nset[findSet(nA)] = findSet(nB);}


int main()
{
    int tcase = 0;
    
    scanf("%i %i %i ", &nNodes, &nEdges, &nQueries);
    while(!(nNodes == 0 && nEdges == 0 && nQueries == 0))
    {
        for(int i = 1; i <= nNodes; ++i)
            for(int j = 1; j <= nNodes; ++j)
                totAdjMatrix[i][j] = INF;
        
        memset(minAdjMatrix, -1, sizeof(minAdjMatrix));
        
        for(int n = 1; n <= nNodes; ++n)
            nset[n] = n;
            
        for(int e = 0; e < nEdges; ++e)
        {
            int tnA, tnB, tw;
            scanf("%i %i %i ", &tnA, &tnB, &tw);
            
            edges.push(edge(tnA, tnB, tw));
        }
        
        while(!edges.empty())
        {
            edge smallest = edges.top();
            edges.pop();
            
            int nA = smallest.nA, nB = smallest.nB;
            
            if(!sameSet(nA, nB))
            {
                unionSet(nA, nB);
                totAdjMatrix[nA][nB] = 
                totAdjMatrix[nB][nA] =
                minAdjMatrix[nA][nB] = 
                minAdjMatrix[nB][nA] = smallest.w;
            }
        }
        
        for(int k = 1; k <= nNodes; ++k)
            for(int i = 1; i <= nNodes; ++i)
                for(int j = 1; j <= nNodes; ++j)
                {
                    if(totAdjMatrix[i][k] + totAdjMatrix[k][j] < 
                                                             totAdjMatrix[i][j])
                    {
                        totAdjMatrix[i][j] = 
                                        totAdjMatrix[i][k] + totAdjMatrix[k][j];
                                        
                        minAdjMatrix[i][j] = 
                            max(minAdjMatrix[i][k], minAdjMatrix[k][j]);
                    }
                }
        
        printf("%sCase #%i\n", (tcase++ != 0 ? "\n" : ""), tcase);
        for(int q = 0; q < nQueries; ++q)
        {
            int qnA, qnB;
            scanf("%i %i ", &qnA, &qnB);
                
            if(qnA == 0 || qnB == 0)
            {
                printf("0\n");
                continue;
            }
            
            if(!sameSet(qnA, qnB))
            {
                printf("no path\n");
                continue;
            }
            
            printf("%i\n", minAdjMatrix[qnA][qnB]);
        }
        
        scanf("%i %i %i ", &nNodes, &nEdges, &nQueries);
    }
    
    return 0;
}
