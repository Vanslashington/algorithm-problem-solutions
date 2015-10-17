#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;


string line;

typedef set<char> si;
typedef map<char,int> mci;
int maxFreq;


int main()
{
    while(getline(cin, line))
    {
        maxFreq = 0;
        si letters;
        mci freqs;
        
        for(int i = 0; i < line.size(); ++i)
        {
            if( !( (line[i] >= 'A' && line[i] <= 'Z')    || 
                   (line[i] >= 'a' && line[i] <= 'z') ))
            {
                continue;
            }
            
            if(!freqs.count(line[i]))
                freqs[line[i]] = 0;
            ++freqs[line[i]];
            
            if(freqs[line[i]] == maxFreq)
                letters.insert(line[i]);
            else if(freqs[line[i]] > maxFreq)
            {
                maxFreq = freqs[line[i]];
                letters.clear();
                letters.insert(line[i]);
            }
        }
        
        for(si::iterator sit = letters.begin();
                         sit != letters.end(); ++sit)
        {
            cout << *sit;
        }
        cout << " " << maxFreq << endl;
    }
    
    return 0;
}
