#include <iostream>

using namespace std;

bool snailMakesIt(int height, int climb, int slide, int fatigue,
				  int &day);

int main()
{
	int height, climb, slide, fatigue;
	int day = 0;
	
	cin >> height;
	
	while(height != 0)
	{
		cin >> climb >> slide >> fatigue;
		day = 1;
		
		cout << endl;
		
		if(snailMakesIt(height, climb, slide, fatigue, day))
		{
			cout << "success";
		}
		else
		{
			cout << "failure";
		}
		
		cout << " on day " << day;
		
		cin >> height;
	}

	return 0;
}

bool snailMakesIt(int height, int climb, int slide, int fatigue,
				  int &day)
{
	double snailHeight = 0.0;
	double fatiguedClimb = climb;
	day = 1;
	
	while(snailHeight >= 0)
	{
		snailHeight += fatiguedClimb;
		
		if(snailHeight > height)
		{
			return true;
		}
		
		snailHeight -= slide;
		
		if(fatiguedClimb > 0)
		{
			fatiguedClimb -= climb * (fatigue / 100.0);
			
			if(fatiguedClimb < 0)
			{
				fatiguedClimb = 0.0;
			}
		}
		
		day++;
	}
	
	day--;
	return false;
}
