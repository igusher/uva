#include <iostream>
#include <fstream>
#include<memory.h>

using namespace std;

int main()
{
	ifstream cin("input.txt");
	const int coinsCount = 5;
	int change[7490];
	int coins[5] = {1,5,10,25,50};
	//int coins[5] = {1,2,4,10,20};
	int money;

	while(cin >> money)
	{
		//cin >> money;
	
		
		memset(change, 0, sizeof(int) * (money +1));
	
		change[0] = 1;
		change[1] = 0;
		for(int c = 0; c < coinsCount; c++)
		{
			for(int m = coins[c]; m <= money; m++)
			{
				change[m] += change[m-coins[c]];
			}
		}
		cout<<change[money] << endl;
	
	}
	return 0;
}
