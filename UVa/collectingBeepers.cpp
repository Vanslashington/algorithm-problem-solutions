#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

typedef unsigned short bset;

int h, w;
int ry, rx;
int numB;

int dt;

struct beeper
{int y, x;};

beeper beepers[11];


int dist(int r1, int r2)
{
    return (abs(beepers[r1].x - beepers[r2].x) + 
            abs(beepers[r1].y - beepers[r2].y));
}


int memo[1024][10];

int minDist(bset taken, int bNum)
{
    if(taken == dt)
        return dist(0, bNum);
        
    if(memo[taken][bNum])
        return memo[taken][bNum];
        
    int minimum = 10000000;
    
    for(int i = 0; i < numB+1; ++i)
        if(!(taken & (1 << i)))
        {
            int md = minDist((taken | (1 << i)), i);
            
            minimum = min(minimum, 
                        dist(bNum, i) + md);
        }
    
    return memo[taken][bNum] = minimum;
}


int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        memset(memo, 0, sizeof(memo));
        
        scanf("%i%i", &w, &h);
        scanf("%i%i", &rx, &ry);
        scanf("%i", &numB);
        
        dt = int(pow(2.0, double(numB+1))) - 1;
        
        beepers[0].x = rx;
        beepers[0].y = ry;
        
        for(int i = 1; i < numB+1; ++i)
            scanf("%i%i", &beepers[i].x, &beepers[i].y);
        
        printf("The shortest path has length %i\n", minDist(1, 0));
    }
    
    return 0;
}
