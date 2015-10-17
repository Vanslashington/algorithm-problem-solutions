#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>

using namespace std;


const int INF = 51;

int nNodes, nEdges;
typedef map<string, int> dlist;
typedef dlist::iterator dlist_it;

map<string, dlist> adjMat;
typedef map<string, dlist>::iterator map_it;

int nodeCount;


int maxDeg()
{
    if(nodeCount != nNodes)
        return INF;
        
    for(map_it i = adjMat.begin(); i != adjMat.end(); ++i)
        for(map_it j = adjMat.begin(); j != adjMat.end(); ++j)
            if(!i->second.count(j->first))
                i->second[j->first] = INF;
                
    for(map_it k = adjMat.begin(); k != adjMat.end(); ++k)
        for(map_it i = adjMat.begin(); i != adjMat.end(); ++i)
            for(map_it j = adjMat.begin(); j != adjMat.end(); ++j)
                i->second[j->first] = min(i->second[j->first],
                                          i->second[k->first] + 
                                                        k->second[j->first]);
    
    int maxInt = 0;
    for(map_it i = adjMat.begin(); i != adjMat.end(); ++i)
        for(map_it j = adjMat.begin(); j != adjMat.end(); ++j)
            if(i->second[j->first] == INF)
                return INF;
            else
                maxInt = max(maxInt, i->second[j->first]);
    
    return maxInt;
}


int main()
{
    int tcase = 0;
    
    cin >> nNodes >> nEdges;
    while(nNodes != 0)
    {
        adjMat.clear();
        nodeCount = 0;
        
        string na, nb;
        
        for(int e = 0; e < nEdges; ++e)
        {
            cin >> na >> nb;
            
            if(!adjMat.count(na))
            {
                ++nodeCount;
                adjMat[na] = dlist();
            }
            if(!adjMat.count(nb))
            {
                ++nodeCount;
                adjMat[nb] = dlist();
            }
            
            adjMat[na][na] = adjMat[nb][nb] = 0;
            adjMat[na][nb] = adjMat[nb][na] = 1;
        }
        
        int maxd = maxDeg();
        
        printf("Network %i: ", ++tcase);
        if(maxd == INF)
            cout << "DISCONNECTED\n";
        else
            cout << maxd << "\n";
        cout << "\n";
        
        cin >> nNodes >> nEdges;
    }
    
    return 0;
}
