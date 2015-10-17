#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <map>

using namespace std;

struct array
{
	int base, elementSize, numDimensions;
	vector<pair<int, int> > bounds;
};

int main()
{
	int address;
	
	map<string, array> arrays;
	vector<int> indices;
	int index;
	deque<int> Cs;
	int Cd, C0;
	
	string name;
	int lowBound, upperBound;
	pair<int, int> bounds;
	int nextBoundsIndex;
	int N, R;
	
	cin >> N >> R;
	
	for(int i = 0; i < N; i++)
	{
		array arr;
		
		getline(cin, name, ' ');
		cin >> arr.base >> arr.elementSize >> arr.numDimensions;
		
		for(int j = 0; j < arr.numDimensions; j++)
		{
			cin >> lowBound >> upperBound;
			bounds.first = lowBound;
			bounds.second = upperBound;
			
			arr.bounds.push_back(bounds);
		}
		
		arrays[name] = arr;
	}
	
	for(int i = 0; i < R; i++)
	{
		address = 0;
		indices.clear();
		Cs.clear();
		
		getline(cin, name, ' ');
		
		for(int j = 0; j < arrays[name].numDimensions; j++)
		{
			cin >> index;
			indices.push_back(index);
		}
		
		Cs.push_back(arrays[name].elementSize);
		
		for(int j = 0; j < arrays[name].numDimensions - 1; j++)
		{
			nextBoundsIndex = arrays[name].bounds.size() - 1 - j;
			Cd = Cs[0] * (arrays[name].bounds[nextBoundsIndex].second -
						  arrays[name].bounds[nextBoundsIndex].first +
						  1);
						  
			Cs.push_front(Cd);
		}
		
		C0 = arrays[name].base;
		for(int j = 0; j < Cs.size(); j++)
		{
			C0 -= (Cs[j] * arrays[name].bounds[j].first);
		}
		
		address += C0;
		for(int j = 0; j < Cs.size(); j++)
		{
			address += (Cs[j] * indices[j]);
		}
		
		cout << name << "[" << indices[0];
		for(int j = 1; j < indices.size(); j++)
		{
			cout << ", " << indices[j];
		}
		cout << "] = " << address;
	}
	cout << endl;

	return 0;
}
