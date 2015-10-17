#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <utility>

using namespace std;


map<char, int> cMap;
typedef pair<int,int> coord;
typedef set<coord>::iterator sc_it;

set<coord> sources, sinks;

int rows, cols;
int wCap;
int capGrid[30][30];


int main()
{
    cMap['*'] = cMap['~'] = 0;
    cMap['.'] = cMap['@'] = 1;
    
    while(cin >> rows >> cols >> wCap)
    {
        sources.clear();
        sinks.clear();
        
        cMap['#'] = wCap;
        
        char c;
        for(int i = 0; i < rows; ++i)
        {
            scanf("%*c");
            for(int j = 0; j < cols; ++j)
            {
                scanf("%c", &c);
                capGrid[i][j] = cMap[c];
                
                if(c == '*')
                    sources.insert(coord(i, j));
                else if(c == '#' || c == '@')
                    sinks.insert(coord(i, j));
            }
        }
        
        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
                printf("%i ", capGrid[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    
    
    return 0;
}
