#include <cstdio>
#include <algorithm>

using namespace std;


const int INF = 200000000;

int b, e;
int adjMat[101][101];


int main()
{
    int tcase = 0;
    
    scanf("%i %i", &b, &e);
    while(b != 0)
    {
        for(int i = 1; i <= 100; ++i)
        {
            for(int j = 1; j <= 100; ++j)
                adjMat[i][j] = INF;
                
            adjMat[i][i] = 0;
        }
        
        adjMat[b][e] = 1;
        
        scanf("%i %i", &b, &e);
        while(b != 0)
        {
            adjMat[b][e] = 1;
            
            scanf("%i %i", &b, &e);
        }
        
        
        for(int k = 1; k <= 100; ++k)
            for(int i = 1; i <= 100; ++i)
                for(int j = 1; j <= 100; ++j)
                    adjMat[i][j] = min(        adjMat[i][j],
                                       adjMat[i][k] + adjMat[k][j] );
        
        int tot = 0, n = 0;
        for(int i = 1; i <= 100; ++i)
            for(int j = 1; j <= 100; ++j)
                if(i != j && adjMat[i][j] < INF)
                {
                    tot += adjMat[i][j];
                    ++n;
                }
                
        printf("Case %i: average length between pages = %.3f clicks\n",
                  ++tcase,                    double(tot) / double(n));
        
        scanf("%i %i", &b, &e);
    }
    
    return 0;
}
