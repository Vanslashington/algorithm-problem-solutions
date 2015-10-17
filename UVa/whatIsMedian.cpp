#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;


typedef multiset<long> si;
typedef si::iterator si_it;

si nums;
si_it mid, midp;


int main()
{
    long num;
    int count = 1;
    
    cin >> num;
    
    nums.insert(num);
    mid = nums.begin();
    
    cout << *mid << endl;
    
    while(scanf("%li", &num) != EOF)
    {
        nums.insert(num);
        ++count;
        
        if(count % 2 != 0)
        {
            if(num > *mid)
                ++mid;
                
            cout << *mid << endl;
        }
        else 
        {
            if(num <= *mid)
                --mid;
            
            midp = mid;
            ++midp;
            cout << (*mid + *midp) / 2 << endl;
        }
    }
    
    return 0;
}
