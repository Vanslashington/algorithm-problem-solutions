#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int FAIL = -1000000000;

int bags[20];
int memo[201][20];

int target = 0;
bool done = false;

int numBags = 0;

char s[4];

int load(int weightLeft, int bag)
{
    if(weightLeft < 0)
        return FAIL;
        
    if(bag == numBags)
        return target - weightLeft;
    
    if(memo[weightLeft][bag] != -1)
        return memo[weightLeft][bag];
        
    return memo[weightLeft][bag] = 
        max(load(weightLeft, bag + 1), load(weightLeft - bags[bag], bag + 1));
}

int main()
{
    int tcases;
    char c;
    scanf("%i%c", &tcases, &c);
    
    for(int tcase = 0; tcase < tcases; ++tcase)
    {
        numBags = 0;
        char c;

        scanf("%s", s);
        if(s == "\n")
        {
            cout << "YES\n";
            continue;
        }

        bags[numBags++] = atoi(s);
        
        scanf("%c", &c);
        
        if(c != '\n')
        {
            scanf("%i%c", &bags[numBags++], &c);
            while(c != '\n')
                scanf("%i%c", &bags[numBags++], &c);
        }
        
        target = 0;
        for(int i = 0; i < numBags; ++i)
        {
            target += bags[i];
        }

        
        if(target % 2 == 1)
        {
            cout << "NO\n";
            continue;
        }
        
        target /= 2;
        
        memset(memo, -1, sizeof(memo));
        
        if(target - load(target, 0) == 0)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    
    return 0;
}
