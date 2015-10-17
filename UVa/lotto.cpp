#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pool;
vector<bool> choices;

int main()
{
    int k;
    cin >> k;
    
    bool first = true;
    
    while(k != 0)
    {
        pool.resize(k);
        for(int i = 0; i < k; ++i)
            cin >> pool[i];
            
        sort(pool.begin(), pool.end());
        
        choices.resize(k);
        for(int i = 0; i < 6; ++i)
            choices[i] = true;
        
        if(first)
            first = false;
        else
            cout << endl;
        
        do
        {
            int p = 0;
            for(int i = 0; i < k; ++i)
                if(choices[i])
                {
                    ++p;
                    cout << pool[i] << (p < 6 ? " " : "");
                }
            
            cout << endl;
        }
        while(prev_permutation(choices.begin(), choices.end()));
        
        cin >> k;
    }
    
    return 0;
}
