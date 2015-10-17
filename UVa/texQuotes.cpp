#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    bool back = true;
    while(getline(cin, s))
    {
        int l = s.length();
        for(int i = 0; i < l; ++i)
        {
            if(s[i] == '\"')
            {
                cout << (back ? "``" : "''");
                back = !back;
            }
            else
            {
                cout << s[i];
            }
        }
        
        cout << endl;
    }
    
    return 0;
}
