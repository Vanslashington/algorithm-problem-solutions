#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

float h, m;
float diff;
char colon;

int main()
{
    scanf("%f %c %f", &h, &colon, &m);
    while(h != 0.0)
    {
        if(h == 12.0)
            h = 0.0;
            
        h *= 30.0;
        m *= 6.0;
        
        h += ((m / 360.0) * 30.0);
        
        diff = abs(h - m);
        
        if(diff > 180.0)
            diff = 360.0 - diff;
        
        printf("%.3f\n", diff);
        
        scanf("%f %c %f", &h, &colon, &m);
    }
    
    return 0;
}
