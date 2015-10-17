#include <cmath>
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long tType;


tType num;

int maxSize()
{return ceil(sqrt(.25+2.0*double(num))-.5);}



int main()
{
    cin >> num;
    while(num > -1)
    {
        tType b;
        tType ms;

        if(num == 1 || num == 0)
        {
            b = num;
            ms = 1;
        }
        else
        {
            for(ms = maxSize(); true; --ms)
            {
                if(((ms % 2 == 1) && (num % ms == 0)))
                {
                    b = (num/ms) - ((ms - 1)/2);
                    break;
                }
                else if(((ms % 2 == 0) && (num % ms == ms/2)))
                {
                    b = ((num + (ms/2))/ms) - (ms/2);
                    break;
                }
            }
        }

        printf("%lli = %lli + ... + %lli\n", num, b, b + ms - 1);

        cin >> num;
    }

    return 0;
}
