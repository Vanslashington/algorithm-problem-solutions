#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int nsize, nqueries;
long long d;
int m;
long long nums[200];


long long memo[20][200][10];

long long countWays(long long msum, int index, int cremaining)
{
    if(cremaining < 0)
        return 0;
        
    if(index == nsize)
        return (cremaining == 0 && msum == 0);
        
    if(memo[msum][index][cremaining])
        return memo[msum][index][cremaining];
    
    long long modnum = (msum + nums[index]) % d;
    if(modnum < 0)
        modnum += d;
    
    return memo[msum][index][cremaining] = 
            countWays(modnum, 
                    index + 1, cremaining - 1) + 
           countWays(msum, index + 1, cremaining);
}


int main()
{
    int setn = 0;
    
    scanf("%i%i", &nsize, &nqueries);
    while(nsize != 0)
    {
        for(int i = 0; i < nsize; ++i)
            scanf("%lli", &nums[i]);
        
        printf("SET %i:\n", ++setn);
        for(int q = 1; q <= nqueries; ++q)
        {
            memset(memo, 0, sizeof(memo));
            
            scanf("%lli%i", &d, &m);
            printf("QUERY %i: %lli\n", q, countWays(0, 0, m));
        }
        
        scanf("%i%i", &nsize, &nqueries);
    }
    
    return 0;
}
