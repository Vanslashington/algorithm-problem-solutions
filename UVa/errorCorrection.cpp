#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


int dim;
int colSum[100];
int oddRow = -1;
int oddCol = -1;


int main()
{
    int e;
    
    cin >> dim;
    while(dim)
    {
        int nOddRows = 0;
        memset(colSum, 0, sizeof(colSum));
        
        for(int i = 0; i < dim; ++i)
        {
            int rowSum = 0;
            
            for(int j = 0; j < dim; ++j)
            {
                scanf("%i", &e);
                rowSum += e;
                colSum[j] += e;
            }
            
            if(rowSum % 2 != 0)
            {
                ++nOddRows;
                oddRow = i;
            }
        }
        
        int nOddCols = 0;
        
        for(int j = 0; j < dim; ++j)
        {
            if(colSum[j] % 2 != 0)
            {
                ++nOddCols;
                oddCol = j;
            }
        }
        
        
        if(nOddRows == 0 && nOddCols == 0)
            cout << "OK" << endl;
        else if(nOddRows == 1 && nOddCols == 1)
            printf("Change bit (%i,%i)\n", oddRow+1, oddCol+1);
        else
            cout << "Corrupt" << endl;
        
        
        cin >> dim;
    }
    
    return 0;
}
