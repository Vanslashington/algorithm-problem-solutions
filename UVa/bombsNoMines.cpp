#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <bitset>
#include <utility>
#include <map>
#include <cstring>

using namespace std;


typedef pair<int,int> ii;


int h, w;
vector<bitset<1000> > grid(1000);
int startX, startY;
int endX, endY;
int dist[1000][1000];
queue<pair<int,int> > bfs;


int main()
{
	while(cin >> h >> w && h != 0)
	{
		for(int i = 0; i < h; ++i)
			grid[i].reset();
		memset(dist, -1, sizeof(dist));
		while(!bfs.empty())
			bfs.pop();


		int nWithBombs;
		cin >> nWithBombs;

		for(int r = 0; r < nWithBombs; ++r)
		{
			int tRow, nBombs;
			cin >> tRow >> nBombs;

			for(int b = 0; b < nBombs; ++b)
			{
				int tCol;
				cin >> tCol;
				grid[tRow].set(tCol);
			}
		}
		
		cin >> startY >> startX;
		cin >> endY >> endX;

		dist[startY][startX] = 0;
		bfs.push(pair<int,int>(startY, startX));	
		
		while(!bfs.empty())
		{
			ii f = bfs.front();
			bfs.pop();
			int fy = f.first, fx = f.second;

			if(fy == endY && fx == endX)
				break;

			for(int i = fy-1; i <= fy+1; ++i)
				for(int j = fx-1; j <= fx+1; ++j)
					if((i == fy || j == fx) &&
					   (i != fy || j != fx) &&
					   (i >= 0) && (i < h) &&
					   (j >= 0) && (j < w) &&
					   (dist[i][j] == -1) &&
					   (!grid[i][j]))
					{
						dist[i][j] = dist[fy][fx] + 1;
						bfs.push(ii(i,j));
					} 
		}

		cout << dist[endY][endX] << endl;
	}	

	return 0;
}

















