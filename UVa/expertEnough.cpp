#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct maker
{
    int low, high;
    char name[21];
    bool operator<(const maker &other) const {return this->high < other.high;}
};

bool ucomp(maker r, int l)
{return l >= r.high;}

int dataSize;
maker makers[20001];

int numQ;
int qPrice;

maker* f, * l;
int nFound;

int main()
{
    int cases;
    scanf("%i ", &cases);
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        scanf("%i ", &dataSize);
        
        for(int i = 0; i < dataSize; ++i)
            scanf("%s %i %i", makers[i].name, &makers[i].low, &makers[i].high);
        
        sort(makers, makers + dataSize);
        
        scanf("%i ", &numQ);
        
        for(int q = 0; q < numQ; ++q)
        {
            scanf("%i", &qPrice);
            
            nFound = 0;
            
            l = lower_bound(makers, makers + dataSize, qPrice, ucomp);
            
            for(maker* i = l; i != makers + dataSize; ++i)
            {
                if(i->low <= qPrice)
                {
                    ++nFound;
                    f = i;
                }
                
                if(nFound > 1)
                    break;
            }
            
            printf("%s\n", (nFound == 1 ? f->name : "UNDETERMINED"));
        }
        
        if(tcase < cases-1)
            printf("\n");
    }
    
    return 0;
}
