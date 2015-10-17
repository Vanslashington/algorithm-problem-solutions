#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;
typedef char nstr[27];
typedef set<string> nset;
typedef map<string, nset> ngraph;

typedef ngraph::iterator ngraph_it;
typedef nset::iterator nset_it;

ngraph calls;
int nPeople, nCalls;




const int WHITE = -1;
typedef map<string, int> simap;
typedef stack<string> sstack;

simap dfsNum, dfsLow;
int dfsCount;
sstack scc;
nset inscc;




void findScc(string name)
{
    dfsNum[name] = dfsLow[name] = dfsCount++;
    scc.push(name);
    inscc.insert(name);

    for(nset_it n = calls[name].begin(); n != calls[name].end(); ++n)
    {
        if(dfsNum[*n] == WHITE)
            findScc(*n);
        
        if(inscc.count(*n))
            dfsLow[name] = min(dfsLow[name], dfsLow[*n]);
    }
    
    if(dfsLow[name] == dfsNum[name])
    {
        while(scc.top() != name)
        {
            printf("%s, ", scc.top().c_str());
            inscc.erase(scc.top());
            scc.pop();
        }
        printf("%s\n", scc.top().c_str());
        inscc.erase(scc.top());
        scc.pop();
    }
}



int main()
{
    int dset = 0;
    
    cin >> nPeople >> nCalls;
    while(!(nPeople == 0 && nCalls == 0))
    {
        calls.clear();
        
        nstr n1, n2;
        for(int c = 0; c < nCalls; ++c)
        {
            scanf("%s %s", n1, n2);
            string str1(n1);
            string str2(n2);
            
            if(!calls.count(str1))
                calls[str1] = nset();
                
            if(!calls.count(str2))
                calls[str2] = nset();
                
            calls[str1].insert(str2);
        }
        
        
        
        for(ngraph_it it = calls.begin(); it != calls.end(); ++it)
        {
            dfsNum[it->first] = WHITE;
            dfsLow[it->first] = WHITE;
        }
        
        while(!scc.empty())
            scc.pop();
        
        inscc.clear();
            
        dfsCount = 0;

        
        printf("Calling circles for data set %i:\n", ++dset);
        
        for(ngraph_it it = calls.begin(); it != calls.end(); ++it)
            if(dfsNum[it->first] == WHITE)
                findScc(it->first);
                
        cin >> nPeople >> nCalls;
        if(!(nPeople == 0 && nCalls == 0))
            cout << endl;
    }
    
    return 0;
}
