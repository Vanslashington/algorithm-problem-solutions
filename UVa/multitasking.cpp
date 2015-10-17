#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int, int> > ncal;
vector< pair< pair<int, int>, int > > mcal;

bool pComp(pair<int,int> lhs, pair<int,int> rhs)
{
    return (lhs.first < rhs.first);
}

bool n2n()
{
    int s = ncal.size();
    for(int i = 1; i < s; ++i)
    {
        if(ncal[i].first < ncal[i-1].second)
        {
            return false;
        }
    }
    
    return true;
}

bool n2m()
{
    
}

int main()
{
    
    int n, m;
    
    cin >> n >> m;
    
    while(n || m)
    {
        int b, e, r;
        
        for(int i = 0; i < n; ++i)
        {
            cin >> b >> e;
            ncal.push_back(pair<int, int>(b, e));
        }
        sort(ncal.begin(), ncal.end(), pComp);
        
        for(int i = 0; i < m; ++i)
        {
            cin >> b >> e >> r;
            mcal.push_back(pair< pair<int,int>, int>(pair<int,int>(b,e),r));
        }
        
        // n to n
        if(!n2n())
        {
            cout << "CONFLICT" << endl;
            continue;
        }
        
        // n to m
        
        
        cin >> n >> m;
    }
    
    return 0;
}
