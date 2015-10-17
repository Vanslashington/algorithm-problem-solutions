#include <iostream>

using namespace std;

int main()
{
	bool openQuote = true;
	string text;
	
	getline(cin, text, '\n');
	for(int i = 0; i < text.length(); i++)
	{
		if(text[i] != '\"')
		{
			cout << text[i];
		}
		else
		{
			if(openQuote)
			{
				cout << "``";
			}
			else
			{
				cout << "''";
			}
			
			openQuote = !openQuote;
		}
	}
	
	return 0;
}
