#include <set>
#include <utility>
#include <iostream>

using namespace std;

int main()
{
    int ndays;
    cin >> ndays;
    
    while(ndays != 0)
    {
        set<pair<int,int> > urn;
        urn.clear();
        unsigned long long payout = 0;
        int tbills = 0;
        
        for(int day = 0; day < ndays; ++day)
        {
            int nbills;
            cin >> nbills;
            
            // Bills go in urn
            for(int billn = 0; billn < nbills; ++billn, ++tbills)
            {
                int tempbill;
                cin >> tempbill;
                urn.insert(pair<int,int>(tempbill, tbills));
            }
            
            // Payout and discard
            //cout << "|" << urn.rbegin()->first << " " << urn.begin()->first << "|";
            payout += urn.rbegin()->first - urn.begin()->first;
            set<pair<int,int> >::iterator it = urn.end();
            --it;
            
            urn.erase(it);
            urn.erase(urn.begin());
        }
        cout << payout << endl;
        
        cin >> ndays;
    }
    
    return 0;
}
