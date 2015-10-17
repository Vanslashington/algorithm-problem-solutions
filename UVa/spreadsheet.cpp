#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<ii, vii> mvii;
typedef vii::iterator vii_it;
typedef mvii::iterator mvii_it;

typedef pair<int,bool> ib;
typedef vector<vector<ib> > vib;
vib grid;

int rows, cols;

ii coord(const string& s)
{
    ii ret(0,0);
    int i = s.size()-1;
    while(s[i] < 'A' || s[i] > 'Z') --i;
    int charCount = 0;
    int place = 1;
    while(i >= 0)
    {
        ret.second += (s[i--] - 'A') * place;
        place *= 26;
        ++charCount;
    }
    stringstream myStream(s);
    char dummy;
    for(i = 0; i < charCount; ++i) myStream.get(dummy);
    myStream >> ret.first;
    --ret.first;

    return ret;
}

int getVal(const ii& thisCoord, mvii& graph)
{
    if(grid[thisCoord.first][thisCoord.second].second)
    {
        grid[thisCoord.first][thisCoord.second].second = false; 
        grid[thisCoord.first][thisCoord.second].first = 0;

        for(vii_it i = graph[thisCoord].begin();
                   i != graph[thisCoord].end(); ++i)
        {
            grid[thisCoord.first][thisCoord.second].first += getVal(*i, graph);
        }
    }
    
    return grid[thisCoord.first][thisCoord.second].first;
}

void solve()
{
    mvii graph;
    cin >> cols >> rows;

    if(rows > grid.size()) grid.resize(rows);
    if(cols > grid[0].size())
        for(int i = 0; i < rows; ++i)
            grid[i].resize(cols);

    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
        {
            string inCell;
            cin >> inCell;
            stringstream inCellStream(inCell);
            if(inCell[0] == '=')
            {
                grid[i][j].second = true;
                string coordStr;
                char dummy;
                inCellStream.get(dummy);
                while(getline(inCellStream, coordStr, '+'))
                    graph[ii(i,j)].push_back(coord(coordStr));
            }
            else
            {
                inCellStream >> grid[i][j].first;
                grid[i][j].second = false;
            }    
        }

    for(mvii_it i = graph.begin(); i != graph.end(); ++i)
        getVal(i->first, graph);

    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
            cout << grid[i][j].first << (j < cols-1 ? ' ' : '\n');
}


int main()
{
    int t;
    for(cin >> t; t; --t)
    {
        solve();
        if(t > 1) cout << endl;
    }
    return 0;
}
