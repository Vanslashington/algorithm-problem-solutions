#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <deque>

using namespace std;

typedef deque<int> di;

di nums;

int main()
{
    int num;
    cin >> num;
    
    while(num != 0)
    {
        nums.resize(num);
        for(int i = 0; i < num; ++i)
            scanf("%i", &nums[i]);
            
        di::iterator b = nums.begin(), e = nums.end();
        
        while(*b == 0 && b != e)
            ++b;
            
        while(*(e-1) == 0 && b != e)
            --e;
        
        if(b != e)
        {
            printf("%i", *b);
            ++b;
        }
        else
            cout << '0';
        
        while(b != e)
        {
            if(*b != 0)
                printf(" %i", *b);
                
            ++b;
        }
        cout << endl;
        
        cin >> num;
    }
    
    return 0;
}
