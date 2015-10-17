#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <deque>
#include <set>

using namespace std;


const bool WHITE = true, BLACK = false;

typedef set<char> sc;
typedef sc::iterator sc_it;

map<char, sc> adjList;
typedef map<char,sc>::iterator al_it;
map<char, int> dist;
map<char, bool> conTo;
map<char, int> cost;
map<char, bool> dfsColor;

deque<char> topSort;
typedef deque<char>::iterator dc_it;


void dfs(char n)
{
    dfsColor[n] = BLACK;
    for(sc_it an = adjList[n].begin();
              an != adjList[n].end(); ++an)
    {
        if(dfsColor[*an])
            dfs(*an);
    }
    topSort.push_front(n);
}


int main()
{
    int cases;
    scanf("%i%*c%*c", &cases);
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        dist.clear();
        conTo.clear();
        topSort.clear();
        adjList.clear();
        cost.clear();
        dfsColor.clear();
        
        
        char toNode;
        int actCost;
        scanf("%c", &toNode);
        while(toNode != '\n')
        {
            cin >> actCost;
            cost[toNode] = actCost;
            dfsColor[toNode] = WHITE;
            dist[toNode] = -1;
            if(!adjList.count(toNode))
                adjList[toNode] = sc();
            
            char c;
            scanf("%c", &c);
            while((c < 'A' || c > 'Z') && c != '\n')
                scanf("%c", &c);
                
            while(c >= 'A' && c <= 'Z')
            {
                conTo[toNode] = true;
                if(!conTo.count(c))
                    conTo[c] = false;
                    
                if(!adjList.count(c))
                    adjList[c] = sc();
                adjList[c].insert(toNode);
                
                scanf("%c", &c);
            }
            
            
            while(c != '\n')
                scanf("%c", &c);
            
            if(scanf("%c", &toNode) == EOF) break;
        }
        
        
        for(al_it n = adjList.begin();
                  n != adjList.end(); ++n)
        {
            char nc = n->first;
            if(!conTo[nc])
            {
                dist[nc] = cost[nc];
                dfs(nc);
            }
        }
        
        int maxDist = 0;
        for(dc_it n = topSort.begin();
                  n != topSort.end(); ++n)
        {
            for(sc_it an = adjList[*n].begin();
                      an != adjList[*n].end(); ++an)
            {
                dist[*an] = max(dist[*an], cost[*an] + dist[*n]);
                maxDist = max(maxDist, dist[*an]);
            }
        }
        
        printf("%s%i\n", (tcase == 0 ? "" : "\n"), maxDist);
    }
    
    return 0;
}
