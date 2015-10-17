#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    int n, w;
    
    while(cin >> n)
    {
        map<short, int> pots;
        int max = -1;
        
        int c = pow(2, n);
        for(short i = 0; i < c; ++i)
        {
            cin >> w;
            for(short j = 0; j < n; ++j)
            {
                short adj = (i ^ (1<<j));
                pots[adj] += w;
            }
        }
        
        for(short i = 0; i < c; ++i)
        {
            for(short j = 0; j < n; ++j)
            {
                short adj = (i ^ (1<<j));
                
                int sum = pots[i] + pots[adj];
                if(sum > max)
                {
                    max = sum;
                }
            }
        }
        
        cout << max << endl;
    }
    
    return 0;
}
