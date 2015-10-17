#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        int l;
        cin >> l;
        
        int swaps = 0;
        
        if(l > 1)
        {
            int trains[l];
            for(int i = 0; i < l; ++i)
                cin >> trains[i];
            
            bool swapped;
            
            do
            {
                swapped = false;
                
                for(int i = 1; i < l; ++i)
                {
                    if(trains[i-1] > trains[i])
                    {
                        int temp = trains[i-1];
                        trains[i-1] = trains[i];
                        trains[i] = temp;
                        
                        ++swaps;
                        swapped = true;
                    }
                }
            }
            while(swapped);
        }
        
        cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
        
        int d;
        if(l == 1)
            cin >> d;
    }
    
    return 0;
}
