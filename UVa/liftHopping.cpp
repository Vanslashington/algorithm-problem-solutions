#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

//          el #   f # 
typedef pair<int, int> floor;

//          time   con f
typedef pair<int, floor> edge;

const int INF = 200000000;

int nElevators;
int endFloor;

vector<int> speeds;
vector<int> conEls[100];


map<floor, vector<edge> > adjList;
map<floor, int> dist;

typedef vector<edge>::iterator ve_it;

//          dist   floor
typedef pair<int, floor> pqElem;
typedef priority_queue<pqElem, vector<pqElem>, greater<pqElem> > floorpq;
floorpq pq;


int main()
{
    while(cin >> nElevators >> endFloor)
    {
        // Clear
        speeds.resize(nElevators);
        for(int i = 0; i < 100; ++i)
            conEls[i].clear();
        adjList.clear();
        dist.clear();
        while(!pq.empty())
            pq.pop();
        
            
        for(int e = 0; e < nElevators; ++e)
            cin >> speeds[e];
            
        floor superStart(-1, 0), superEnd(-1, 1);
        dist[superEnd] = INF;
        
        // Connect adjacent floor for each elevator
        for(int e = 0; e < nElevators; ++e)
        {
            int fNum;
            scanf("%i", &fNum);
            floor pFloor = floor(e, fNum);
            conEls[fNum].push_back(e);
            dist[pFloor] = INF;
            
            char tc;
            scanf("%c", &tc);
            while(tc != '\n')
            {
                scanf("%i", &fNum);
                floor tFloor = floor(e, fNum);
                conEls[fNum].push_back(e);
                dist[tFloor] = INF;
                
                int fdist = fNum - pFloor.second;
                
                adjList[pFloor].push_back(edge(speeds[e]*fdist, tFloor));
                adjList[tFloor].push_back(edge(speeds[e]*fdist, pFloor));
                
                pFloor = tFloor;
                
                
                scanf("%c", &tc);
            }
        }
        
        // Connect elevators that go to the same floor
        for(int i = 0; i < 100; ++i)
            if(conEls[i].size() > 1)
                for(int j = 0; j < conEls[i].size(); ++j)
                {
                    for(int k = j+1; k < conEls[i].size(); ++k)
                    {
                        floor f1(conEls[i][j], i);
                        floor f2(conEls[i][k], i);
                        
                        adjList[f1].push_back(edge(60, f2));
                        adjList[f2].push_back(edge(60, f1));
                    }
                }
        
        // Connect superStart to floor 0
        for(int i = 0; i < conEls[0].size(); ++i)
            adjList[superStart].push_back(edge(0, floor(conEls[0][i], 0)));
           
        // Connect target floor to superEnd
        for(int i = 0; i < conEls[endFloor].size(); ++i)
            adjList[ floor(conEls[endFloor][i], endFloor) ].push_back(
                edge(0, superEnd) );
                
        // Dijkstra's
        dist[superStart] = 0;
        pq.push(pqElem(0, superStart));
        
        while(!pq.empty())
        {
            pqElem t = pq.top();
            pq.pop();
            
            int td = t.first;
            floor tf = t.second;
            
            
            if(td == dist[tf])
            {
                for(ve_it e = adjList[tf].begin();
                    e != adjList[tf].end(); ++e)
                {
                    if(dist[tf] + e->first < dist[e->second])
                    {
                        dist[e->second] = dist[tf] + e->first;
                        pq.push(pqElem(dist[e->second], e->second));
                    }
                }
            }
        }
        
        if(dist[superEnd] < INF)
            cout << dist[superEnd];
        else
            cout << "IMPOSSIBLE";
        cout << endl;
    }
    
    return 0;
}
