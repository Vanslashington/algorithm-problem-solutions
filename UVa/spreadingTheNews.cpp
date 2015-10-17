#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int N_ADJ = 15;

int nNodes;
int adjList[2500][16];


int maxSize, firstDay;
int day[2500];
queue<int> bfsQ;


int main()
{
    scanf("%i", &nNodes);
    
    for(int n = 0; n < nNodes; ++n)
    {
        scanf("%i", &adjList[n][N_ADJ]);
        for(int a = 0; a < adjList[n][N_ADJ]; ++a)
            scanf("%i", &adjList[n][a]);
    }
    
    int nQueries;
    scanf("%i", &nQueries);
    
    int qSrc;
    for(int q = 0; q < nQueries; ++q)
    {
        scanf("%i", &qSrc);
        
        if(adjList[qSrc][N_ADJ] == 0)
        {
            printf("0\n");
            continue;
        }
        
        maxSize = firstDay = 0;
        memset(day, -1, sizeof(day));
        while(!bfsQ.empty())
            bfsQ.pop();
            
        bfsQ.push(qSrc);
        day[qSrc] = 0;
        
        int currentDay = 0;
        int currentSize = 0;
        
        while(!bfsQ.empty())
        {
            int bf = bfsQ.front();
            int nAdj = adjList[bf][N_ADJ];
            
            if(day[bf] != currentDay)
            {
                if(currentSize > maxSize)
                {
                    maxSize = currentSize;
                    firstDay = currentDay;
                }
                
                currentSize = 0;
                currentDay = day[bf];
            }
            
            ++currentSize;
            
            for(int a = 0; a < nAdj; ++a)
            {
                if(day[adjList[bf][a]] == -1)
                {
                    day[adjList[bf][a]] = day[bf] + 1;
                    bfsQ.push(adjList[bf][a]);
                }
            }
            
            bfsQ.pop();
        }
        
        if(currentSize > maxSize)
        {
            maxSize = currentSize;
            firstDay = currentDay;
        }
        
        if(firstDay == 0)
            firstDay = 1;
        
        printf("%i %i\n", maxSize, firstDay);
    }
    
    return 0;
}
