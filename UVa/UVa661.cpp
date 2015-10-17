#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int main()
{
	int totalConsumption, highestTotal;
	int sequenceNum = 0;
	
	int numDevices, numOperations, capacity;
	
	int consumption, operation;
	deque<pair<int, bool> > consumptions;
	deque<int> operations;
	
	pair<int, bool> currentDevice;
	
	cin >> numDevices;
	
	while(numDevices != 0)
	{
		totalConsumption = 0;
		highestTotal = 0;
		sequenceNum++;
		cin >> numOperations >> capacity;
		consumptions.clear();
		operations.clear();
		
		for(int i = 0; i < numDevices; i++)
		{
			cin >> consumption;
			currentDevice.first = consumption;
			currentDevice.second = false;
			
			consumptions.push_back(currentDevice);
		}
		
		for(int i = 0; i < numOperations && 
			totalConsumption <= capacity; i++)
		{
			cin >> operation;
			consumptions[operation - 1].second =
									!consumptions[operation - 1].second;
			if(consumptions[operation - 1].second)
			{
				totalConsumption += consumptions[operation - 1].first;
			}
			else
			{
				totalConsumption -= consumptions[operation - 1].first;
			}
			
			if(totalConsumption > highestTotal)
			{
				highestTotal = totalConsumption;
			}
		}
		
		cout << endl << "Sequence " << sequenceNum << endl
			 << "Fuse was ";
		
		if(totalConsumption > capacity)
		{
			cout << "blown." << endl;
		}
		else
		{
			cout << "not blown." << endl
				 << "Maximal power consumption was " << highestTotal
				 << " amperes." << endl;
		}
		
		cin >> numDevices;
	}

	return 0;
}
