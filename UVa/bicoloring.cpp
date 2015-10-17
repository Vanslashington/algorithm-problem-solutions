#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vi::iterator vit;

enum colors
{
    WHITE = -1,
    UNCOLORED,
    BLACK
};

struct node
{
    node() : color(UNCOLORED) {}
    vi adj;
    int color;
};

int nNodes, nEdges;
node graph[200];


bool bicolor(int nNum, int cColor)
{
    graph[nNum].color = cColor;
    vi& adja = graph[nNum].adj;
    
    for(vit adjn = adja.begin(); adjn != adja.end(); ++adjn)
    {
        if(graph[*adjn].color == cColor)
            return false;
        else if(graph[*adjn].color == UNCOLORED)
            if(!bicolor(*adjn, -1 * cColor))
                return false;
    }
    
    return true;
}


int main()
{
    cin >> nNodes;
    while(nNodes != 0)
    {
        for(int i = 0; i < 200; ++i)
            graph[i] = node();
            
        cin >> nEdges;
        
        for(int i = 0; i < nEdges; ++i)
        {
            int n1, n2;
            scanf("%i %i", &n1, &n2);
            
            graph[n1].adj.push_back(n2);
            graph[n2].adj.push_back(n1);
        }
        
        printf("%sBICOLORABLE.\n", (bicolor(0, WHITE) ? "" : "NOT "));
        
        cin >> nNodes;
    }
    
    return 0;
}
