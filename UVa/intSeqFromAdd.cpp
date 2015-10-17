#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> poly;

int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        int degree;
        cin >> degree;
        poly.resize(degree+1);
        
        for(int i = 0; i < degree+1; ++i)
            cin >> poly[i];
        
        ll d, k;
        cin >> d >> k;
            
        ll element;
        int index = 0;
        int s;
        for(ll m = 1; index < k; ++m)
        {
            if(index + m * d >= k-1)
            {
                element = 0;
                for(int i = 0; i < poly.size(); ++i)
                    element += poly[i] * (ll)pow(double(m), double(i));
            }
            
            s = index;
            for(; index < s + m * d && index < k; ++index)
            {}
        }
        
        cout << element << endl;
    }
    
    return 0;
}
