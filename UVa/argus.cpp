#include <iostream>
#include <queue>
#include <utility>
#include <deque>

using namespace std;

struct order
{
    int qnum;
    int per;
    int nextt;
    
    order(int qnum, int per, int nextt) : qnum(qnum), per(per), nextt(nextt)
    {}
};

struct pgreater
{
    bool operator() (order lhs, order rhs) const
    {
        if(lhs.nextt > rhs.nextt)
            return true;
        else if(lhs.nextt == rhs.nextt)
            return (lhs.qnum > rhs.qnum);
        else
            return false;
    }
};

int main()
{
    priority_queue<order, deque<order>, pgreater> orders;
    
    string s;
    int qnum, per, n;
    
    cin >> s;
    while(s[0] != '#')
    {
        cin >> qnum >> per;
        orders.push(order(qnum, per, per));
        cin >> s;
    }
    cin >> n;
    
    for(int i = 0; i < n; ++i)
    {
        cout << orders.top().qnum << endl;
        orders.push(order( orders.top().qnum, orders.top().per, 
                    orders.top().nextt + orders.top().per));
        orders.pop();
    }
    
    return 0;
}
