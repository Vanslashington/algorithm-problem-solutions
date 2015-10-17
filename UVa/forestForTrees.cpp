#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void spread(char n, map<char,vector<char> > &graph, map<char,bool> &checked)
{
    checked[n] = true;
    
    for(int i = 0; i < graph[n].size(); ++i)
    {
        if(!checked[graph[n][i]])
            spread(graph[n][i], graph, checked);
    }
}

int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        map<char,vector<char> > graph;
        int trees = 0, acorns = 0;
        
        string s;
        getline(cin, s);
        
        while(s[0] != '*')
        {
            char n1 = s[1];
            char n2 = s[3];
            
            if(!graph.count(n1))
                graph[n1] = vector<char>();
            if(!graph.count(n2))
                graph[n2] = vector<char>();
                
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
            
            getline(cin, s);
        }
        
        getline(cin, s);
        
        map<char,bool> checked;
        for(int i = 0; i < s.length(); i += 2)
            acorns += checked[s[i]] = (!graph.count(s[i]));
            
        for(map<char,bool>::iterator it = checked.begin();
            it != checked.end(); ++it)
        {
            if(!(it->second))
            {
                ++trees;
                spread(it->first, graph, checked);
            }
        }
        
        cout << "There are " << trees << " tree(s) and " 
                             << acorns << " acorn(s)." << endl;
    }
    
    return 0;
}
