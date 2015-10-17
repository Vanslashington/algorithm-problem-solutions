#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

ll maxs;
ll s, d;

void calcs(ll current, ll add, int month, vi history)
{
    current += add;
    history[month] = add;
    
    ll hissum = 0;
    
    if(month >= 4)
    {
        for(int i = 0; i <= 4; ++i)
            hissum += history[month - i];
            
        if(hissum >= 0)
            return;
    }
            
    if(month == 11)
    {
        if(current > maxs)
            maxs = current;
            
        return;
    }
    
    calcs(current, s, month+1, history);
    calcs(current, -1 * d, month+1, history);
}

int main()
{
    vi history(12, 0);
    
    while(cin >> s && cin >> d)
    {
        maxs = -1;
        
        calcs(0, s,      0, history);
        calcs(0, -1 * d, 0, history);
        
        if(maxs >= 0)
            cout << maxs;
        else
            cout << "Deficit";
            
        cout << endl;
    }
    
    return 0;
}
