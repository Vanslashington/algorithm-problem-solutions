#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n, avg, moves;
vector<int> heights;

int main()
{
    int set = 1;
    
    cin >> n;
    while(n)
    {
        avg = 0;
        moves = 0;
        heights.resize(n);
        
        for(int i = 0; i < n; ++i)
        {
            cin >> heights[i];
            avg += heights[i];
        }
        avg /= n;
        
        for(int i = 0; i < n; ++i)
            moves += (heights[i] > avg ? heights[i] - avg : 0);
            
        printf("Set #%i\nThe minimum number of moves is %i.\n\n", set, moves);
        
        cin >> n;
        ++set;
    }
    
    return 0;
}
