#include <iostream>
#include <map>
using namespace std;

int i, j;
map<int, int> memo;


int count(int n)
{
    if(n == 1)
        return 1;
    
    if(memo.count(n))
    {
        return memo[n];
    }
    
    int nn = ((n % 2) ? (3*n+1) : (n / 2));
    
    memo[n] = 1 + count(nn);
    return memo[n];
}


int main()
{
    memo[1] = 1;
    
    while(cin >> i && cin >> j)
    {
        bool swapped = false;
        if(i > j)
        {
            swapped = true;
            int t = i;
            i = j;
            j = t;
        }
        
        int max = 1;
        
        for(int n = i; n <= j; ++n)
        {
            int c = count(n);
            if(max < c)
            {
                max = c;
            }
        }
        
        if(swapped)
        {
            int t = i;
            i = j;
            j = t;
        }
        cout << i << " " << j << " " << max << endl;
    }
    
    return 0;
}
