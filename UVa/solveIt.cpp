#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int p, q, r, s, t, u;
double x;

double equat()
{
    return
        p * exp(-1.0 * x) + 
        q * sin(x) +
        r * cos(x) +
        s * tan(x) +
        t * pow(x, 2.0) +
        u;
}

bool bs(double b, double e)
{
    x = (b + e) / 2.0;
    
    double ans = equat();
    ans = floor((100000.0 * ans) + 0.5) / 100000.0;
    
    if(ans != 0.0 && b == e)
        return false;
    else if(ans > 0.0)
        return bs(x, e);
    else if(ans < 0.0)
        return bs(b, x);
    else
        return true;
}


int main()
{
    while(scanf("%i%i%i%i%i%i", &p, &q, &r, &s, &t, &u) != EOF)
    {
        if(bs(0.0, 1.0))
            printf("%.4f\n", x);
        else
            printf("No solution\n");
    }
    
    return 0;
}
