#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


int n;
int nums[1001];


int main()
{
    while(cin >> n)
    {
        for(int i = 0; i < n; ++i)
            scanf("%i", &nums[i]);
            
        
        int count = 0;
        bool flipped;
        int it = 0;
        
        do
        {
            flipped = false;
            
            for(int i = 1; i < (n-it); ++i)
                if(nums[i] < nums[i-1])
                {
                    swap(nums[i], nums[i-1]);
                    flipped = true;
                    ++count;
                }
            
            ++it;
        }
        while(flipped);
        
        
        printf("Minimum exchange operations : %i\n", count);
    }
    
    return 0;
}
