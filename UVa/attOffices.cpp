#include <iostream>
#include <utility>
#include <algorithm>
#include <set>
#include <cmath>
#include <deque>

using namespace std;

int grid[5][5];
deque<int> dist;

int main()
{
    int tcases;
    cin >> tcases;
    
    
    //dist.resize(25);
    
    for(int tcase = 0; tcase < tcases; ++tcase)
    {
        dist.clear();
        
        for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 5; ++j)
                grid[i][j] = 0;
                
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i)
        {
            int r, c, pop;
            cin >> r >> c >> pop;
            
            grid[r][c] = pop;
        }
        
        for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 5; ++j)
            {
                int dsum = 0;
                
                for(int ii = 0; ii < 5; ++ii)
                    for(int jj = 0; jj < 5; ++jj)
                        dsum += (abs(i - ii) + abs(j - jj)) * grid[ii][jj];
                    
                //dist[j + i * 5] = dsum;
                dist.push_back(dsum);
            }
            
        sort(dist.begin(), dist.end());
        for(int i = 0; i < 5; ++i)
            cout << dist[i] << (i < 4 ? ' ' : '\n');
    }
    
    return 0;
}
