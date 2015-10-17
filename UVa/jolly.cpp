#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> nums(n);
        
        for(int i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }
        
        if(n == 1)
        {
            cout << "Jolly" << endl;
            continue;
        }
        
        bitset<3000> diffs;
        
        bool bad = false;
        int d;
        for(int a = 0, b = 1; b < n; ++a, ++b)
        {
            d = abs(nums[a] - nums[b]);
            
            if(d > n-1 || d == 0)
            {
                //cout << " " << a << " " << b << " ";
                bad = true;
                break;
            }
            
            diffs.set(d);
        }
        
        if(bad)
        {
            cout << "Not jolly" << endl;
            continue;
        }
        
        //cout << "   " << diffs << "   ";
        
        for(int i = 1; i < n-1; ++i)
        {
            if(!diffs[i])
            {
                //cout << " " << i << " ";
                bad = true;
                break;
            }
        }
        
        if(bad)
        {
            cout << "Not jolly" << endl;
        }
        else
        {
            cout << "Jolly" << endl;
        }
    }
    
    return 0;
}
