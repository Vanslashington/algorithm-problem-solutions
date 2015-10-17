#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s, t;
int slen, tlen;
vector<int> earliest;

bool subSeq(int sInd, int tInd)
{
    if(sInd == slen)
        return true;
        
    if(tInd == tlen)
        return false;

    for(int i = (earliest[sInd] == -1 ? tInd : earliest[sInd]); i < tlen; ++i)
        if(s[sInd] == t[i])
        {
            
            if(subSeq(sInd+1, i+1))
                return true;
                
            earliest[sInd] = i + 2;
        }
    
    
    
    return false;
}

int main()
{
    while(cin >> s >> t)
    {
        slen = s.size();
        tlen = t.size();
        
        earliest = vector<int>(slen, -1);
        
        bool good = false;
        for(int i = 0; i < tlen; ++i)
            if(s[0] == t[i])
                if(subSeq(0, i))
                {
                    cout << "Yes\n";
                    good = true;
                    break;
                }
                
        if(!good)
            cout << "No\n";
    }
    
    return 0;
}
