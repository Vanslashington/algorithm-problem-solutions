#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;



typedef char T;

map<T,T> pset;

T findSet(T i);
void unionSet(T i, T j);
bool isSameSet(T i, T j);
int numSets();
int sizeOfSet(T i);



int main()
{
    int v;
    while(cin >> v)
    {
        int numV = 0;
        pset.clear();
        map<char, vector<char> > graph;
        
        int e;
        cin >> e;
        
        string src;
        cin >> src;
        
        string s;
        for(int i = 0; i < e; ++i)
        {
            cin >> s;
            
            pset[s[0]] = s[0];
            pset[s[1]] = s[1];
            
            if(!graph.count(s[0]))
                {graph[s[0]] = vector<char>();
                ++numV;}
            if(!graph.count(s[1]))
            {
                graph[s[1]] = vector<char>();
                ++numV;
            }
                
            if(find(graph[s[0]].begin(), graph[s[0]].end(), s[1]) == 
                                         graph[s[0]].end()) 
                graph[s[0]].push_back(s[1]);
            if(find(graph[s[1]].begin(), graph[s[1]].end(), s[0]) == 
                                         graph[s[1]].end()) 
                graph[s[1]].push_back(s[0]);
        }
        
        pset[src[0]] = src[0];
        pset[src[1]] = src[1];
        pset[src[2]] = src[2];
        
        if(!graph.count(src[0]))
            graph[src[0]] = vector<char>();
        if(!graph.count(src[1]))
            graph[src[1]] = vector<char>();
        if(!graph.count(src[2]))
            graph[src[2]] = vector<char>();
        
        unionSet(src[0], src[1]);
        unionSet(src[1], src[2]);
        
        bool end = false;
        int years;
        for(years = 0; numSets() > 1; ++years)
        {
            end = false;
            queue<char> toggle;
            map<char,char>::iterator pit;
            for(pit = pset.begin(); pit != pset.end(); ++pit)
            {
                if(sizeOfSet(pit->first) == 1)
                {
                    int count = 0;
                    for(int i = 0; i < graph[pit->first].size() && 
                        count < 3; ++i)
                    {
                        count += (sizeOfSet(graph[pit->first][i]) > 1);
                    }
                    
                    if(count >= 3)
                        toggle.push(pit->first);
                }
            }
            
            if(toggle.empty() || pset.size() != v)
            {
                cout << "THIS BRAIN NEVER WAKES UP" << endl;
                end = true;
                break;
            }
            
            while(!toggle.empty())
            {
                unionSet(toggle.front(), src[0]);
                toggle.pop();
            }
        }
        if(end) continue;
        
        if(pset.size() != v)
        {
            cout << "THIS BRAIN NEVER WAKES UP" << endl;
            continue;
        }
        
        cout << "WAKE UP IN, " << years << ", YEARS" << endl;
    }
    
    return 0;
}




T findSet(T i)
{
    if(pset[i] == i)
    {
        return i;
    }
    else
    {
        return (pset[i] = findSet(pset[i]));
    }
}

void unionSet(T i, T j)
{
    pset[findSet(i)] = findSet(j);
}

bool isSameSet(T i, T j)
{
    return findSet(i) == findSet(j);
}

int numSets()
{
    int count = 0;
    
    for(map<T,T>::iterator it = pset.begin(); it != pset.end(); ++it)
    {
        count += (it->first == it->second);
    }
    
    return count;
}

int sizeOfSet(T i)
{
    int size = 0;
    
    T iSet = findSet(i);
    
    for(map<T,T>::iterator it = pset.begin(); it != pset.end(); ++it)
    {
        size += (iSet == findSet(it->first));
    }
    
    return size;
}
