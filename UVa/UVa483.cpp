#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string line = "";
	vector<string> lines;
	char character;
	
	int startIndex, endIndex;
	
	ifstream fin;
	fin.clear();
	fin.open("483.txt");
	
	getline(fin, line, '\n');
	
	while(fin.good())
	{
		lines.push_back(line);
		
		getline(fin, line, '\n');
	}
	
	for(int lineNum = 0; lineNum < lines.size(); lineNum++)
	{
		for(int i = 0; i < lines[lineNum].length(); i++)
		{
			if(lines[lineNum][i] != ' ')
			{
				startIndex = i;
				endIndex = lines[lineNum].length() - 1;
				
				for(int j = i; 
					j < lines[lineNum].length() && 
					lines[lineNum][j] != ' '; 
					j++)
				{
					endIndex = j;
				}
				
				for(int left = startIndex, right = endIndex;
					left < right;
					left++, right--)
				{
					lines[lineNum][left] ^= lines[lineNum][right];
					lines[lineNum][right] ^= lines[lineNum][left];
					lines[lineNum][left] ^= lines[lineNum][right];
				}
				
				i = endIndex + 1;
			}
		}
		
		cout << lines[lineNum] << endl;
	}

	return 0;
}
