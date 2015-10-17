#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


int n, k;


int countMemo[101][100];

int count(int remaining, int index)
{
    if(index == k)
        return (remaining == 0);
    
    if(remaining < 0)
        return 0;
        
    if(countMemo[remaining][index] != -1)
        return countMemo[remaining][index];
        
    int ways = 0;
    
    for(int i = 0; i <= remaining; ++i)
        ways = (ways + count(remaining - i, index + 1)) % 1000000;
        
    return countMemo[remaining][index] = ways;
}


int main()
{
    scanf("%i%i", &n, &k);
    
    while(n != 0)
    {
        memset(countMemo, -1, sizeof(countMemo));
        
        printf("%i\n", count(n, 0));
        
        scanf("%i%i", &n, &k);
    }
    
    return 0;
}
