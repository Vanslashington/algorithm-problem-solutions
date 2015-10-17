#include <iostream>
#include <cstdio>
#include <set>
#include <deque>

using namespace std;

int nTasks, nEdges;

struct task
{
    task() : nParents(0) {};
    set<int> children;
    int nParents;
};

task tasks[110];
deque<int> order;

void traverse(int node)
{
    tasks[node].nParents = -1;
    order.push_back(node);
    
    for(set<int>::iterator it = tasks[node].children.begin();
        it != tasks[node].children.end(); ++it)
        {
            if(tasks[*it].nParents == 1)
                traverse(*it);
                
            --tasks[*it].nParents;
        }
}


int main()
{
    cin >> nTasks >> nEdges;
    while(nTasks != 0)
    {
        order.clear();
        
        for(int i = 0; i < 110; ++i)
            tasks[i] = task();
        
        for(int i = 0; i < nEdges; ++i)
        {
            int p, c;
            scanf("%i %i", &p, &c);
            
            if(!(tasks[p].children.count(c)))
            {
                tasks[p].children.insert(c);
                ++tasks[c].nParents;
            }
        }
        
        for(int i = 1; i <= nTasks; ++i)
            if(tasks[i].nParents == 0)
                traverse(i);
        
        cout << order[0];
        for(int i = 1; i < nTasks; ++i)
            cout << " " << order[i];
        cout << endl;
        
        
        cin >> nTasks >> nEdges;
    }
    
    return 0;
}
