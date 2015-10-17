#include <iostream>
using namespace std;

int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        int premium = 0;
        int f;
        cin >> f;
        
        int size, num, env;
        for(int i = 0; i < f; ++i)
        {
            cin >> size >> num >> env;
            premium += size*env;
        }
        
        cout << premium << endl;
    }
    
    return 0;
}
