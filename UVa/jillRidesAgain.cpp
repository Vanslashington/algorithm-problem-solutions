#include <iostream>
#include <cstdio>

using namespace std;

int nroutes;
int routes[20010];

int maxn = 0; 
int mi = -1;
int mj = -1;

int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 1; tcase <= cases; ++tcase)
    {
        maxn = 0;
        
        cin >> nroutes;
        
        routes[0] = 0;
        scanf("%i", &routes[1]);
        for(int i = 2; i < nroutes; ++i)
        {
            scanf("%i", &routes[i]);
            routes[i] += routes[i-1];
        }
        
        for(int i = nroutes-2; i >= 0; --i)
            for(int j = i+1; j < nroutes; ++j)
            {
                int diff = routes[j] - routes[i];
                
                if(diff > maxn || 
                  (diff == maxn && j - i >= mj - mi))
                {
                    maxn = diff;
                    mi = i;
                    mj = j;
                }
            }
            
        if(maxn > 0)
            printf("The nicest part of route %i is between stops %i and %i\n",
                   tcase, mi+1, mj+1);
        else
            printf("Route %i has no nice parts\n", tcase);
    }
    
    return 0;
}
