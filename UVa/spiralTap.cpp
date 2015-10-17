#include <iostream>
#include <cmath>
using namespace std;

int x, y, ring, p;

void traverseRing()
{
    int p2 = pow(ring*2+1, 2);
    
    for(int i = ring*2+1; i > 1; --i)
    {
        if(p == p2)
        {
            return;
        }
        
        --y;
        --p2;
    }
    
    for(int i = ring*2+1; i > 1; --i)
    {
        if(p == p2)
        {
            return;
        }
        --x;
        --p2;
    }
    
    for(int i = ring*2+1; i > 1; --i)
    {
        if(p == p2)
        {
            return;
        }
        ++y;
        --p2;
    }
    
    for(int i = ring*2+1; i > 1; --i)
    {
        if(p == p2)
        {
            return;
        }
        ++x;
        --p2;
    }
}



int main()
{
    int sz;
    cin >> sz >> p;
    
    while(sz != 0 && p != 0)
    {
        if(p == 1)
        {
            cout << "Line = " << (sz-1)/2 + 1 
                 << ", column = " << (sz-1)/2 + 1 << "."
                 << endl;
            cin >> sz >> p;
            continue;
        }
        
        for(int i = 1; i < 49999; ++i)
        {
            if(p <= pow(i*2 + 1, 2))
            {
                ring = i;
                break;
            }
        }
        
        x = y = ring + ((sz - 1)/2) + 1;
        
        traverseRing();
        
        cout << "Line = " << y << ", column = " << x << "." << endl;
        
        cin >> sz >> p;
    }
    
    return 0;
}
