#include <fstream>

using namespace std;

int main()
{
	string name;
	string code;
	int previous;
	int codeLength;
	
	ifstream fin;
	fin.clear();
	fin.open("739.txt");
	
	ofstream fout;
	fout.clear();
	fout.open("739o.txt");
	
	fout << "         NAME                     SOUNDEX CODE" << endl;
	
	fin >> name;
	
	while(fin.good())
	{
		code = "";
		code += name[0];
		codeLength = 0;
		previous = -1;
		
		switch(name[0])
		{
			case('B'):
			case('P'):
			case('F'):
			case('V'):
				previous = 1;
				break;
			case('C'):
			case('S'):
			case('K'):
			case('G'):
			case('J'):
			case('Q'):
			case('X'):
			case('Z'):
				previous = 2;
				break;
			case('D'):
			case('T'):
				previous = 3;
				break;
			case('L'):
				previous = 4;
				break;
			case('M'):
			case('N'):
				previous = 5;
				break;
			case('R'):
				previous = 6;
				break;
		}
		
		for(int i = 1; 
			codeLength < 3 && i < name.length(); 
			i++)
		{
			switch(name[i])
			{
				case('B'):
				case('P'):
				case('F'):
				case('V'):
					if(previous != 1)
					{
						code += '1';
						codeLength++;
					}
					previous = 1;
					break;
				case('C'):
				case('S'):
				case('K'):
				case('G'):
				case('J'):
				case('Q'):
				case('X'):
				case('Z'):
					if(previous != 2)
					{
						code += '2';
						codeLength++;
					}
					previous = 2;
					break;
				case('D'):
				case('T'):
					if(previous != 3)
					{
						code += '3';
						codeLength++;
					}
					previous = 3;
					break;
				case('L'):
					if(previous != 4)
					{
						code += '4';
						codeLength++;
					}
					previous = 4;
					break;
				case('M'):
				case('N'):
					if(previous != 5)
					{
						code += '5';
						codeLength++;
					}
					previous = 5;
					break;
				case('R'):
					if(previous != 6)
					{
						code += '6';
						codeLength++;
					}
					previous = 6;
					break;
				default:
					previous = -1;
					break;
			}
		}
		
		for(; codeLength < 3; codeLength++)
		{
			code += '0';
		}
		
		fout << "         " << name;
		for(int i = 0; i < 25 - name.length(); i++)
		{
			fout << " ";
		}
		fout << code << endl;
		
		fin >> name;
	}
	fout << "                   " << "END OF OUTPUT";
	
	return 0;
}
