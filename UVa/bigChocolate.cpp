#include <cstdio>

using namespace std;

int main()
{
    int m, n;
    while(scanf("%i%i", &m, &n) != EOF)
        printf("%i\n", m*n - 1);
    
    return 0;
}
