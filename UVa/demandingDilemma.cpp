#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <utility>

using namespace std;
typedef pair<int,int> ii;
typedef set<ii> sii;

int rows, cols;
int colSums[30];
ii colVerts[30];
sii edges;

int main()
{
    int cases;
    cin >> cases;
    
    for(int tcase = 0; tcase < cases; ++tcase)
    {
        bool good = true;
        memset(colSums, 0, sizeof(colSums));
        edges.clear();
        
        cin >> rows >> cols;
        for(int i = 0; i < rows; ++i)
        {
            int bit;
            
            for(int j = 0; j < cols; ++j)
            {
                scanf("%i", &bit);
                colSums[j] += bit;
                
                if(colSums[j] == 1 && bit == 1)
                    colVerts[j].first = i;
                    
                else if(colSums[j] == 2 && bit == 1)
                {
                    colVerts[j].second = i;
                    if(edges.count(colVerts[j]))
                        good = false;
                    else
                        edges.insert(colVerts[j]);
                }
            }
        }
        
        for(int i = 0; i < cols; ++i)
            if(colSums[i] != 2)
            {
                good = false;
                break;
            }
        
        printf("%s\n", good ? "Yes" : "No");
    }
    
    return 0;
}
