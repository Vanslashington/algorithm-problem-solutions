#include <iostream>
#include <cstdio>

using namespace std;

int grid[101][101];
int n;
int maxsum, rectsum;

int main()
{
    cin >> n;
    
    scanf("%i", &grid[0][0]);
    
    for(int j = 1; j < n; ++j)
    {
        scanf("%i", &grid[0][j]);
        grid[0][j] += grid[0][j-1];
    }
        
    for(int i = 1; i < n; ++i)
    {
        scanf("%i", &grid[i][0]);
        grid[i][0] += grid[i-1][0];
        
        for(int j = 1; j < n; ++j)
        {
            scanf("%i", &grid[i][j]);
            grid[i][j] += ((grid[i-1][j] + grid[i][j-1]) - grid[i-1][j-1]);
        }
    }
        
    
    
    maxsum = -1270000;
    
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
    {
        for(int ii = i; ii < n; ++ii)
        for(int jj = j; jj < n; ++jj)
        {
            rectsum = grid[ii][jj];
            
            if(j != 0)
                rectsum -= grid[ii][j-1];
            
            if(i != 0)
                rectsum -= grid[i-1][jj];
            
            if(j != 0 && i != 0)
                rectsum += grid[i-1][j-1];
            
            if(rectsum > maxsum)
                maxsum = rectsum;
        }
    }
    
    cout << maxsum << endl;
    
    return 0;
}
