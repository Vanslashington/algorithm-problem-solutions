#include <iostream>

using namespace std;

int main()
{
    for(int x = 0; x < 200; ++x)
    {
        int a = 100 * ((2 * ((x + 15) / 32)) / (1 + ((x + 15) / 32)));
        int b = (1/ ( (17/ (x+1) ) +1) )*100;
    
        cout << x << ": " << a << " " << b << endl;
    }
    
    return 0;
}
