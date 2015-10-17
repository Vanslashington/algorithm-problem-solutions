#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef double numt;

numt num;
numt prods[101];
int i;

numt large()
{
    // Store:
    // Abs lorgest pos
    // Abs smallest pos dec
    // Abs largest neg
    // Abs smallest neg
    
    // Loop from each of them to find their match
    
    // Return maximum of:
    // Abs largest / left smallest decimal
    // Right largest / Abs smallest decimal
    // Abs largest neg / left smallest neg
    // Right largest neg / Abs smallest neg
}


int main()
{
    while(cin >> num)
    {
        prods[0] = num;
        i = 1;
        
        while(prods[i-1] != -999999)
        {
            // Account for 0's
            // Element after a 0 = itself
            cin >> num;
            
            if(num == -999999)
                break;
            
            prods[i] = num * (prods[i-1] ? 1 : prods[i -1]);
            ++i;
            
        }
        
        cout << large() << endl;
    }
    
    return 0;
}
