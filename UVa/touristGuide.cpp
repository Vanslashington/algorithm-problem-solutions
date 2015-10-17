#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;


const int WHITE = -1;

typedef map<string, vector<string> > msv;
typedef msv::iterator msv_it;
typedef vector<string>::iterator vs_it;

msv adjList;
int nPlaces, nRoads;
map<string, int> dfsNum, dfsLow;
int dfsDepth;

map<string, string> dfsParent;
set<string> artPoints;

string start;
int camsFound;


void tarjan(string n)
{
    dfsNum[n] = dfsLow[n] = dfsDepth++;
    int children = 0;
        
    for(vs_it a = adjList[n].begin();
        a != adjList[n].end(); ++a)
    {
        if(dfsNum[*a] == WHITE)
        {
            dfsParent[*a] = n;
            ++children;
            tarjan(*a);

            if(dfsLow[*a] >= dfsNum[n] && !artPoints.count(n) && n != start)
            {
                artPoints.insert(n);
                ++camsFound;
            }

            dfsLow[n] = min(dfsLow[n], dfsLow[*a]);
        }

        else if(dfsParent[n] != *a)
            dfsLow[n] = min(dfsLow[n], dfsNum[*a]);
    }

    if(n == start && children > 1)
    {
        artPoints.insert(n);
        ++camsFound;
    }
}


int main()
{
    int mapNum = 0;

    cin >> nPlaces;
    while(nPlaces != 0)
    {
        adjList.clear();
        dfsNum.clear();
        dfsLow.clear();
        artPoints.clear();
        dfsParent.clear();
        
        camsFound = 0;


        for(int p = 0; p < nPlaces; ++p)
        {
            string place;
            cin >> place;

            adjList[place] = vector<string>();
            dfsNum[place] = dfsLow[place] = WHITE;
        }

        cin >> nRoads;
        for(int r = 0; r < nRoads; ++r)
        {
            string p1, p2;
            cin >> p1 >> p2;

            adjList[p1].push_back(p2);
            adjList[p2].push_back(p1);
        }

        
        for(msv_it p = adjList.begin();
            p != adjList.end(); ++p)
        {
            start = p->first;

            if(dfsNum[start] == WHITE)
            {
                dfsDepth = 0;
                tarjan(start);                
            }
        }


        if(mapNum != 0)
            cout << endl;

        printf("City map #%i: %i camera(s) found\n", ++mapNum, camsFound);
        for(set<string>::iterator p = artPoints.begin();
            p != artPoints.end(); ++p)
        {
            cout << *p << endl;
        }
       
        cin >> nPlaces;
    }

    return 0;
}
