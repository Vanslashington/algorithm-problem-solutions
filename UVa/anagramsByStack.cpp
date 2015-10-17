#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string s;
string d;
vector<string> io;

void look(int sI, int dI, string log, stack<char> reserve)
{
    if(sI == s.length())
        return;
    
    reserve.push(s[sI]);
    ++sI;
    log += "i";
    while(dI < d.length() && ((!reserve.empty() && reserve.top() == d[dI]) 
                                || sI < s.length()))
    {
        while((reserve.empty() || reserve.top() != d[dI]) && sI < s.length())
        {
            reserve.push(s[sI]);
            ++sI;
            log += "i";
        }
        
        while(!reserve.empty() && dI < d.length() && reserve.top() == d[dI])
        {
            look(sI, dI, log, reserve);
            reserve.pop();
            ++dI;
            log += "o";
        }
    }
    
    if(dI == d.length())
    {
        io.push_back(log);
    }
}

bool lComp(string l, string r)
{
    return (lexicographical_compare(l.begin(), l.end(), r.begin(), r.end()));
}

int main()
{
    while(cin >> s >> d)
    {
        io.clear();
        look(0, 0, string(""), stack<char>());
        sort(io.begin(), io.end(), lComp);
        
        cout << "["<< endl;
        for(int i = 0; i < io.size(); ++i)
        {
            int j;
            for(j = 0; j < io[i].length() - 1; ++j)
            {
                cout << io[i][j] << " ";
            }
            cout << io[i][j] << endl;
        }
        cout << "]" << endl;
    }
    
    return 0;
}
