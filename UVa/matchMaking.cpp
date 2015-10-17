#include <iostream>
#include <cstdio>

using namespace std;

int b, s;

void getints(int n)
{
    int t;
    for(int i = 0; i < n; ++i)
        scanf("%i", &t);
}

int main()
{
    int tcase = 0;
    cin >> b >> s;
    
    while(b != 0 || s != 0)
    {
        ++tcase;
        
        if(s >= b)
        {
            printf("Case %i: 0\n", tcase);
            getints(b);
            getints(s);
            cin >> b >> s;
            continue;
        }
        
        int tbach;
        scanf("%i", &tbach);
        int min = tbach;
        for(int i = 1; i < b; ++i)
        {
            scanf("%i", &tbach);
            if(tbach < min)
                min = tbach;
        }
            
        printf("Case %i: %i %i\n", tcase, b-s, min);
        getints(s);
        
        cin >> b >> s;
    }
    
    return 0;
}
