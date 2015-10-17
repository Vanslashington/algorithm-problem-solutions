#include <iostream>
#include <cstdio>

using namespace std;


typedef long long ll;

int start, limit;
int count;


void collatz(ll num)
{
    if(num > limit)
        return;
        
    ++count;
    
    if(num == 1)
        return;
        
    if(num % 2 == 0)
        collatz(num / 2);
    else
        collatz(3*num + 1);
}


int main()
{
    int tcase = 0;
    
    scanf("%i%i", &start, &limit);
    while(start >= 0)
    {
        count = 0;
        collatz(start);
        
        printf("Case %i: A = %i, limit = %i, number of terms = %i\n",
                  ++tcase,  start,      limit,                count);
        
        scanf("%i%i", &start, &limit);
    }
    
    return 0;
}
