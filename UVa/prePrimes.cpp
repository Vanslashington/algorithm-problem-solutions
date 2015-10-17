#include <bitset>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>

using namespace std;


bitset<1000000> sieve;


int main()
{
    ofstream fout;
    fout.open("prePrimes.txt");

    sieve.reset(); sieve.flip();
    sieve[0] = sieve[1] = false;
    
    fout << "2";
    for(int i = 4; i < 1000000; i += 2)
        sieve.reset(i);
        

    int count = 1;

    for(int i = 3; i < 1000000; i += 2)   
        if(sieve[i])
        {
            fout << ", " << i;
            ++count;

            if(count % 10 == 0)
                fout << endl;

            if(i >= 1000)
                continue;

            for(int j = i*i; j < 1000000; j += i)
                sieve.reset(j);
        }
    cout << endl;

    return 0;
}
