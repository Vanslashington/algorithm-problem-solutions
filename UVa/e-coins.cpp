#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


const int INF = 200000000;

int nCoins, emodGoal;
int emodGoalS;

struct ecoin
{
    int d, i;
    bool operator<(const ecoin& other) const 
        {return (d+i) >= (other.d + other.i);}
};

ecoin ecoins[41];


int memo[41][301][301];

int minCoins(int coinNum, int emodD, int emodI)
{
    int emodSquare = (emodD * emodD) + (emodI * emodI);
    
    if(coinNum == nCoins)
        return (emodSquare == emodGoalS ? 0 : INF);
        
    if(memo[coinNum][emodD][emodI] != -1)
        return memo[coinNum][emodD][emodI];
    
    
    int minFromHere = INF;
    
    int n = 0;
    int nEmodSquare = emodSquare;
    
    while(nEmodSquare <= emodGoalS)
    {
        int newD = emodD + (n * ecoins[coinNum].d);
        int newI = emodI + (n * ecoins[coinNum].i);
        
        minFromHere = min(minFromHere, n + minCoins(coinNum+1, newD, newI));
        
        ++n;
        nEmodSquare = (newD*newD) + (newI*newI);
    }
    
    
    return memo[coinNum][emodD][emodI] = memo[coinNum][emodI][emodD] =
                                minFromHere;
}


int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        memset(memo, -1, sizeof(memo));
                
                
        cin >> nCoins >> emodGoal;
        emodGoalS = emodGoal * emodGoal;
        
        for(int c = 0; c < nCoins; ++c)
            scanf("%i%i", &ecoins[c].d, &ecoins[c].i);
        
        sort(ecoins, ecoins+nCoins);
            
        
        int ans = minCoins(0, 0, 0);
        if(ans == INF)
            cout << "not possible\n";
        else
            cout << ans << endl;
    }
    
    
    return 0;
}
