#include <iostream>
#include <string>

using namespace std;

bool letter(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int main()
{
    string s;
    while(getline(cin, s))
    {
        int i;
        int count = 0;
        int l = s.length();
        for(i = 0; i < l; ++i)
        {
            for(; i < l && !letter(s[i]); ++i)
            {}
            
            if(i == l)
                break;
            
            ++count;
            
            for(; i < l && letter(s[i]); ++i)
            {}
            
            if(i == l)
                break;
        }
        
        cout << count << endl;
    }
    
    return 0;
}
