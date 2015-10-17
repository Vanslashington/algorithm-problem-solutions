#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;
typedef stack<int> sti;

sti digits;
int mdec;

int main()
{
    char c;
    
    scanf("%c", &c);
    while(c != '0')
    {
        digits.push(c - '0');
        scanf("%c", &c);
        
        while(c != '\n')
        {
            digits.push(c - '0');
            scanf("%c", &c);
        }
        
        mdec = 0;
        
        for(int place = 1; !digits.empty(); place = place * 2 + 1)
        {
            mdec += place * digits.top();
            digits.pop();
        }
        
        cout << mdec << endl;
        scanf("%c", &c);
    }
    
    
    return 0;
}
