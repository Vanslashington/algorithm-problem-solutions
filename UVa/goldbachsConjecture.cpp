#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;


bitset<1000001> sieve;
vector<int> primes;
typedef vector<int>::iterator vi_it;

int num;

void findPrimes()
{
    vi_it up = lower_bound(primes.begin(), primes.end(), num);
    --up;
    
    while(sieve[(num - *up)] || (num - *up) % 2 == 0)
        --up;
    
    printf("%i = %i + %i\n", num, (num - *up), *up);
}


int main()
{
    sieve.reset();
    
    sieve.set(0);
    sieve.set(1);
    primes.push_back(2);
    
    for(int i = 3; i < 1000000; i += 2)
    {
        if(!sieve[i])
        {
            primes.push_back(i);
            
            if(i >= 1000)
                continue;
            
            for(int j = i * i; j < 1000000; j += i)
                sieve.set(j);
        }
    }
    primes.push_back(1000000);
    
    
    scanf("%i", &num);
    while(num != 0)
    {
        findPrimes();
        
        scanf("%i", &num);
    }
    
    
    return 0;
}
