#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;


int nAreas;


bool check(int m)
{
    deque<int> areas(nAreas);
    for(int i = 0; i < nAreas; ++i)
        areas[i] = i;
    
    int s;
    
    for(int i = 0; areas[i] != 12; )
    {
        areas.erase(areas.begin() + i);
        
        s = areas.size();
        i += (m-1);
        i %= s;
    }
    
    return s == 1;
}


int main()
{
    cin >> nAreas;
    while(nAreas)
    {
        bool found = false;
        for(int m = 1; true; ++m)
        {
            if(check(m))
            {
                found = true;
                cout << m << endl;
                break;
            }
        }
        
        cin >> nAreas;
    }
    
    return 0;
}
