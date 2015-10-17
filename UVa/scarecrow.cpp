#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int flen;
char field[101];

int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 1; tcase <= cases; ++tcase)
    {
        int count = 0;
        cin >> flen >> field;
        
        for(int i = 1; i <= flen; ++i)
            if(field[i-1] == '.')
            {
                ++count;
                i += 2;
            }
        
        printf("Case %i: %i\n", tcase, count);
    }
    
    return 0;
}
