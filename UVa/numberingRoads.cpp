#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;


int numRoads, numInts;


int main()
{
    int tcase = 0;

    cin >> numRoads >> numInts;
    while(numRoads != 0 || numInts != 0)
    {
        int numGroups = ceil(double(numRoads) / numInts);
        int lettersNeeded = (numGroups > 0 ? numGroups-1 : 0);

        printf("Case %i: ", ++tcase);
        if(lettersNeeded <= 26)
            cout << lettersNeeded;
        else
            cout << "impossible";
        cout << endl;

        cin >> numRoads >> numInts;
    }

    return 0;
}
