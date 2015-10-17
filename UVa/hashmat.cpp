#include <iostream>

using namespace std;

int main()
{
    long long a, b, d;
    
    while(cin >> a >> b)
    {
        d = b - a;
        
        if(d < 0)
        {
            d *= -1;
        }
        
        cout << d << endl;
    }
    
    return 0;
}
