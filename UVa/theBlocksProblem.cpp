#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef vector<vector<int> > vv;
typedef vector<int>::iterator vit;

vv piles;
int numPiles;

int locs[30];

char com1[5], com2[5];
int src, dst;

int srcp, dstp;
vit srcit, dstit;



void move()
{
    ++srcit;
    while(srcit != piles[srcp].end())
    {
        piles[*srcit].push_back(*srcit);
        locs[*srcit] = *srcit;
        piles[srcp].erase(srcit);
    }
    --srcit;
    piles[srcp].erase(srcit);
    
    piles[dstp].push_back(src);
    locs[src] = locs[dst];
}


void pile()
{
    while(srcit != piles[srcp].end())
    {
        piles[locs[dst]].push_back(*srcit);
        locs[*srcit] = locs[dst];
        piles[srcp].erase(srcit);
    }
}


int main()
{
    cin >> numPiles;
    
    piles.resize(numPiles, vector<int>(1));
    for(int i = 0; i < numPiles; ++i)
        piles[i][0] = locs[i] = i;
    
    scanf("%s %i %s %i", com1, &src, com2, &dst);
    
    while(com1[0] != 'q')
    {
        if(locs[src] != locs[dst])
        {
            srcp = locs[src]; 
            dstp = locs[dst];
            
            srcit = find(piles[srcp].begin(), piles[srcp].end(), src);
            
            if(com2[1] == 'n')
            {
                dstit = find(piles[dstp].begin(), piles[dstp].end(), dst);
                
                ++dstit;
                
                while(dstit != piles[dstp].end())
                {
                    piles[*dstit].push_back(*dstit);
                    locs[*dstit] = *dstit;
                    piles[dstp].erase(dstit);
                }
            }
            
            if(com1[0] == 'm')
                move();
            else
                pile();
        }
        
        scanf("%s %i %s %i", com1, &src, com2, &dst);
    }
    
    for(int i = 0; i < numPiles; ++i)
    {
        printf("%i:", i);
        for(int j = 0; j < piles[i].size(); ++j)
            printf(" %i", piles[i][j]);
        cout << endl;
    }
    
    return 0;
}
