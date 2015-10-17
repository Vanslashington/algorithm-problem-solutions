#include <cstdio>
#include <map>

using namespace std;

/*int f91(int n)
{
    if(n < 101) return f91(f91(n + 11));
    else        return n - 10;
}*/

int main()
{
    int n;
    scanf("%i", &n);
    
    while(n)
    {
        printf("f91(%i) = %i\n", n, /*f91(n)*/ (n < 101 ? 91 : n - 10));
        scanf("%i", &n); 
    }
    
    return 0;
}
