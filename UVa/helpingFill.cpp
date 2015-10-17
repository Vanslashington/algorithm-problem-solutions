#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <set>
#include <bitset>
#include <stack>

using namespace std;

typedef pair<char,int> ci;
typedef pair<ci, int> pci;
typedef set<pci> sci;

sci students;
stack<pci> toadd;

vector<ci> query;


bool pcomp(pci p1, pci p2)
{return p1.first.first < p2.first.first;}

bool bscomp(pci p, char c)
{return p.first.first < c;}


bool match()
{
    for(vector<ci>::iterator it = query.begin(); it != query.end(); ++it)
    {
        
    }
}


int main()
{
    // Get S
    char c;
    char tc;
    scanf("%c", &c);
    int id = 0;
    while(c != '\n')
    {
        tc = c;
        ci temp(c, 1);
        scanf("%c", &c);
        while(tc == c && c != '\n')
        {
            ++(temp.second);
            scanf("%c", &c);
        }
        
        students.insert(pci(temp, id));
        ++id;
    }
    
    stable_sort(students.begin(), students.end(), pcomp);
    
    // Get num queries
    int queries;
    scanf("%i", queries);
    
    // Get each query
    for(int q = 0; q < queries; ++q)
    {
        while(!toadd.empty())
        {
            students.insert(toadd.top());
            toadd.pop();
        }
        
        query.clear();
        scanf("%c", &c);
        while(c != '\n')
        {
            tc = c;
            ci temp(c, 1);
            scanf("%c", &c);
            while(tc == c && c != '\n')
            {
                ++(temp.second);
                scanf("%c", &c);
            }
            
            query.push_back(temp);
        }
        
        match();
    }
    
    return 0;
}
