#include <iostream>
#include <cstdio>

using namespace std;


typedef long long ll;

ll b, p;
int m;


int main()
{
    while(scanf("%lli", &b) != EOF)
    {
        scanf("%lli", &p);
        scanf("%i", &m);
        
        int ans;
        
        if(p == 0 && b > 0)
        {
            b = 1;
            p = 1;
        }
        
        int rem = 1;
        while(p > 1)
        {
            while(b <= 46340 && p > 1)
            {
                rem %= m;
                
                if(p % 2 != 0)
                    rem *= b;
                
                b *= b;
                
                p /= 2;
            }
            
            b %= m;
        }
        
        rem %= m;
        ans = (rem * b) % m;
        
        cout << ans << endl;
    }
    
    return 0;
}
