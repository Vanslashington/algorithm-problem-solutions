#include <iostream>
#include <cstdio>
#include <deque>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<char,int> ci;
typedef deque<ci> dci;
typedef dci::iterator dit;

int n;
char c;
int u2l = 'A' - 'a';

dci counts(26, ci('A', 0));

bool dcicomp(ci a, ci b)
{return b.second < a.second;}


int main()
{
    cin >> n;
    
    for(int i = 0; i < 26; ++i)
        counts[i].first += i;
    
    while(scanf("%c", &c) != EOF)
    {
        if(c == '\n')
            continue;
        
        if(c >= 'a')
            c += u2l;
            
        if(c < 'A' || c > 'Z')
            continue;
            
        ++(counts[c - 'A'].second);
    }
    
    stable_sort(counts.begin(), counts.end(), dcicomp);
    
    for(int i = 0; i < 26; ++i)
        if(counts[i].second)
            printf("%c %i\n", counts[i].first, counts[i].second);
    
    return 0;
}
