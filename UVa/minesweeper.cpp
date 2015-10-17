#include <iostream>

using namespace std;

int main()
{
    int fnum = 1;
    int r, c;
    cin >> r >> c;
    
    while(r != 0 || c != 0)
    {
        int f[r][c];
        
        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                f[i][j] = 0;
            }
        }
        
        char s;
        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                cin >> s;
                if(s == '*')
                {
                    for(int ii = i-1; ii <= i+1; ++ii)
                    {
                        for(int jj = j-1; jj <= j+1; ++jj)
                        {
                            if(ii >= 0 && ii < r && jj >= 0 && jj < c)
                            {
                                ++f[ii][jj];
                            }
                        }
                    }
                    f[i][j] = -10;
                }
            }
        }
        
        if(fnum != 1)
            cout << endl;
            
        cout << "Field #" << fnum << ":" << endl;
        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                if(f[i][j] >= 0)
                {
                    cout << f[i][j];
                }
                else
                {
                    cout << "*";
                }
            }
            cout << endl;
        }
        
        ++fnum;
        cin >> r >> c;
    }
    
    return 0;
}
