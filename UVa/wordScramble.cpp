#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

string line, word;
stringstream ss;

int main()
{
    while(getline(cin, line))
    {
        ss.str("");
        ss.clear();
        
        ss << line;
        
        ss >> word;
        reverse(word.begin(), word.end());
        cout << word;
        
        while(ss >> word)
        {
            reverse(word.begin(), word.end());
            cout << " " << word;
        }
        cout << endl;
    }
    
    return 0;
}
