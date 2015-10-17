#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    
    int sum, diff;
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        cin >> sum >> diff;
        
        bool sumEven = (sum % 2 == 0);
        if(diff > sum || ((diff % 2 == 0) != sumEven))
        {
            cout << "impossible\n";
            continue;
        }
        
        cout << sum - ((sum - diff) / 2) << " " << (sum - diff) / 2 << endl;
    }
    
    return 0;
}
