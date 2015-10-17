#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef set<char> sc;
typedef vector<sc> vsc;
typedef set<char>::iterator scit;

vsc lock1;
vsc lock2;
int k;

void findkth()
{
    int num = 0;
    
    for(scit c0 = lock1[0].begin(); c0 != lock1[0].end(); ++c0)
    for(scit c1 = lock1[1].begin(); c1 != lock1[1].end(); ++c1)
    for(scit c2 = lock1[2].begin(); c2 != lock1[2].end(); ++c2)
    for(scit c3 = lock1[3].begin(); c3 != lock1[3].end(); ++c3)
    for(scit c4 = lock1[4].begin(); c4 != lock1[4].end(); ++c4)
    {
        if( lock2[0].count(*c0) && 
            lock2[1].count(*c1) && 
            lock2[2].count(*c2) && 
            lock2[3].count(*c3) && 
            lock2[4].count(*c4))
            
            ++num;
            
        if(num == k)
        {
            cout << *c0 << *c1 << *c2 << *c3 << *c4 << endl;
            return;
        }
    }
    
    cout << "NO" << endl;
}

int main()
{
    int cases;
    cin >> cases;
    
    lock1.resize(5);
    lock2.resize(5);
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        cin >> k;
        
        for(int i = 0; i < 5; ++i)
        {
            lock1[i].clear();
            lock2[i].clear();
        }
        
        for(int row = 0; row < 6; ++row)
            for(int col = 0; col < 5; ++col)
            {
                char temp;
                cin >> temp;
                
                lock1[col].insert(temp);
            }
            
        for(int row = 0; row < 6; ++row)
            for(int col = 0; col < 5; ++col)
            {
                char temp;
                cin >> temp;
                
                lock2[col].insert(temp);
            }
            
        findkth();
    }
    
    return 0;
}
