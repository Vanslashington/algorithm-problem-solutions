#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using namespace std;


typedef multiset<int> si;
typedef si::iterator si_it;
vector<si> adjList;

int nNodes;


vector<long> count;
long dfsCount(int n)
{
    if(count[n])
        return count[n];
        
    if(!adjList[n].size())
        return count[n] = 1;
    
    long tcount = 0;
    for(si_it e = adjList[n].begin();
              e != adjList[n].end(); ++e)
    {
        tcount += dfsCount(*e);
    }
    
    return (count[n] = tcount);
}


int main()
{
    int tcase = 0;
    
    while(cin >> nNodes)
    {
        if(nNodes > adjList.size())
        {
            adjList.resize(nNodes);
            count.resize(nNodes);
        }
        
        for(int n = 0; n < nNodes; ++n)
        {
            adjList[n].clear();
            count[n] = 0;
        }
        
        adjList[0].clear();
        count[0] = 0;
        
            
        for(int n = 0; n < nNodes; ++n)
        {
            int nEdges;
            cin >> nEdges;
            
            for(int e = 0; e < nEdges; ++e)
            {
                int conE;
                scanf("%i", &conE);
                adjList[n].insert(conE);
            }
        }
        
        printf("%s%li\n", ((tcase++) == 0 ? "" : "\n"), dfsCount(0));
    }
    
    return 0;
}
