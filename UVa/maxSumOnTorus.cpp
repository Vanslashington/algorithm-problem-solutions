#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


int dim, tdim;
int torus[75*2][75*2];


int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        cin >> dim;
        
        for(int i = 0; i < dim; ++i)
            for(int j = 0; j < dim; ++j)
            {
                scanf("%i", &torus[i][j]);
                torus[i+dim][j] = torus[i][j+dim] = torus[i+dim][j+dim]
                                = torus[i][j];
            }
            
        tdim = 2*dim;
        for(int j = 1; j < tdim; ++j)
            torus[0][j] += torus[0][j-1];
            
        for(int i = 1; i < tdim; ++i)
            torus[i][0] += torus[i-1][0];
            
        for(int i = 1; i < tdim; ++i)
            for(int j = 1; j < tdim; ++j)
                torus[i][j] += (torus[i-1][j] + torus[i][j-1] -
                                    torus[i-1][j-1]);
        
        int maxSum = -600000;
        
        for(int i = 0; i < tdim; ++i)
        for(int j = 0; j < tdim; ++j)
        {
            for(int ii = max(0, (i-dim)+1); ii <= i; ++ii)
            for(int jj = max(0, (j-dim)+1); jj <= j; ++jj)
            {
                int sum = torus[i][j];
                sum -= ( (ii-1 >= 0 ? torus[ii-1][j] : 0) +
                         (jj-1 >= 0 ? torus[i][jj-1] : 0) -
                       (ii-1 >= 0 && jj-1 >= 0 ? torus[ii-1][jj-1] : 0)  );
                
                maxSum = max(maxSum, sum);
            }
        }
        
        if(dim == 0) maxSum = 0;
        
        cout << maxSum << endl;
    }
    
    return 0;
}
