#include <cstdio>

using namespace std;
typedef long long ll;

ll qCuts;

ll cuts, regions;

int main()
{
    scanf("%lli ", &qCuts);
    while(qCuts >= 0)
    {
        for(cuts = 0, regions = 1; cuts < qCuts; ++cuts, regions += cuts){}
        
        printf("%lli\n", regions);
        
        scanf("%lli ", &qCuts);
    }
    
    return 0;
}
