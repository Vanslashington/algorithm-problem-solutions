#include <iostream>
#include <cmath>

using namespace std;

double n, p;

int main()
{
    while(cin >> n >> p)
        cout << int(floor(pow(p, 1.0/n) + 0.5)) << endl;
    
    return 0;
}
