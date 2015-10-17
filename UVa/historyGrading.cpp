#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;
typedef map<int,int> mii;

int student[21];
mii placings;

int numEvents;

int memo[21];

int longest(int index)
{
    if(memo[index])
        return memo[index];
        
    int maxl = 1;
    
    for(int i = index-1; i >= 0; --i)
        if(placings[student[i]] < placings[student[index]])
        {
            maxl = max(maxl, 1 + longest(i));
        }
    
    memo[index] = maxl;
    return maxl;
}

int main()
{
    cin >> numEvents;
    int n;
    
    for(int i = 0; i < numEvents; ++i)
    {
        scanf("%i", &n);
        placings[i] = n-1;
    }
    
    for(int i = 0; scanf("%i", &n) != EOF; i = 0)
    {
        student[n-1] = i;
        for(i = 1; i < numEvents; ++i)
        {
            scanf("%i", &n);
            student[n-1] = i;
        }
            
        memset(memo, 0, sizeof(memo));
        memo[0] = 1;
        
        int maxl = 1;
        for(int j = 0; j < numEvents; ++j)
            maxl = max(maxl, longest(j));
        
        cout << maxl << endl;
    }
            
    return 0;
}
