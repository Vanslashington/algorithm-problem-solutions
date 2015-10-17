#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


int nums[3];


int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 1; tcase <= cases; ++tcase)
    {
        for(int i = 0; i < 3; ++i)
            cin >> nums[i];
            
        sort(nums, nums+3);
        
        printf("Case %i: %i\n", tcase, nums[1]);
    }
    
    return 0;
}
