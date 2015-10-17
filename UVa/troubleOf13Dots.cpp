#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


const int NINF = -200000000;

int money, nItems;

struct item
{ 
    int p, f;
    bool operator<(const item& other) const {return p < other.p;}
};

item items[100];


int memo[10201][100][2];

int shop(int rmoney, int citem, bool bonus)
{
    if(bonus && money - rmoney > 2000)
    {
        bonus = false;
        rmoney += 200;
    }
        
    if(rmoney < 0)
        return NINF;
    
    if(citem == nItems)
        return 0;
        
    if(memo[rmoney][citem][bonus] != -1)
        return memo[rmoney][citem][bonus];

    int ts = shop(rmoney, citem+1, bonus);
    memo[rmoney][citem][bonus] = max(ts,
                items[citem].f + shop(rmoney-items[citem].p, citem+1, bonus));
    
    return memo[rmoney][citem][bonus];
}


int main()
{
    while(cin >> money >> nItems)
    {
        memset(memo, -1, sizeof(memo));
        
        
        for(int i = 0; i < nItems; ++i)
            scanf("%i%i", &items[i].p, &items[i].f);
        
        sort(items, items + nItems);
        
            
        cout << shop(money, 0, true) << endl;
    }
    
    return 0;
}
