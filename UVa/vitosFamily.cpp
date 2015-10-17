#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int optHouse;
int nMembers;
int totDist;

int family[501];

int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        cin >> nMembers;
        totDist = 0;
        
        for(int i = 0; i < nMembers; ++i)
            scanf("%i", &family[i]);
            
        sort(family, family + nMembers);
        
        optHouse = family[nMembers / 2];
        
        for(int i = 0; i < nMembers; ++i)
            totDist += abs(optHouse - family[i]);
            
        cout << totDist << endl;
    }
    
    return 0;
}
