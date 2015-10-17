#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef double dub;


void con(dub &num)
{
    num *= 100;
    num = floor(num);
    num /= 100;
}


int main()
{
    cout << fixed << setprecision(2);
    
    int asdf = 0;
    
    for(dub i = 20.00; i >= .01; i -= .01)
    {
        if(i * i * i * i < i + i + i + i) break;
        
        for(dub j = 20.00 - i; j >= .01; j -= .01)
        {
            if(j > i) break;
            if(i * j * j * j < i + j + j + j) break;
            
            for(dub k = 20.00 - (i + j); k >= .01; k -= .01)
            {
                if(k > j) break;
                if(i * j * k * k < i + j + k + k) break;
                
                for(dub l = 20.00 - (i + j + k); l >= .01; l -= .01)
                {
                    if(l > k) break;
                    if(i * j * k * l < i + j + k + l) break;
                    
                    
                    dub x, y;
                    dub a = x = i * j * k * l;
                    dub b = y = i + j + k + l;
                    
                    con(a);
                    con(b);
                    
                    if(a != x || b != y)
                        break;
                    
                    if(a == b)
                    cout << l << ", "
                         << k << ", "
                         << j << ", "
                         << i << ", " << endl;
                }
            }
        }
    }
    
    return 0;
}
