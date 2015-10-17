#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;

    for(int tcase = 1; tcase <= cases; ++tcase)
    {
        int a, b;
        cin >> a >> b;

        int sum = 0;

        for(int i = a; i <= b; ++i)
            sum += (i%2 == 1 ? i : 0);

        cout << "Case " << tcase << ": " << sum << endl;
    }

    return 0;
}
