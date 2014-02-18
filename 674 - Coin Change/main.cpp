#include <iostream>
#include <fstream>
#include<memory.h>

using namespace std;

int main()
{
//	ifstream cin("input.txt");
	const int coinsCount = 5;
	int coins[5] = {1,5,10,25,50};
	int money;

	//while(!cin.eof())
	//{
		cin >> money;
	
		int * change = new int[money+1];
		memset(change, 0, sizeof(int) * (money +1));
		int min = 10000;
		change[0] = 0;
		change[1] = 1;
		for(int c = 0; c < coinsCount; c++)
		{
			for(int m = coins[c]; m <= money; m++)
			{
				change[m] += change[m-coins[c]];
			}
		}
		cout<<change[money] << endl;
	
	//}
	return 0;
}
