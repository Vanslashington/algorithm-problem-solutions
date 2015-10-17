#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;


// Modify to 3-dimensional state table:
//   Start Node x End Node x Bit Mask


const double INF = 200000000.0;

int nNodes;

typedef unsigned char byte;

struct coord
{
    int x, y;
};

coord comps[8];


double compDist(int c1, int c2)
{
    int xDist = abs(comps[c1].x - comps[c2].x);
    int yDist = abs(comps[c1].y - comps[c2].y);
    
    return sqrt(double((xDist*xDist) + (yDist*yDist))) + 16.0;
}


struct memoElem
{
    memoElem() {}
    memoElem(double dist, int prev) : dist(dist), prev(prev) {}
    
    double dist;
    int prev;
};

memoElem memo[8][8][257];

memoElem minPath(int startNode, int endNode, byte bitMask)
{
    if(!(bitMask ^ (1 << startNode)))
        return memoElem(0.0, startNode);
        
    if(memo[startNode][endNode][bitMask].dist != 0.0)
        return memo[startNode][endNode][bitMask];
    
    
    memoElem minRet(INF, -1);
    
    for(int a = 0; a < nNodes; ++a)
    {
        if(a != startNode && (bitMask & (1 << a)))
        {
            memoElem t = minPath(startNode, a, (bitMask ^ (1 << a)));
            
            double a2t = compDist(t.prev, a);
            
            if(t.dist + a2t < minRet.dist)
            {
                minRet.dist = t.dist + a2t;
                minRet.prev = a;
            }
        }
    }
    
    
    return memo[startNode][bitMask] = minRet;
}


int printPath(int startNode, byte bitMask)
{
    if(!(bitMask ^ (1 << startNode)))
        return startNode;
    
    int thisNum = memo[startNode][bitMask].prev;
    int prevNum = printPath(startNode, bitMask ^ (1 << thisNum));
    
    printf("Cable requirement to connect (%i,%i) to (%i,%i) is %.2f feet.\n",
           comps[prevNum].x, comps[prevNum].y,
           comps[thisNum].x, comps[thisNum].y,
           compDist(prevNum, thisNum));
    
    return thisNum;
}


int main()
{
    int tcase = 0;
    
    cin >> nNodes;
    while(nNodes != 0)
    {
        for(int i = 0; i < 8; ++i)
            for(int j = 0; j < 257; ++j)
                memo[i][j].dist = 0.0;
                    
                    
        for(int n = 0; n < nNodes; ++n)
            scanf("%i%i", &comps[n].x, &comps[n].y);
        
        
        byte pEnd = 0;
        for(int i = 0; i < nNodes; ++i)
            pEnd |= (1 << i);
        
        memoElem mp(INF, -1);
        int minStart = INF;
        for(int s = 0; s < nNodes; ++s)
        {
            memoElem t = minPath(s, pEnd);
            if(t.dist < mp.dist)
            {
                mp = t;
                minStart = s;
            }
        }
        
        cout << "**********************************************************\n";
        printf("Network #%i\n", ++tcase);
        printPath(minStart, pEnd);
        printf("Number of feet of cable required is %.2f.\n", mp.dist);
        
        
        cin >> nNodes;
    }
    
    return 0;
}
