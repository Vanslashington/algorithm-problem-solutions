#include <iostream>

using namespace std;

int main()
{
    // b, g, c
    
    int bins[3][3];
    
    while(cin >> bins[0][0])
    {
        int min = 2000000000;
        int minl, minm, minr;
        
        int j = 1;
        for(int i = 0; i < 3; ++i)
        {
            for(; j < 3; ++j)
            {
                cin >> bins[i][j];
            }
            
            j = 0;
        }
        for(int i = 0; i < 3; ++i)
        {
            int temp = bins[i][1];
            bins[i][1] = bins[i][2];
            bins[i][2] = temp;
        }
        
        
        
        for(int l = 0; l < 3; ++l)
        {
            for(int m = 0; m < 3; ++m)
            {
                for(int r = 0; r < 3; ++r)
                {
                    if(l != m && l != r && m != r)
                    {
                        int moves = 0;
                        
                        moves += bins[1][l] + bins[2][l];
                        moves += bins[0][m] + bins[2][m];
                        moves += bins[0][r] + bins[1][r];
                        
                        if(moves < min)
                        {
                            min = moves;
                            minl = l;
                            minm = m;
                            minr = r;
                        }
                    }
                }
            }
        }
        
        char letters[3] = {'B', 'C', 'G'};
        
        cout << letters[minl] << letters[minm] << letters[minr]
             << " " << min << endl;
    }
    
    return 0;
}
