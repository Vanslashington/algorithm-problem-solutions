#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

vi towers;
vector<vi> tcas;
vi cas;

int main()
{
    int planned, actual;
    cin >> planned >> actual;
    int tcase = 0;
    
    bool first = true;
    
    while(planned != 0)
    {
        towers.resize(planned);
        for(int i = 0; i < planned; ++i)
            cin >> towers[i];
        
        int careas;
        cin >> careas;
        
        tcas.clear();
        tcas = vector<vi>(planned, vector<ll>());
        cas.resize(careas);
        
        for(int i = 0; i < careas; ++i)
        {
            int nt;
            cin >> nt;
            
            for(int j = 0; j < nt; ++j)
            {
                int tnum;
                cin >> tnum;
                
                tcas[tnum-1].push_back(i);
            }
            
            cin >> cas[i];
        }
        
        for(int i = 0; i < planned; ++i)
            for(int j = 0; j < tcas[i].size(); ++j)
                towers[i] -= cas[tcas[i][j]];
        
        vector<bool> chosen(planned, false);
        for(int i = 0; i < actual; ++i)
            chosen[i] = true;
        
        ll max = 0;
        set<int> chosenAreas;
        ll covered;
        vector<bool> maxchosen = chosen;
        
        do
        {
            covered = 0;
            chosenAreas.clear();
            for(int i = 0; i < planned; ++i)
                if(chosen[i])
                {
                    covered += towers[i];
                    int s = tcas[i].size();
                    for(int j = 0; j < s; ++j)
                        chosenAreas.insert(tcas[i][j]);
                }
                    
            for(set<int>::iterator it = chosenAreas.begin();
                        it != chosenAreas.end(); ++it)
            { covered += cas[(*it)]; }
            
            if(covered > max)
            {
                max = covered;
                maxchosen = chosen;
            }
        }
        while(prev_permutation(chosen.begin(), chosen.end()));
            
        first = false;
        
        cout << "Case Number  " << ++tcase << endl;
        cout << "Number of Customers: " << max << endl;
        cout << "Locations recommended: ";
        
        int printed = 0;
        for(int i = 0; i < planned; ++i)
            if(maxchosen[i])
            {
                ++printed;
                cout << i+1 << (printed < actual ? ' ' : '\n');
            }
        cout << endl;
        
        cin >> planned >> actual;
    }
    
    return 0;
}
