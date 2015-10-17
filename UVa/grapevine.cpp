#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


int rows, cols;
int grid[505][505];

int qLo, qHi;

int bsLo, bsHi;
int bsMid;


bool testLen()
{
    for(int i = 0; i < (rows - bsMid) + 1; ++i)
    {
        int* rSelect = lower_bound(grid[i], grid[i] + cols, qLo);
        
        if(rSelect == grid[i] + cols)
            continue;
        
        int j = rSelect - grid[i];
        
        if((i + bsMid) - 1 < rows && (j + bsMid) - 1 < cols &&
                grid[(i + bsMid) - 1][(j + bsMid) - 1] <= qHi)
        {
            return true;
        }
    }
    
    return false;
}


int main()
{
    cin >> rows >> cols;
    
    while(rows != 0)
    {
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
                scanf("%i", &grid[i][j]);
                
        int numQ;
        cin >> numQ;
        for(int q = 0; q < numQ; ++q)
        {
            scanf("%i%i", &qLo, &qHi);
            
            int maxSideLen = min(rows, cols);
            bsLo = 0;
            bsHi = maxSideLen;
            
            while(bsLo < bsHi)
            {
                bsMid = 1 + (bsLo + bsHi) / 2;
                
                if(testLen())
                    bsLo = bsMid;
                else
                    bsHi = bsMid - 1;
            }
            
            printf("%i\n", bsLo);
        }
        cout << '-' << endl;
        
        cin >> rows >> cols;
    }
    
    return 0;
}
