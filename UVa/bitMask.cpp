#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long ul;
typedef vector<int> vi;

ul n, l, u;
ul m;
vi bitnums;
ul bits;

int main()
{
    while(cin >> n >> l >> u)
    {
        bitnums.clear();
        
        m = u;
        
        ul max = (n | u);
        
        for(ul i = u; i >= l; --i)
        {
            if((i | n) >= max)
            {
                max = (i | n);
                m = i;
            }
                
            if(!(i & n))
            {
                m = i;
                break;
            }
        }
        
        for(int i = 0; i < 32; ++i)
            if(n & (1u << i))
                bitnums.push_back(i);
                
        int bnlen = bitnums.size();
        
        ul mm;
        bits = 0;
        
        while(true)
        {
            mm = m;
            
            for(int i = 0; i < bnlen; ++i)
            {
                if(bits & (1u << i))
                    mm |= (1u << bitnums[i]);
            }
            
            if(l <= mm && mm <= u)
            {
                cout << mm << endl;
                break;
            }
            
            ++bits;
        }
    }
    
    return 0;
}
