#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
	//ifstream cin ("input.txt");
	
	bool isOpenQuote = true;
	char  b = 0;
	while(cin.get(b))
	{
			if(b == '"')
			{
				if(isOpenQuote)
					cout <<"``";
				else
					cout <<"''";
				isOpenQuote = !isOpenQuote;
			}
			else
				cout<<b;
		
		

	}
}