#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;


int nMartians;
int mGraph[50010];
int reach[50010];

int cIndex;


void dfs(int node, int color)
{
    if(reach[node] <= 0)
        reach[node] = color;
        
    if(reach[mGraph[node]] != color && mGraph[node] != cIndex)
    {
        reach[mGraph[node]] = color;
        
        ++reach[cIndex];
        dfs(mGraph[node], color);
    }
}


int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 1; tcase <= cases; ++tcase)
    {
        memset(mGraph, 0, sizeof(mGraph));
        memset(reach, 0, sizeof(reach));
        
        
        cin >> nMartians;
        int ind;
        for(int m = 0; m < nMartians; ++m)
        {
            scanf("%i", &ind);
            scanf("%i", &mGraph[ind]);
        }
        
        
        for(cIndex = 1; cIndex <= nMartians; ++cIndex)
            if(!reach[cIndex])
            {
                reach[cIndex] = 1;
                dfs(cIndex, -1 * cIndex);
            }

            
        int maxi = 1;
        for(int i = 2; i <= nMartians; ++i)
            if(reach[i] > reach[maxi])
                maxi = i;
        
        
        printf("Case %i: %i\n", tcase, maxi);
    }
    
    return 0;
}
