#include <iostream>
#include <deque>
#include <utility>

using namespace std;
typedef pair<int,int> ii;
typedef deque<ii> dii;

int spaces, pieces;
ii ontheleft, ontheright;
dii doms;


bool place(dii remaining, int rindex, int prev, int tplace)
{
    if(rindex != -1)
        remaining.erase(remaining.begin() + rindex);
        
    if(tplace == spaces)
        return (prev == ontheright.first);
        
    for(int i = 0; i < remaining.size(); ++i)
    {
        if(remaining[i].first == prev)
            if( place(remaining, i, remaining[i].second, tplace + 1) )
                return true;
                
        if(remaining[i].second == prev)
            if( place(remaining, i, remaining[i].first, tplace + 1) )
                return true;
    }
    
    return false;
}


int main()
{
    cin >> spaces;
    
    while(spaces)
    {
        cin >> pieces;
        cin >> ontheleft.first >> ontheleft.second;
        cin >> ontheright.first >> ontheright.second;
        
        doms.resize(pieces);
        for(int i = 0; i < pieces; ++i)
            cin >> doms[i].first >> doms[i].second;
        
        cout << ( place(doms, -1, ontheleft.second, 0) ? "YES" : "NO" ) << endl;
        
        cin >> spaces;
    }
    
    return 0;
}
