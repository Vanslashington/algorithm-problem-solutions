#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

struct city
{
    string name;
    string os;
    int val;
};

typedef vector<city> vs;
typedef long long ll;

ll table[1001][1001];
int bcount[1001][1001];

void solve()
{
    memset(table, 0, sizeof(table));
    memset(bcount, 0, sizeof(bcount));
    vs north, south;
    int numNorth, numSouth;

    cin >> numNorth;
    north.resize(numNorth);
    for(int i = 0; i < numNorth; ++i)
        cin >> north[i].name >> north[i].os >> north[i].val;

    cin >> numSouth;
    south.resize(numSouth);
    for(int i = 0; i < numSouth; ++i)
        cin >> south[i].name >> south[i].os >> south[i].val;

    for(int i = 1; i <= numNorth; ++i)
        for(int j = 1; j <= numSouth; ++j)
            if(north[i-1].os == south[j-1].os
               && north[i-1].val + south[j-1].val != 0)
            {
                table[i][j] = north[i-1].val + south[j-1].val + table[i-1][j-1];
                bcount[i][j] = bcount[i-1][j-1] + 1;
            }
            else
            {
                bool iVal, jVal;
                if(table[i][j-1] != table[i-1][j])
                    iVal = table[i][j-1] < table[i-1][j];
                else
                    iVal = bcount[i][j-1] > bcount[i-1][j];
                jVal = !iVal;

                table[i][j] = table[i-iVal][j-jVal];
                bcount[i][j] = bcount[i-iVal][j-jVal];
            }

    cout << table[numNorth][numSouth] << " " << bcount[numNorth][numSouth]
         << endl;
}

int main()
{
    int t;
    for(cin >> t; t; --t)
        solve();

    return 0;
}
