#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;


bool solve(ll a, ll b, ll c)
{
    for(ll x = -1 * b; x <= b; ++x)
    {
        if(x==0) continue;
        if(b%x != 0) continue;
        
        for(ll y = -1 * b; y <= abs(b/x); ++y)
        {
            if(y==0) continue;
            if((b/x)%y != 0) continue;
            
            for(ll z = -1 * b; z <= abs((b/x)/y); ++z)
            {
                if(z==0) continue;
                if(((b/x)/y)%z != 0) continue;
                if(x == y || x == z || y == z) continue;
                
                if(x + y + z == a)
                    if(x*x + y*y + z*z == c)
                    {
                        cout << x << " "
                             << y << " "
                             << z << endl;
                             
                        return true;
                    }
            }
        }
    }
    
    return false;
}


int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        
        if(!solve(a,b,c))
            cout << "No solution." << endl;
    }
    
    return 0;
}
