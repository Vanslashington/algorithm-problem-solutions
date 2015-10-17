#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_LEN = 1000;
int lcsTable[MAX_LEN][MAX_LEN];

string s1, s2;
int s1Len, s2Len;

int main()
{
    while(getline(cin, s1) && getline(cin, s2))
    {
        s1Len = s1.length();
        s2Len = s2.length();

        memset(lcsTable, 0, sizeof(lcsTable));
        for(int i = 1; i <= s1Len; ++i)
            for(int j = 1; j <= s2Len; ++j)
                if(s1[i-1] == s2[j-1])
                    lcsTable[i][j] = lcsTable[i-1][j-1] + 1;
                else
                    lcsTable[i][j] = max(lcsTable[i][j-1], lcsTable[i-1][j]);

        cout << lcsTable[s1Len][s2Len] << endl;
    }

    return 0;
}
