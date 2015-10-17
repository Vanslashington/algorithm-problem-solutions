#include <iostream>
#include <cstdio>

using namespace std;


typedef long long ll;

int numV, numC;
int vCaps[1000];

ll bsLo, bsHi, bsMid;


bool testCap()
{
    int v = 0;
    for(int c = 0; c < numC && v < numV; ++c)
    {
        ll tCont = 0;
        for( ; v < numV && tCont + vCaps[v] <= bsMid; ++v)
            tCont += vCaps[v];
    }
    
    return (v == numV);
}


int main()
{
    while(cin >> numV >> numC)
    {
        bsHi = 0;
        
        for(int i = 0; i < numV; ++i)
        {
            scanf("%i", &vCaps[i]);
            bsHi += vCaps[i];
        }
        
        bsLo = bsHi / numC;
        
        while(bsLo < bsHi)
        {
            bsMid = (bsLo + bsHi) / 2;
            
            if(testCap())
                bsHi = bsMid;
            else
                bsLo = bsMid + 1;
        }
        
        cout << bsLo << endl;
    }
    
    return 0;
}
