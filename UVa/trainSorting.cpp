#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>

using namespace std;
typedef deque<int> di;

int numCars, lsize;

di cars;
int lens[4000];


int longest(int index)
{
    if(index == 0)
        return 1;
        
    if(lens[index])
        return lens[index];
        
    int maxl = 0;
    for(int i = index-1; i >= 0; --i)
        if(cars[i] > cars[index])
            maxl = max(maxl, longest(i));
        
    return (lens[index] = maxl + 1);
}


int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        cin >> numCars;
        lsize = numCars * 2;
        
        cars.clear();
        
        memset(lens, 0, sizeof(lens));
        
        int c;
        for(int i = 0; i < numCars; ++i)
        {
            scanf("%i", &c);
            cars.push_front(c);
            cars.push_back(c);
        }
        
        int maxl = 0;
        for(int i = lsize - 1; i >= 0; --i)
            maxl = max(maxl, longest(i));
            
        cout << maxl << endl;
    }
    
    return 0;
}
