#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long nt;

nt memo[30010][5];
int denoms[5] = {1, 5, 10, 25, 50};

int target;

nt count(int moneyLeft, int cDenom)
{
    if(cDenom == 5)
        return (moneyLeft == 0);
        
    if(memo[moneyLeft][cDenom] != -1)
        return memo[moneyLeft][cDenom];
    
    nt ways = 0;
    
    for(int i = 0; i * denoms[cDenom] <= moneyLeft; ++i)
        ways += count(moneyLeft - (i * denoms[cDenom]), cDenom + 1);
    
    return memo[moneyLeft][cDenom] = ways;
}

int main()
{
    memset(memo, -1, sizeof(memo));
    
    while(scanf("%i", &target) != EOF)
    {
        nt ways = count(target, 0);
        if(ways <= 1)
            printf("There is only 1 way ");
        else
            cout << "There are " << ways << " ways ";
        
        printf("to produce %i cents change.\n", target);
    }
    
    return 0;
}
