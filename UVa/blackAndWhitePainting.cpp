#include <iostream>

using namespace std;


int n, m, c;


int main()
{
    cin >> n >> m >> c;

    while(n)
    {
        if(c && n == 8 && m == 8)
            cout << 1 << endl;
        else
        {
            cout << (((n-7) * (m-7)) + c) / 2;
            cout << endl;
        }

        cin >> n >> m >> c;
    }

    return 0;
}
