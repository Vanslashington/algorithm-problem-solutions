#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


typedef long long ll;
ll heap[20][20][20];

int h, w, d;


int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        cin >> h >> w >> d;
        for(int i = 0; i < h; ++i)
            for(int j = 0; j < w; ++j)
                for(int k = 0; k < d; ++k)
                {
                    scanf("%lli", &heap[i][j][k]);
                    
                    bool selects[3] = {1, 0, 0};
                    do
                    {
                        int ii = i - selects[0],
                            jj = j - selects[1],
                            kk = k - selects[2];
                        
                        if(ii >= 0 && jj >= 0 && kk >= 0)
                            heap[i][j][k] += heap[ii][jj][kk];
                    }
                    while(prev_permutation(selects, selects+3));
                    
                    selects[1] = 1;
                    do
                    {
                        int ii = i - selects[0],
                            jj = j - selects[1],
                            kk = k - selects[2];
                        
                        if(ii >= 0 && jj >= 0 && kk >= 0)
                            heap[i][j][k] -= heap[ii][jj][kk];
                    }
                    while(prev_permutation(selects, selects+3));
                    
                    if(i-1 >= 0 && j-1 >= 0 && k-1 >= 0)
                        heap[i][j][k] += (heap[i-1][j-1][k-1]);
                }
        
        ll maxSum = heap[h-1][w-1][d-1];
        
        for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j)
        for(int k = 0; k < d; ++k)
        {
            for(int ii = 0; ii <= i; ++ii)
            for(int jj = 0; jj <= j; ++jj)
            for(int kk = 0; kk <= k; ++kk)
            {
                ll sum = heap[i][j][k];
                
                sum -= ( (ii-1 >= 0 ? heap[ii-1][j][k] : 0) +
                         (jj-1 >= 0 ? heap[i][jj-1][k] : 0) +  
                         (kk-1 >= 0 ? heap[i][j][kk-1] : 0)  );
                
                sum += ( ((ii-1 >= 0 && jj-1 >= 0) ? heap[ii-1][jj-1][k] : 0) +
                         ((ii-1 >= 0 && kk-1 >= 0) ? heap[ii-1][j][kk-1] : 0) +
                         ((jj-1 >= 0 && kk-1 >= 0) ? heap[i][jj-1][kk-1] : 0) );
                
                if(ii-1 >= 0 && jj-1 >= 0 && kk-1 >= 0)
                    sum -= (1 * heap[ii-1][jj-1][kk-1]);
                
                maxSum = max(maxSum, sum);
            }
        }
        
        
        if(tcase != 0) cout << endl;
        cout << maxSum << endl;
    }
    
    return 0;
}
