#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    string s;
    
    while(getline(cin, s))
    {
        list<char> l;
        list<char>::iterator it = l.begin();
        int size = s.length();
        
        for(int i = 0; i < size; ++i)
        {
            if(s[i] == '[')
            {
                it = l.begin();
            }
            else if(s[i] == ']')
            {
                it = l.end();
            }
            else
            {
                l.insert(it, s[i]);
            }
        }
        
        for(it = l.begin(); it != l.end(); ++it)
        {
            cout << *it;
        }
        cout << endl;
    }
    
    return 0;
}
