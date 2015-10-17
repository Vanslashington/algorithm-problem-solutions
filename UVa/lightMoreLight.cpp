#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long double n;
long double s;

int main()
{
    cin >> n;
    
    while(n != 0.0)
    {
        s = sqrt(n);
        printf("%s", ((floor(s) == s) ? "yes\n" : "no\n"));
        
        cin >> n;
    }
    
    return 0;
}
