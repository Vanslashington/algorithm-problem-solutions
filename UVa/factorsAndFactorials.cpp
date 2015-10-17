#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cstring>

using namespace std;


typedef vector<int> vi;
typedef vi::iterator vi_it;

bitset<100> sieve;
vi primes;

bool isPrime(int n)
{ return (!sieve[n] && n % 2 != 0); }


int num;
int pFreqs[100];


int main()
{
    sieve.set(0);
    sieve.set(1);
    sieve.set(2);
    primes.push_back(2);
    
    for(int i = 3; i < 100; i += 2)
    {
        if(!sieve[i])
        {
            primes.push_back(i);
            for(int m = i*i; m < 100; m += i)
                sieve.set(m);
        }
    }
    
    
    cin >> num;
    while(num)
    {
        memset(pFreqs, 0, sizeof(pFreqs));
        
        for(int step = num; step >= 2; --step)
        {
            int tnum = step;
            for(int pInd = 0; tnum != 1; ++pInd)
            {
                while(tnum % primes[pInd] == 0)
                {
                    tnum /= primes[pInd];
                    ++pFreqs[pInd];
                }
            }
        }
        
        
        printf("%3i! =", num);
        for(int i = 0; pFreqs[i] != 0; ++i)
        {
            if(i != 0 && i % 15 == 0)
                cout << "\n      ";
            printf("%3i", pFreqs[i]);
            
        }
        cout << endl;
        
        
        cin >> num;
    }
    
    return 0;
}
