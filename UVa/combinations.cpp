#include <iostream>
#include <cstdio>

using namespace std;


typedef long long ll;

ll tn, tr;


ll memo[100][100];
ll pasc_nCr(int n, int r)
{
    if(r > n/2)
        r = n-r;
    
    if(r == 0)
        return 1;
        
    if(memo[n][r])
        return memo[n][r];
        
    return memo[n][r] = (pasc_nCr(n-1, r-1) + pasc_nCr(n-1, r));
}


int main()
{
    cin >> tn >> tr;
    while(tn != 0 || tr != 0)
    {
        printf("%lli things taken %lli at a time is %lli exactly.\n",
               tn, tr, pasc_nCr(tn, tr));
        
        cin >> tn >> tr;
    }
    
    return 0;
}
