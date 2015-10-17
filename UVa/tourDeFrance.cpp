#include <iostream>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;


vector<int> rearc;
vector<int> frontc;

set<double> ratios;

int main()
{
    int rsize, fsize;
    
    while(cin >> fsize && cin >> rsize)
    {
        rearc.resize(rsize);
        frontc.resize(fsize);
        ratios.clear();
        
        for(int i = 0; i < fsize; ++i)
            cin >> frontc[i];
            
        for(int i = 0; i < rsize; ++i)
            cin >> rearc[i];
            
        for(int i = 0; i < rsize; ++i)
            for(int j = 0; j < fsize; ++j)
                ratios.insert(double(rearc[i]) / double(frontc[j]));
                
        double max = -1.0;
        set<double>::iterator it = ratios.begin(), it2 = ratios.begin(); ++it2;
        for(; it2 != ratios.end(); ++it, ++it2)
        {
            double div = (*(it2)) / (*it);
            
            if(div > max)
                max = div;
        }
        
        cout << fixed << setprecision(2);
        cout << max << endl;
    }
    
    return 0;
}
