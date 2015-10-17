#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 10000;
const int WHITE = -1;

int start, target, nButtons;
int buttons[10];
int states[MAX];
queue<int> bfsQ;

int main()
{
    int tcase = 0;
    cin >> start >> target >> nButtons;
    while(!(start == 0 && target == 0 && nButtons == 0))
    {
        for(int b = 0; b < nButtons; ++b)
            cin >> buttons[b];
        
        memset(states, WHITE, sizeof(states));
        
        while(!bfsQ.empty())
            bfsQ.pop();
        
        bfsQ.push(start);
        states[start] = 0;
        
        printf("Case %i: ", ++tcase);
        
        while(!bfsQ.empty())
        {
            int current = bfsQ.front();
            bfsQ.pop();
            
            if(current == target)
            {
                cout << states[current] << "\n";
                break;
            }
            
            for(int b = 0; b < nButtons; ++b)
            {
                int next = (current + buttons[b]) % MAX;
                if(states[next] == WHITE)
                {
                    bfsQ.push(next);
                    states[next] = states[current] + 1;
                }
            }
        }
        
        if(states[target] == WHITE)
            cout << "Permanently Locked\n";
        
        cin >> start >> target >> nButtons;
    }
    
    return 0;
}
