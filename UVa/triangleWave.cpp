#include <iostream>
#include <cstdio>

using namespace std;

int a, f;

int main()
{
    int cases;
    cin >> cases;
    
    bool notfirst = false;
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        if(notfirst)
            cout << endl;
        notfirst = true;
        
        scanf("%i %i", &a, &f);
        
        bool notfirstwave = false;
        for(int wave = 0; wave < f; ++wave)
        {
            if(notfirstwave)
                cout << endl;
            notfirstwave = true;
            
            for(int h = 1; h <= a; ++h)
            {
                for(int i = 0; i < h; ++i)
                    printf("%i", h);
                printf("\n");
            }
            
            for(int h = a-1; h >= 1; --h)
            {
                for(int i = 0; i < h; ++i)
                    printf("%i", h);
                printf("\n");
            }
        }
    }
}
