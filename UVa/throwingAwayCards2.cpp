#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;


int nCards;


int main()
{
    cin >> nCards;
    while(nCards)
    {
        int p = pow(2.0, double(ceil((log(nCards))/(log(2)))));
        cout << 2*nCards - p << endl;
        cin >> nCards;
    }

    return 0;
}
