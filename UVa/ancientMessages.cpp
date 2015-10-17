#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>

using namespace std;

int bitmap[202][202];

int h, w, h2, w2;
int nObjects, holes;
char hDigit;

char glyphs[6] = {'W', 'A', 'K', 'J', 'S', 'D'};

deque<char> foundObjects;

const int WHITE = 0,
          OBJECT = 1,
          BACKGROUND = 2;


void flood(int nodeY, int nodeX, int color)
{
    bitmap[nodeY][nodeX] = color;
    
    for(int i = nodeY - 1; i <= nodeY + 1; ++i)
        for(int j = nodeX - 1; j <= nodeX + 1; ++j)
            if(i >= 0 && i < h2 && j >= 0 && j < w2)
                if(bitmap[i][j] == WHITE)
                    flood(i, j, color);
}

void oFlood(int nodeY, int nodeX, int color)
{
    bitmap[nodeY][nodeX] = color;
    
    for(int i = nodeY - 1; i <= nodeY + 1; ++i)
        for(int j = nodeX - 1; j <= nodeX + 1; ++j)
        {
            if(bitmap[i][j] == OBJECT)
                oFlood(i, j, color);
            else if(bitmap[i][j] == WHITE)
            {
                ++holes;
                flood(i, j, color);
            }
        }
}


int main()
{
    cin >> h >> w;
    int tcase = 0;
    
    while(h != 0 && w != 0)
    {
        memset(bitmap, WHITE, sizeof(bitmap));
        
        int i, j;
        for(i = 1; i <= h; ++i)
            for(j = 0; j < w; ++j)
            {
                int jj = 1 + j * 4;
                scanf("%1x", &hDigit);
                if(hDigit != 0)
                    for(int k = 0; k < 4; ++k)
                        bitmap[i][jj + k] = ((hDigit & (1 << (3 - k))) ? 1 : 0);
            }
        
        h2 = 2 + h;
        w2 = 2 + w * 4;
    
        nObjects = 0;
        foundObjects.clear();
        
        flood(0, 0, BACKGROUND);
        
        for(int i = 0; i < h2; ++i)
        {
            for(int j = 0; j < w2; ++j)
            {
                if(bitmap[i][j] == OBJECT)
                {
                    holes = 0;
                    oFlood(i, j, (++nObjects) + 2);
                    foundObjects.push_back(glyphs[holes]);
                }
            }
        }
        
        sort(foundObjects.begin(), foundObjects.end());
        
        printf("Case %i: ", ++tcase);
        for(int i = 0; i < nObjects; ++i)
            cout << foundObjects[i];
        cout << endl;
        
        cin >> h >> w;
    }
    
    return 0;
}
