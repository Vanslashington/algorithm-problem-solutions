#include <iostream>
#include <string>
#include <map>

using namespace std;

string k = "  `1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
map<char,char> c;
string s;

int main()
{
    for(int i = 1; i < k.size(); ++i)
        c[k[i]] = k[i-1];
    
    while(getline(cin, s))
    {
        for(int i = 0; i < s.size(); ++i)
            cout << c[s[i]];
        cout << endl;
    }
    
    return 0;
}
