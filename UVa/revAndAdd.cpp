#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

typedef long long ll;

deque<int> itodq(ll num)
{
    deque<int> ret;
    
    while(num != 0)
    {
        ret.push_front(num % 10);
        num /= 10;
    }
    
    return ret;
}

int dqtoi(deque<int>& dnum)
{
    int place = 1;
    int num = 0;
    
    for(deque<int>::reverse_iterator rit = dnum.rbegin();
        rit != dnum.rend(); ++rit, place *= 10)
    {
        num += (*rit * place);
    }
    
    return num;
}

bool pal(ll num)
{
    deque<int> temp = itodq(num);
    reverse(temp.begin(), temp.end());
    
    return(itodq(num) == temp);
}

int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        ll num;
        cin >> num;
        
        int its = 0;
        
        while(!pal(num))
        {
            ++its;
            
            deque<int> temp = itodq(num);
            reverse(temp.begin(), temp.end());
            num += dqtoi(temp);
        }
        
        cout << its << " " << num << endl;
    }
    
    return 0;
}
