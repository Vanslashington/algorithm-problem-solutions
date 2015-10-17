#include <cstdio>
#include <map>
#include <queue>

using namespace std;
typedef map<int,int> mii;
typedef mii::iterator mii_it;


struct road
{ 
    int jA, jB, len;
    bool operator<(road other) const {return this->len >= other.len;}
};


int nJunctions, nRoads;
int savings;
priority_queue<road> roads;



mii pset;
int findSet(int j);
bool sameSet(int j1, int j2);
void setUnion(int j1, int j2);


int main()
{
    scanf("%i %i ", &nJunctions, &nRoads);
    while(nJunctions != 0)
    {
        while(!roads.empty())
            roads.pop();
        
        pset.clear();
        
        savings = 0;
        
        for(int i = 0; i < nRoads; ++i)
        {
            road temp;
            scanf("%i %i %i ", &temp.jA, &temp.jB, &temp.len);
            roads.push(temp);
            
            pset[temp.jA] = temp.jA;
            pset[temp.jB] = temp.jB;
            savings += temp.len;
        }
        
        for(int j = 0; j < nJunctions-1; )
        {
            road smallest = roads.top();
            roads.pop();
            if(!sameSet(smallest.jA, smallest.jB))
            {
                setUnion(smallest.jA, smallest.jB);
                savings -= smallest.len;
                ++j; 
            }
        }
        
        printf("%i\n", savings);
        
        scanf("%i %i ", &nJunctions, &nRoads);
    }
    
    return 0;
}




int findSet(int j)
{return (pset[j] == j ? j : pset[j] = findSet(pset[j]));}

bool sameSet(int j1, int j2)
{return findSet(j1) == findSet(j2);}

void setUnion(int j1, int j2)
{pset[findSet(j1)] = findSet(j2);}
