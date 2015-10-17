#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;
typedef set<int> si;
typedef si::iterator sit;

const int WHITE = -1;

int numV;
si places[110];

int nArtPoints;

int numRChildren;
int dfsCount;
int dfsParent[110];
int dfsDepth[110];
int dfsLow[110];
bool dfsAP[110];


string line;


void countArtPoints(int place)
{
    dfsDepth[place] = dfsLow[place] = (dfsCount++);
    
    /*
    cout << endl;
    cout << "[" << place << "]" << endl;
    for(int i = 1; i <= numV; ++i)
    {
        cout << i << "(" << dfsDepth[i] << "," << dfsLow[i] << ")" << ": ";
        for(sit v = places[i].begin(); v != places[i].end(); ++v)
            cout << *v << " ";
        cout << endl;
    }*/
    
    for(sit c = places[place].begin(); c != places[place].end(); ++c)
    {
        if(dfsDepth[*c] == WHITE)
        {
            dfsParent[*c] = place;
            
            if(place == 1)
                ++numRChildren;
                
            countArtPoints(*c);
            
            //cout << endl << "( <- " << place << ")" << endl;
            
            if(dfsLow[*c] >= dfsDepth[place] && !dfsAP[place] && place != 1)
            {
                //cout << "AP:" << place <<endl;
                dfsAP[place] = true;
                ++nArtPoints;
            }
            
            // ?????
            if(dfsLow[*c] < dfsLow[place])
            {
                dfsLow[place] = dfsLow[*c];
            }
        }
        else if(*c != dfsParent[place])
            if(dfsDepth[*c] < dfsLow[place])
            {
                //cout << "<<" << place << "," << *c << ">>";
                dfsLow[place] = dfsDepth[*c];
            }
    }
    
    
}


int main()
{
    cin >> numV;
    while(numV != 0)
    {
        for(int i = 1; i <= 105; ++i)
            places[i].clear();
        
        int tempp; char d;
        scanf("%i", &tempp);
        scanf("%c", &d);
        
        while(tempp != 0)
        {
            getline(cin, line);
            stringstream ss;
            ss << line;
            
            int tempc;
            ss >> tempc;
            while(!ss.eof())
            {
                if(tempp != tempc)
                {
                    places[tempp].insert(tempc);
                    places[tempc].insert(tempp);
                }
                
                ss >> tempc;
            }
            if(tempp != tempc)
            {
                places[tempp].insert(tempc);
                places[tempc].insert(tempp);
            }
            
            scanf("%i", &tempp);
        }
        
        
        
        
        
        numRChildren = 0;
        dfsCount = 0;
        memset(dfsParent, 0, sizeof(dfsParent));
        memset(dfsDepth, WHITE, sizeof(dfsDepth));
        memset(dfsLow, WHITE, sizeof(dfsLow));
        memset(dfsAP, false, sizeof(dfsAP));
        
        /*
        for(int i = 1; i <= numV; ++i)
        {
            cout << i << "(" << dfsDepth[i] << "," << dfsLow[i] << ")" << ": ";
            for(sit v = places[i].begin(); v != places[i].end(); ++v)
                cout << *v << " ";
            cout << endl;
        }*/
        
        nArtPoints = 0;
        countArtPoints(1);
        
        /*
        cout << endl;
        for(int i = 1; i <= numV; ++i)
        {
            cout << i << "(" << dfsDepth[i] << "," << dfsLow[i] << ")" << ": ";
            for(sit v = places[i].begin(); v != places[i].end(); ++v)
                cout << *v << " ";
            cout << endl;
        }*/
        
        if(numRChildren > 1)
        {
            ++nArtPoints;
        }
            
        cout << nArtPoints << endl;
        
        cin >> numV;
    }
    
    return 0;
}
