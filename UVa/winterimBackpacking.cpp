#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


int nCamps, nNights;
int nGaps;
int trailLen;

int gaps[605];


int tryLen(int b, int e)
{
    if(b == e)
        return b;
        
    int mid = (b + e) / 2;
    int cGap = 0;
    int campCount = 0;
    
    for(int i = 0; i < nGaps; ++i)
    {
        if(gaps[i] > mid)
            return tryLen(mid + 1, e);
        
        if(cGap + gaps[i] > mid)
        {
            ++campCount;
            if(campCount > nNights)
                return tryLen(mid + 1, e);
                
            cGap = 0;
        }
        
        cGap += gaps[i];
    }
    
    return tryLen(b, mid);
}


int main()
{
    while(cin >> nCamps >> nNights)
    {
        nGaps = nCamps + 1;
        trailLen = 0;
        
        memset(gaps, 0, sizeof(gaps));
        
        for(int g = 0; g < nGaps; ++g)
        {
            scanf("%i", &gaps[g]);
            trailLen += gaps[g];
        }
        
        printf("%i\n", tryLen(0, trailLen));
    }
    
    return 0;
}
