#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <string>

using namespace std;

struct car
{
    int a;
    bool side;
    int order;
    int a2;
    
    car(int a, bool side, int order) : a(a), side(side), order(order)
    {}
};

int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        int n, t, m;
        cin >> n >> t >> m;
        
        vector<car> cars;
        queue<car> qs[2];
        
        for(int i = 0; i < m; ++i)
        {
            int arrive;
            string s;
            
            cin >> arrive >> s;
            
            cars.push_back(car(arrive, (s[0] != 'l'), i));
        }
        
        bool fside = 0;
        int time = 0;
        int cindex = 0;
        
        while(cindex < m || !qs[0].empty() || !qs[1].empty())
        {
            // Cars arrive
            while(cindex < m && cars[cindex].a <= time)
            {
                qs[cars[cindex].side].push(cars[cindex]);
                ++cindex;
            }
            
            // Ferry takes care of the cars
            int loaded = 0;
            while(!(qs[fside].empty()) && loaded < n)
            {
                cars[ qs[fside].front().order ].a2 = time + t;
                qs[fside].pop();
                ++loaded;
            }
            
            // Ferry moves
            if(loaded || !qs[!fside].empty())
            {
                time += t;
                fside = !fside;
            }
            else
            {
                time = cars[cindex].a;
            }
        }
        
        for(int i = 0; i < m; ++i)
        {
            cout << cars[i].a2 << endl;
        }
        
        if(tcase < cases-1)
            cout << endl;
    }
    
    return 0;
}
