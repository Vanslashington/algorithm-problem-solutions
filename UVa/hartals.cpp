#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;


bitset<3650> calendar;
int nDays, nParties;


int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        cin >> nDays >> nParties;
        
        
        calendar.reset();
        int count = 0;
        int hp;
        
        for(int p = 0; p < nParties; ++p)
        {
            scanf("%i", &hp);
            
            for(int d = hp-1; d < nDays; d += hp)
            {
                count += (!calendar[d] && (d+2) % 7 != 0 && (d+1) % 7 != 0);
                calendar.set(d);
            }
        }
        
        
        cout << count << endl;
    }
    
    return 0;
}
