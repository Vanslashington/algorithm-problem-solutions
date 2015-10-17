#include <iostream>
#include <map>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        int nflakes;
        cin >> nflakes;
        int max = 0;
        int count = 0;
        int cutoff = 0;
        
        map<int,int> sindex;
        
        for(int i = 0; i < nflakes; ++i)
        {
            int flake;
            cin >> flake;
            
            if(!sindex.count(flake) || sindex[flake] < cutoff)
            {
                ++count;
            }
            else
            {
                if(count > max)
                    max = count;
                    
                count = i - sindex[flake];
                cutoff = sindex[flake] + 1;
            }
            
            sindex[flake] = i;
        }
        if(count > max)
            max = count;
        
        cout << max << endl;
    }
    
    return 0;
}
