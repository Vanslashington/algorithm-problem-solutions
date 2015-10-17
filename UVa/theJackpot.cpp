#include <iostream>
#include <cstdio>

using namespace std;

int numbers[10001];
int n;
int tnum;
int maxn;

int main()
{
    cin >> n;
    while(n != 0)
    {
        maxn = 0;
        
        scanf("%i", &numbers[0]);
        
        for(int i = 1; i < n; ++i)
        {
            scanf("%i", &numbers[i]);
            numbers[i] += numbers[i-1];
        }
        
        for(int i = 0; i < n; ++i)
            for(int j = i+1; j < n; ++j)
            {
                int streak = numbers[j] - numbers[i];
                if(streak > maxn)
                    maxn = streak;
            }
        
        if(maxn)
            printf("The maximum winning streak is %i.", maxn);
        else
            printf("Losing streak.");
        
        cout << endl;
        
        cin >> n;
    }
    
    return 0;
}
